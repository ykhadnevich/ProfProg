import java.util.ArrayList;
import java.util.List;

public class MegaDataPool {
    private int poolSize;
    private List<MegaData> pool;
    private boolean[] available;

    public MegaDataPool(int poolSize) {
        this.poolSize = poolSize;
        pool = new ArrayList<>(poolSize);
        available = new boolean[poolSize];
        for (int i = 0; i < poolSize; i++) {
            pool.add(new MegaData());
            available[i] = true;
        }
        System.out.println("MegaDataPool constructor called with pool size: " + poolSize);
    }

    public MegaData acquire() {
        for (int i = 0; i < poolSize; i++) {
            if (available[i]) {
                available[i] = false;
                System.out.println("Acquired object at index: " + i);
                return pool.get(i);
            }
        }
        throw new RuntimeException("No available MegaData objects in the pool");
    }

    public void release(MegaData data) {
        for (int i = 0; i < poolSize; i++) {
            if (pool.get(i) == data) {
                if (!available[i]) {
                    available[i] = true;
                    data.reset();
                    System.out.println("Released object at index: " + i);
                    return;
                } else {
                    System.out.println("Error: This MegaData object is already released");
                    throw new RuntimeException("This MegaData object is already released");
                }
            }
        }
        System.out.println("Error: This MegaData object does not belong to the pool");
        throw new RuntimeException("This MegaData object does not belong to the pool");
    }

    public int size() {
        return poolSize;
    }

    public int usedSize() {
        int count = 0;
        for (boolean available : available) {
            if (!available) {
                count++;
            }
        }
        return count;
    }
}
