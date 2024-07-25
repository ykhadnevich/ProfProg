public class OrangeMessage {
    private String text1;
    private String text2;
    private int number;
    private double value;

    public OrangeMessage(String text1, String text2, int number, double value) {
        this.text1 = text1;
        this.text2 = text2;
        this.number = number;
        this.value = value;
    }

    public String getText1() {
        return text1;
    }

    public String getText2() {
        return text2;
    }

    public int getNumber() {
        return number;
    }

    public double getValue() {
        return value;
    }
}
