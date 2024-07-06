package org.yan;

import org.msgpack.MessagePack;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

public class MsgPackDeserialization {
    public static MyDataType deserialize(String fileName) throws IOException {
        MessagePack msgpack = new MessagePack();
        MyDataType data;
        try (InputStream inputStream = new FileInputStream(fileName)) {
            data = msgpack.read(inputStream, MyDataType.class);
        }
        return data;
    }
}
