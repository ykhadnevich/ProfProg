import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        SongFSM fsm = new SongFSM();
        boolean running = true;

        System.out.println("Starting song: " + fsm.getCurrentSong());

        while (running) {
            System.out.println("Enter command (sad, fun, silly, dangerous): ");
            String command = scanner.nextLine().trim();

            running = fsm.processCommand(command);

            if (running) {
                System.out.println("Current song: " + fsm.getCurrentSong());
            } else {
                System.out.println("Terminating song: " + fsm.getCurrentSong());
            }
        }

        scanner.close();
    }
}
