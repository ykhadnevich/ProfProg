import java.util.List;

public class MathUtils {

    public static double dummyFunc(double x) {
        return x > 0 ? x : 0;
    }

    public static String repeatString(List<Integer> vec, String str) {
        if (vec.isEmpty()) return "";
        int max_elem = vec.stream().max(Integer::compare).orElse(0);
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < max_elem; ++i) {
            result.append(str);
        }
        return result.toString();
    }
}
