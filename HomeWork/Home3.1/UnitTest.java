import java.util.ArrayList;
import java.util.List;
import java.util.function.Supplier;

public class UnitTest {

    private static class Test {
        String name;
        Runnable func;

        Test(String name, Runnable func) {
            this.name = name;
            this.func = func;
        }
    }

    private List<Test> tests;

    public UnitTest() {
        tests = new ArrayList<>();
    }

    public void addTest(String name, Runnable func) {
        tests.add(new Test(name, func));
    }

    public void run() {
        int totalCount = tests.size();
        int successCount = 0;

        for (Test test : tests) {
            System.out.println("Executing test " + test.name + "...");
            try {
                test.func.run();
                System.out.println(test.name + " PASSED.");
                successCount++;
            } catch (AssertionError e) {
                System.out.println(test.name + " FAILED.");
            }
        }

        System.out.println(successCount + " of " + totalCount + (totalCount == 1 ? " test" : " tests") + " have passed.");
    }

    public static void assertEquals(Object expected, Object actual) {
        if (!expected.equals(actual)) {
            throw new AssertionError("Expected: " + expected + ", Actual: " + actual);
        }
    }
}
