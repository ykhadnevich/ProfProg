public enum SongState {
    INTRO("Intro"),
    STARMAN("Starman"),
    SHOW_MUST_GO_ON("Show must go on"),
    LET_IT_BE("Let it be"),
    BUT_IN_THE_END("But in the end, it doesn't even matter");

    private final String song;

    SongState(String song) {
        this.song = song;
    }

    public String getSong() {
        return song;
    }
}
