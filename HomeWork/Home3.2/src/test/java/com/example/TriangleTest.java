package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class TriangleTest {

    @Test
    public void testGetHeightForSideA() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertEquals(4.0, triangle.getHeight('a'));
    }
}
