#ifndef MYDATATYPE_H
#define MYDATATYPE_H

#include <string>
#include <vector>
#include <msgpack.h>

class MyDataType {
public:
    enum class Type {
        Integer,
        String,
        Map
    };

    MyDataType(int16_t intValue);
    MyDataType(const std::string& strValue);
    MyDataType(const std::vector<std::pair<std::string, MyDataType>>& mapValue);

    void serialize(msgpack_packer* pk) const;

private:
    Type type;
    int16_t intValue;
    std::string strValue;
    std::vector<std::pair<std::string, MyDataType>> mapValue;
};

std::vector<uint8_t> serializeToMsgPack(const MyDataType& data);

#endif // MYDATATYPE_H
