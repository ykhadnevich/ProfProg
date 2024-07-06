public class PricePresenter<PRIORITY extends Number> {
    private PRIORITY priority; // Field to store PRIORITY

    public PricePresenter(PRIORITY priority) {
        this.priority = priority;
    }

    public <T extends PriceInfo, U extends PriceInfo> void printTotalPrice(T obj1, U obj2) {
        double priorityValue = priority.intValue(); // Get the integer value of PRIORITY
        double totalPrice = priorityValue * obj1.getCoefficient() * obj1.getBasePrice() +
                            priorityValue * obj2.getCoefficient() * obj2.getBasePrice();
        System.out.println("Total Price: " + totalPrice);
    }
}
