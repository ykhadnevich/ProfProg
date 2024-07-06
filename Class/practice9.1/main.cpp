#include <iostream>
#include <fstream>
#include <vector>
#include "MyDataType.h"

int main() {
    // Example usage
    MyDataType data1(123);
    MyDataType data2("Hello, MsgPack!");
    MyDataType data3({
        {"key1", MyDataType(456)},
        {"key2", MyDataType("Nested string")},
        {"key3", MyDataType(std::vector<std::pair<std::string, MyDataType>>{
            {"inner_key1", MyDataType(789)},
            {"inner_key2", MyDataType("Another nested string")}
        })}
    });

    // Serialize and write to files
    auto serializedData1 = serializeToMsgPack(data1);
    auto serializedData2 = serializeToMsgPack(data2);
    auto serializedData3 = serializeToMsgPack(data3);

    // Write to files
    std::ofstream file1("data1.msgpack", std::ios::binary);
    file1.write(reinterpret_cast<const char*>(serializedData1.data()), serializedData1.size());
    file1.close();

    std::ofstream file2("data2.msgpack", std::ios::binary);
    file2.write(reinterpret_cast<const char*>(serializedData2.data()), serializedData2.size());
    file2.close();

    std::ofstream file3("data3.msgpack", std::ios::binary);
    file3.write(reinterpret_cast<const char*>(serializedData3.data()), serializedData3.size());
    file3.close();

    std::cout << "Serialized data written to files: data1.msgpack, data2.msgpack, data3.msgpack" << std::endl;

    return 0;
}
