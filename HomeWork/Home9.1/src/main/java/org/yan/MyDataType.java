package org.yan;

import java.util.Vector;

public class MyDataType {
    private int intValue;
    private String stringValue;
    private Vector<Pair<String, MyDataType>> vectorValue;

    public int getIntValue() {
        return intValue;
    }

    public void setIntValue(int intValue) {
        this.intValue = intValue;
    }

    public String getStringValue() {
        return stringValue;
    }

    public void setStringValue(String stringValue) {
        this.stringValue = stringValue;
    }

    public Vector<Pair<String, MyDataType>> getVectorValue() {
        return vectorValue;
    }

    public void setVectorValue(Vector<Pair<String, MyDataType>> vectorValue) {
        this.vectorValue = vectorValue;
    }
}
