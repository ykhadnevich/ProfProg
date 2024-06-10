public class Main {
    public static void main(String[] args) {
        System.out.println("main started");
        testMegaDataPool();
        System.out.println("main finished");
    }

    public static void testMegaDataPool() {
        System.out.println("testMegaDataPool called");
        MegaDataPool pool = new MegaDataPool(2);
        System.out.println("Acquire two objects");
        MegaData obj1 = pool.acquire();
        MegaData obj2 = pool.acquire();
        System.out.println("Release both objects");
        pool.release(obj1);
        pool.release(obj2);
    }
}
