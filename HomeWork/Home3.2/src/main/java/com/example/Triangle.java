package com.example;

public class Triangle {
    private double sideA;
    private double sideB;
    private double sideC;

    public Triangle(double sideA, double sideB, double sideC) {
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
    }

    public double getHeight(char side) {
        switch (side) {
            case 'a':
                return (2 * area()) / sideA;
            case 'b':
                return (2 * area()) / sideB;
            case 'c':
                return (2 * area()) / sideC;
            default:
                throw new IllegalArgumentException("Invalid side: " + side);
        }
    }

    private double area() {
        double s = (sideA + sideB + sideC) / 2;
        return Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }
}
