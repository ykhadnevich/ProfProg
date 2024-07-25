package org.yan;

import java.io.IOException;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        MyDataType data1 = new MyDataType();
        data1.setIntValue(10);
        data1.setStringValue("Hello");

        Vector<Pair<String, MyDataType>> vector = new Vector<>();
        vector.add(new Pair<>("key1", data1));

        MyDataType data2 = new MyDataType();
        data2.setIntValue(20);
        data2.setStringValue("World");
        vector.add(new Pair<>("key2", data2));

        data1.setVectorValue(vector);

        String fileName = "data.msgpack";

        try {
            MsgPackSerialization.serialize(data1, fileName);
            MyDataType deserializedData = MsgPackDeserialization.deserialize(fileName);
            System.out.println("Deserialized Data: " + deserializedData);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

