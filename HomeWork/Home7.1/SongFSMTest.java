import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class SongFSMTest {

    @Test
    public void testInitialState() {
        SongFSM fsm = new SongFSM();
        assertEquals("Intro", fsm.getCurrentSong());
    }

    @Test
    public void testIntroToLetItBe() {
        SongFSM fsm = new SongFSM();
        assertTrue(fsm.processCommand("dangerous"));
        assertEquals("Let it be", fsm.getCurrentSong());
    }

    @Test
    public void testIntroToStarman() {
        SongFSM fsm = new SongFSM();
        assertTrue(fsm.processCommand("fun"));
        assertEquals("Starman", fsm.getCurrentSong());
    }

    

    @Test
    public void testStarmanToIntro() {
        SongFSM fsm = new SongFSM();
        fsm.processCommand("fun");  // move to Starman
        assertTrue(fsm.processCommand("silly"));
        assertEquals("Intro", fsm.getCurrentSong());
    }

    @Test
    public void testStarmanToShowMustGoOn() {
        SongFSM fsm = new SongFSM();
        fsm.processCommand("fun");  // move to Starman
        assertTrue(fsm.processCommand("dangerous"));
        assertEquals("Show must go on", fsm.getCurrentSong());
    }
    @Test
    public void testShowMustGoOnToLetItBe() {
        SongFSM fsm = new SongFSM();
        fsm.processCommand("fun");  // move to Starman
        fsm.processCommand("dangerous");  // move to Show must go on
        assertTrue(fsm.processCommand("sad"));
        assertEquals("Let it be", fsm.getCurrentSong());
    }

    @Test
    public void testShowMustGoOnToStarman() {
        SongFSM fsm = new SongFSM();
        fsm.processCommand("fun");  // move to Starman
        fsm.processCommand("dangerous");  // move to Show must go on
        assertTrue(fsm.processCommand("fun"));
        assertEquals("Starman", fsm.getCurrentSong());
    }

    @Test
    public void testLetItBeToIntro() {
        SongFSM fsm = new SongFSM();
        fsm.processCommand("dangerous");  // move to Let it be
        assertTrue(fsm.processCommand("dangerous"));
        assertEquals("Intro", fsm.getCurrentSong());
    }

    @Test
    public void testLetItBeToShowMustGoOn() {
        SongFSM fsm = new SongFSM();
        fsm.processCommand("dangerous");  // move to Let it be
        assertTrue(fsm.processCommand("silly"));
        assertEquals("Show must go on", fsm.getCurrentSong());
    }

    

    @Test
    public void testInvalidCommandReplaysCurrentSong() {
        SongFSM fsm = new SongFSM();
        assertTrue(fsm.processCommand("invalid"));
        assertEquals("Intro", fsm.getCurrentSong());

        fsm.processCommand("fun");  // move to Starman
        assertTrue(fsm.processCommand("invalid"));
        assertEquals("Starman", fsm.getCurrentSong());
    }
}
