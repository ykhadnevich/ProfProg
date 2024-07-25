// Configuration.java

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Configuration {
    private static Configuration instance;
    private String[][] settings;

    private Configuration() {
        loadSettings();
    }

    public static synchronized Configuration getInstance() {
        if (instance == null) {
            instance = new Configuration();
        }
        return instance;
    }

    private void loadSettings() {
        // Load configuration from file
        // Assume the configuration file is named "config.txt" and has the specified format
        try (BufferedReader reader = new BufferedReader(new FileReader("config.txt"))) {
            settings = new String[3][2];
            for (int i = 0; i < 3; i++) {
                String line = reader.readLine();
                String[] parts = line.split(" ");
                settings[i] = parts;
            }
        } catch (IOException e) {
            System.err.println("Error loading configuration: " + e.getMessage());
        }
    }

    public String[] getWordSettings(char firstLetter) {
        int index;
        if (firstLetter >= 'a' && firstLetter <= 'k') {
            index = 0;
        } else if (firstLetter >= 'l' && firstLetter <= 'o') {
            index = 1;
        } else {
            index = 2;
        }
        return settings[index];
    }
}
