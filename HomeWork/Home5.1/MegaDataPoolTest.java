import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class MegaDataPoolTest {
    private MegaDataPool pool;

    @Before
    public void setUp() {
        pool = new MegaDataPool(2);
    }

    @Test
    public void testAcquireAndRelease() {
        MegaData obj1 = pool.acquire();
        MegaData obj2 = pool.acquire();

        assertNotNull(obj1);
        assertNotNull(obj2);

        assertEquals(2, pool.size());
        assertEquals(0, pool.usedSize());

        pool.release(obj1);
        assertEquals(1, pool.usedSize());

        pool.release(obj2);
        assertEquals(0, pool.usedSize());
    }

    @Test(expected = RuntimeException.class)
    public void testAcquireThrowsExceptionWhenPoolIsEmpty() {
        pool.acquire();
        pool.acquire();
        pool.acquire(); // Pool is exhausted, should throw exception
    }

    @Test(expected = RuntimeException.class)
    public void testReleaseThrowsExceptionWhenObjectNotInPool() {
        MegaData obj = new MegaData();
        pool.release(obj); // Object not in pool, should throw exception
    }
}
