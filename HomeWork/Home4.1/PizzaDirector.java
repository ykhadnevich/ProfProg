import java.util.Scanner;

public class PizzaDirector {
    public void constructPizza(PizzaBuilder builder) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter ingredients (type 'done' to finish):");

        while (true) {
            String input = scanner.nextLine();
            if (input.equals("done")) {
                break;
            }
            try {
                builder.addIngredient(input);
                System.out.println(input + " added.");
            } catch (IllegalArgumentException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
