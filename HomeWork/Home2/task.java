import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class task {
    private static final String DATABASE_FILE = "user_stats.txt";
    private static final String SECRET_WORD = "bread";

    public static void main(String[] args) {
        if (args.length < 1 || args.length > 2) {
            System.err.println("Usage: java task <name> [delete]");
            System.exit(1);
        }

        String name = args[0];
        boolean deleteFlag = (args.length == 2 && "delete".equals(args[1]));

        Map<String, Integer> userStats = new HashMap<>();
        loadDatabase(userStats);

        if (SECRET_WORD.equals(name)) {
            exterminateAll(userStats);
        } else if (deleteFlag) {
            resetUser(name, userStats);
        } else {
            if (!userStats.containsKey(name)) {
                userStats.put(name, 0);
                System.out.println("Welcome, " + name + "!");
            } else {
                userStats.put(name, userStats.get(name) + 1);
                System.out.println("Hello again(x" + userStats.get(name) + "), " + name + "!");
            }
            saveDatabase(userStats);
        }
    }

    private static void loadDatabase(Map<String, Integer> userStats) {
        try (Scanner scanner = new Scanner(new File(DATABASE_FILE))) {
            while (scanner.hasNext()) {
                String name = scanner.next();
                int count = scanner.nextInt();
                userStats.put(name, count);
            }
        } catch (FileNotFoundException e) {
        }
    }

    private static void saveDatabase(Map<String, Integer> userStats) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(DATABASE_FILE))) {
            for (Map.Entry<String, Integer> entry : userStats.entrySet()) {
                writer.println(entry.getKey() + " " + entry.getValue());
            }
        } catch (IOException e) {
            System.err.println("Error saving database: " + e.getMessage());
        }
    }

    private static void resetUser(String name, Map<String, Integer> userStats) {
        userStats.remove(name);
        System.out.println("Statistics for " + name + " have been reset.");
        saveDatabase(userStats);
    }

    private static void exterminateAll(Map<String, Integer> userStats) {
        userStats.clear();
        System.out.println("All history exterminated.");
        saveDatabase(userStats);
    }
}
