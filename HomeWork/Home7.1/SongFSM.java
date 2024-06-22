import java.util.HashMap;
import java.util.Map;

public class SongFSM {
    private SongState currentState;

    private final Map<SongState, Map<String, SongState>> transitions = new HashMap<>();

    public SongFSM() {
        currentState = SongState.INTRO;

        transitions.put(SongState.INTRO, Map.of(
            "dangerous", SongState.LET_IT_BE,
            "fun", SongState.STARMAN,
            "sad", SongState.BUT_IN_THE_END
        ));

        transitions.put(SongState.STARMAN, Map.of(
            "silly", SongState.INTRO,
            "dangerous", SongState.SHOW_MUST_GO_ON,
            "fun", SongState.BUT_IN_THE_END
        ));

        transitions.put(SongState.SHOW_MUST_GO_ON, Map.of(
            "sad", SongState.LET_IT_BE,
            "fun", SongState.STARMAN
        ));

        transitions.put(SongState.LET_IT_BE, Map.of(
            "dangerous", SongState.INTRO,
            "silly", SongState.SHOW_MUST_GO_ON
        ));
    }

    public String getCurrentSong() {
        return currentState.getSong();
    }

    public boolean processCommand(String command) {
        if (currentState == SongState.BUT_IN_THE_END) {
            return false;
        }

        Map<String, SongState> stateTransitions = transitions.get(currentState);
        SongState nextState = stateTransitions != null ? stateTransitions.getOrDefault(command, currentState) : currentState;

        currentState = nextState;

        return currentState != SongState.BUT_IN_THE_END;
    }
}
