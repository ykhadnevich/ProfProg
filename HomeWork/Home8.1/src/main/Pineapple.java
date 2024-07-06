public class Pineapple implements PriceInfo {
    @Override
    public double getCoefficient() {
        return 1.8;
    }

    @Override
    public double getBasePrice() {
        return 3.75;
    }
}
