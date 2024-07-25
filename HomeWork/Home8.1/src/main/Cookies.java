public class Cookies implements PriceInfo {
    @Override
    public double getCoefficient() {
        return 1.5;
    }

    @Override
    public double getBasePrice() {
        return 1.0;
    }
}
