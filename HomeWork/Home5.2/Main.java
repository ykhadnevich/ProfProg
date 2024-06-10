// Main.java

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Ask user for 5 favorite words
        Scanner scanner = new Scanner(System.in);
        String[] favoriteWords = new String[5];
        System.out.println("Enter your 5 favorite words:");
        for (int i = 0; i < 5; i++) {
            favoriteWords[i] = scanner.nextLine();
        }

        // Start 5 threads for each word
        for (String word : favoriteWords) {
            for (int i = 0; i < 5; i++) {
                Thread thread = new WordThread(word);
                thread.start();
            }
        }
    }
}
