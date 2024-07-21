import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter your name: ");
        String name = scanner.nextLine();

        BookRecommender recommender = new BookRecommender();
        recommender.recommendBook(name);

        scanner.close();
    }
}
