import java.util.ArrayList;
import java.util.List;

public class Pizza {
    private List<Ingredient> ingredients = new ArrayList<>();

    public void addIngredient(String name, double cost) {
        ingredients.add(new Ingredient(name, cost));
    }

    public double getTotalCost() {
        return ingredients.stream().mapToDouble(Ingredient::getCost).sum();
    }

    public List<Ingredient> getIngredients() {
        return ingredients;
    }

    public static class Ingredient {
        private final String name;
        private final double cost;

        public Ingredient(String name, double cost) {
            this.name = name;
            this.cost = cost;
        }

        public String getName() {
            return name;
        }

        public double getCost() {
            return cost;
        }
    }
}
