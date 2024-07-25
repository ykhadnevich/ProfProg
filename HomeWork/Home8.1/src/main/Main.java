public class Main {
    public static void main(String[] args) {
        Integer priority = 3; // Example priority value
        PricePresenter<Integer> presenter = new PricePresenter<>(priority);

        Milk milk = new Milk();
        Cookies cookies = new Cookies();
        Pineapple pineapple = new Pineapple();

        presenter.printTotalPrice(milk, cookies);
        presenter.printTotalPrice(cookies, pineapple);
    }
}
