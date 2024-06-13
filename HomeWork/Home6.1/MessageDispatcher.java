import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.UUID;

public class MessageDispatcher {
    private Map<String, List<Subscriber<?>>> subscribers;

    public MessageDispatcher() {
        this.subscribers = new HashMap<>();
    }

    public UUID subscribeToGreen(Subscriber<GreenMessage> subscriber) {
        return subscribe(GreenMessage.class.getSimpleName(), subscriber);
    }

    public UUID subscribeToBlue(Subscriber<BlueMessage> subscriber) {
        return subscribe(BlueMessage.class.getSimpleName(), subscriber);
    }

    public UUID subscribeToOrange(Subscriber<OrangeMessage> subscriber) {
        return subscribe(OrangeMessage.class.getSimpleName(), subscriber);
    }

    private UUID subscribe(String messageType, Subscriber<?> subscriber) {
        UUID subscriptionId = UUID.randomUUID();
        subscribers.computeIfAbsent(messageType, k -> new ArrayList<>()).add(subscriber);
        return subscriptionId;
    }

    public void unsubscribe(UUID subscriptionId) {
        subscribers.values().forEach(subscriberList -> {
            subscriberList.removeIf(subscriber -> subscriber.getId().equals(subscriptionId));
        });
    }

    public void publish(GreenMessage message) {
        notifySubscribers(GreenMessage.class.getSimpleName(), message);
    }

    public void publish(BlueMessage message) {
        notifySubscribers(BlueMessage.class.getSimpleName(), message);
    }

    public void publish(OrangeMessage message) {
        notifySubscribers(OrangeMessage.class.getSimpleName(), message);
    }

    private <T> void notifySubscribers(String messageType, T message) {
        List<Subscriber<?>> subscriberList = subscribers.get(messageType);
        if (subscriberList != null) {
            for (Subscriber<?> subscriber : subscriberList) {
                @SuppressWarnings("unchecked")
                Subscriber<T> castedSubscriber = (Subscriber<T>) subscriber;
                castedSubscriber.receive(message);
            }
        }
    }
}
