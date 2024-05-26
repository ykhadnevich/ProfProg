import java.util.List;

public class MathUtilsTest {

    public static void main(String[] args) {
        UnitTest testSuite = new UnitTest();

        testSuite.addTest("Dummy_test1", () -> {
            // Build:
            double value = 0.0;

            // Operate:
            double result = MathUtils.dummyFunc(value);

            // Check:
            UnitTest.assertEquals(0.0, result);
        });

        testSuite.addTest("Dummy_test2", () -> {
            // Build:
            double value = -1.0;

            // Operate:
            double result = MathUtils.dummyFunc(value);

            // Check:
            UnitTest.assertEquals(0.0, result); // Test negative input
        });

        testSuite.addTest("Dummy_test3", () -> {
            // Build:
            double value = 3.5;

            // Operate:
            double result = MathUtils.dummyFunc(value);

            // Check:
            UnitTest.assertEquals(3.5, result); // Test positive input
        });

        testSuite.addTest("RepeatString_test1", () -> {
            // Build:
            List<Integer> vec = List.of(0, 2, 1);
            String str = "home";

            // Operate:
            String result = MathUtils.repeatString(vec, str);

            // Check:
            UnitTest.assertEquals("homehome", result);
        });

        testSuite.run();
    }
}
