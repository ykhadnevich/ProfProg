import org.junit.Test;

import static org.junit.Assert.*;

public class MegaDataTest {

    @Test
    public void testDefaultValues() {
        MegaData megaData = new MegaData();
        float[] smallArray = megaData.getSmallArray();
        double[] bigArray = megaData.getBigArray();

        for (float value : smallArray) {
            assertEquals(42.0f, value, 0.0f);
        }

        for (double value : bigArray) {
            assertEquals(42.0, value, 0.0);
        }
    }

    @Test
    public void testReset() {
        MegaData megaData = new MegaData();
        megaData.getSmallArray()[0] = 10.0f;
        megaData.getBigArray()[0] = 20.0;
        megaData.reset();

        assertEquals(42.0f, megaData.getSmallArray()[0], 0.0f);
        assertEquals(42.0, megaData.getBigArray()[0], 0.0);
    }
}
