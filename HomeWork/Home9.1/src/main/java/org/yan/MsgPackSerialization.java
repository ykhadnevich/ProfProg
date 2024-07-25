package org.yan;

import org.msgpack.MessagePack;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class MsgPackSerialization {
    public static void serialize(MyDataType data, String fileName) throws IOException {
        MessagePack msgpack = new MessagePack();
        byte[] bytes = msgpack.write(data);
        try (OutputStream outputStream = new FileOutputStream(fileName)) {
            outputStream.write(bytes);
        }
        System.out.println("Serialized data written to file: " + fileName);
    }
}
