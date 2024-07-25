import java.util.UUID;

public class Main {
    public static void main(String[] args) {
        MessageDispatcher dispatcher = new MessageDispatcher();

        UUID greenSubscriptionId = dispatcher.subscribeToGreen(message -> {
            System.out.println("Received GreenMessage: " + message.getText() + ", " + message.getCounter());
        });

        UUID blueSubscriptionId = dispatcher.subscribeToBlue(message -> {
            System.out.println("Received BlueMessage: " + message.getValue1() + ", " + message.getValue2());
        });

        UUID orangeSubscriptionId = dispatcher.subscribeToOrange(message -> {
            System.out.println("Received OrangeMessage: " + message.getText1() + ", " + message.getText2() +
                               ", " + message.getNumber() + ", " + message.getValue());
        });

        dispatcher.publish(new GreenMessage("GreenMessage", 1));
        dispatcher.publish(new BlueMessage(0.5, 0.8));
        dispatcher.publish(new OrangeMessage("OrangeMessage1", "OrangeMessage2", 42, 0.123));

        dispatcher.unsubscribe(greenSubscriptionId);

        dispatcher.publish(new GreenMessage("GreenMessage after unsubscribe", 2));

        System.out.println("Main method execution completed.");
    }
}
