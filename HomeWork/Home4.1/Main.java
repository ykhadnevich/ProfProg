import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        PizzaBuilder builder = new PizzaBuilder();
        PizzaDirector director = new PizzaDirector();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose an option:");
        System.out.println("1. Classical pizza");
        System.out.println("2. Custom pizza");
        int choice = scanner.nextInt();
        scanner.nextLine();  // Consume newline

        if (choice == 1) {
            System.out.println("Select a classical pizza:");
            System.out.println("1. Margherita (Cheese, Tomato)");
            System.out.println("2. Pepperoni (Cheese, Tomato, Pepperoni)");
            System.out.println("3. Hawaiian (Cheese, Tomato, Ham, Pineapple)");
            int classicalChoice = scanner.nextInt();
            scanner.nextLine();  // Consume newline

            switch (classicalChoice) {
                case 1:
                    builder.addIngredient("Cheese");
                    builder.addIngredient("Tomato");
                    break;
                case 2:
                    builder.addIngredient("Cheese");
                    builder.addIngredient("Tomato");
                    builder.addIngredient("Pepperoni");
                    break;
                case 3:
                    builder.addIngredient("Cheese");
                    builder.addIngredient("Tomato");
                    builder.addIngredient("Ham");
                    builder.addIngredient("Pineapple");
                    break;
                default:
                    System.out.println("Invalid choice.");
                    return;
            }
        } else if (choice == 2) {
            director.constructPizza(builder);
        } else {
            System.out.println("Invalid choice.");
            return;
        }

        Pizza pizza = builder.getPizza();
        System.out.println("Your pizza ingredients and cost:");
        for (Pizza.Ingredient ingredient : pizza.getIngredients()) {
            System.out.println(ingredient.getName() + ": $" + ingredient.getCost());
        }
        System.out.println("Total cost: $" + pizza.getTotalCost());
    }
}
