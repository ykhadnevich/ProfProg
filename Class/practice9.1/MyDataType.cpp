#include "MyDataType.h"

MyDataType::MyDataType(int16_t intValue) : type(Type::Integer), intValue(intValue) {}

MyDataType::MyDataType(const std::string& strValue) : type(Type::String), strValue(strValue) {}

MyDataType::MyDataType(const std::vector<std::pair<std::string, MyDataType>>& mapValue)
    : type(Type::Map), mapValue(mapValue) {}

void MyDataType::serialize(msgpack_packer* pk) const {
    switch (type) {
        case Type::Integer:
            msgpack_pack_int16(pk, intValue);
            break;
        case Type::String:
            msgpack_pack_str(pk, strValue.length());
            msgpack_pack_str_body(pk, strValue.c_str(), strValue.length());
            break;
        case Type::Map: {
            msgpack_pack_map(pk, static_cast<uint32_t>(mapValue.size()));
            for (const auto& pair : mapValue) {
                msgpack_pack_str(pk, pair.first.length());
                msgpack_pack_str_body(pk, pair.first.c_str(), pair.first.length());
                pair.second.serialize(pk);
            }
            break;
        }
    }
}

std::vector<uint8_t> serializeToMsgPack(const MyDataType& data) {
    msgpack_sbuffer sbuf;
    msgpack_sbuffer_init(&sbuf);

    msgpack_packer pk;
    msgpack_packer_init(&pk, &sbuf, msgpack_sbuffer_write);

    data.serialize(&pk);

    std::vector<uint8_t> msgpackData(sbuf.data, sbuf.data + sbuf.size);

    msgpack_sbuffer_destroy(&sbuf);

    return msgpackData;
}
