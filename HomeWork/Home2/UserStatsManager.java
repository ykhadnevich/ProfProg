import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class UserStatsManager {
    private static final String DATABASE_FILE = "user_stats.txt";
    private static final String SECRET_WORD = "bread";
    private Map<String, Integer> userStats;

    public UserStatsManager() {
        userStats = new HashMap<>();
        loadDatabase();
    }

    public void processUser(String name, boolean deleteFlag) {
        if (SECRET_WORD.equals(name)) {
            exterminateAll();
        } else if (deleteFlag) {
            resetUser(name);
        } else {
            if (!userStats.containsKey(name)) {
                userStats.put(name, 0);
                System.out.println("Welcome, " + name + "!");
            } else {
                userStats.put(name, userStats.get(name) + 1);
                System.out.println("Hello again(x" + userStats.get(name) + "), " + name + "!");
            }
            saveDatabase();
        }
    }

    private void loadDatabase() {
        try (BufferedReader reader = new BufferedReader(new FileReader(DATABASE_FILE))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                userStats.put(parts[0], Integer.parseInt(parts[1]));
            }
        } catch (IOException e) {
            System.err.println("Error loading database: " + e.getMessage());
        }
    }

    private void saveDatabase() {
        try (PrintWriter writer = new PrintWriter(new FileWriter(DATABASE_FILE))) {
            for (Map.Entry<String, Integer> entry : userStats.entrySet()) {
                writer.println(entry.getKey() + " " + entry.getValue());
            }
        } catch (IOException e) {
            System.err.println("Error saving database: " + e.getMessage());
        }
    }

    private void resetUser(String name) {
        userStats.remove(name);
        System.out.println("Statistics for " + name + " have been reset.");
        saveDatabase();
    }

    private void exterminateAll() {
        userStats.clear();
        System.out.println("All history exterminated.");
        saveDatabase();
    }

    public static void main(String[] args) {
        if (args.length < 1 || args.length > 2) {
            System.err.println("Usage: java UserStatsManager <name> [delete]");
            System.exit(1);
        }

        String name = args[0];
        boolean deleteFlag = (args.length == 2 && "delete".equals(args[1]));

        UserStatsManager statsManager = new UserStatsManager();
        statsManager.processUser(name, deleteFlag);
    }
}
