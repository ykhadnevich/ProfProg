import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class PizzaBuilder {
    private Pizza pizza;
    private Map<String, Double> availableIngredients;

    public PizzaBuilder() {
        pizza = new Pizza();
        availableIngredients = new HashMap<>();
        loadIngredients();
    }

    private void loadIngredients() {
        try (BufferedReader br = new BufferedReader(new FileReader("ingredients.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(" ");
                if (parts.length == 2) {
                    String ingredient = parts[0];
                    double cost = Double.parseDouble(parts[1]);
                    availableIngredients.put(ingredient, cost);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void addIngredient(String ingredient) {
        if (availableIngredients.containsKey(ingredient)) {
            pizza.addIngredient(ingredient, availableIngredients.get(ingredient));
        } else {
            throw new IllegalArgumentException("Ingredient not available");
        }
    }

    public Pizza getPizza() {
        return pizza;
    }
}
