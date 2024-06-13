import java.util.UUID;

@FunctionalInterface
public interface Subscriber<T> {
    void receive(T message);

    default UUID getId() {
        return UUID.randomUUID();
    }
}
