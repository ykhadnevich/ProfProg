import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class BookRecommender {
    private List<String> books;

    public BookRecommender() {
        books = new ArrayList<>();
        books.add("The Topographer’s Clown");
        books.add("The Chamber of Beaver");
        books.add("The Ironer of Kanban");
        books.add("The Piglet of Tire");
        books.add("The Border of the Unix");
        books.add("The Half-Time Convince");
        books.add("The Earthly Pillows");
        books.add("The Censorship of the Ping");
        books.add("The True Powers");
        books.add("The Overturn of the Ling");
    }

    private String getRandomBook() {
        if (books.isEmpty()) {
            return "";
        }
        Random rand = new Random();
        int index = rand.nextInt(books.size());
        return books.get(index);
    }

    public void recommendBook(String name) {
        Scanner scanner = new Scanner(System.in);
        while (!books.isEmpty()) {
            String book = getRandomBook();
            System.out.println("We recommend you to read: " + book);
            System.out.print("Do you like this book? (yes/no): ");
            String response = scanner.nextLine();

            if (response.equalsIgnoreCase("yes")) {
                System.out.println("Great! Enjoy your book.");
                return;
            } else if (response.equalsIgnoreCase("no")) {
                books.remove(book);
            } else {
                System.out.println("Invalid response. Please enter 'yes' or 'no'.");
            }
        }
        System.out.println("Au revoir, " + name + "!");
        scanner.close();
    }
}
