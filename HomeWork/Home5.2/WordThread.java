// WordThread.java

public class WordThread extends Thread {
    private String word;

    public WordThread(String word) {
        this.word = word;
    }

    @Override
    public void run() {
        try {
            char firstLetter = Character.toLowerCase(word.charAt(0));
            String[] settings = Configuration.getInstance().getWordSettings(firstLetter);
            String preWord = settings[0];
            String postWord = settings[1];
            System.out.println(preWord + " " + word + " " + postWord);
            Thread.sleep(1000); // Sleep for 1 second
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
