import java.util.Arrays;

public class MegaData {
    private static final int SMALL_ARRAY_SIZE = 1024;
    private static final int BIG_ARRAY_SIZE = 1024 * 1024;
    private static final float DEFAULT_VALUE = 42.0f;

    private float[] smallArray;
    private double[] bigArray;

    public MegaData() {
        smallArray = new float[SMALL_ARRAY_SIZE];
        bigArray = new double[BIG_ARRAY_SIZE];
        Arrays.fill(smallArray, DEFAULT_VALUE);
        Arrays.fill(bigArray, DEFAULT_VALUE);
        System.out.println("MegaData constructor called");
    }

    public void reset() {
        Arrays.fill(smallArray, DEFAULT_VALUE);
        Arrays.fill(bigArray, DEFAULT_VALUE);
        System.out.println("MegaData reset called");
    }
}
