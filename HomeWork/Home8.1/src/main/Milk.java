public class Milk implements PriceInfo {
    @Override
    public double getCoefficient() {
        return 1.2;
    }

    @Override
    public double getBasePrice() {
        return 2.5;
    }
}
