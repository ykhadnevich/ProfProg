public class Team {
    String name;
    int goalsScored = 0;
    int goalsConceded = 0;
    int yellowCards = 0;
    int redCards = 0;
    double topHeight = 0.0;
    double points = 0.0;

    public Team(String name) {
        this.name = name;
    }

    public void updateStats(int scored, int conceded, int yellow, int red, double height) {
        goalsScored += scored;
        goalsConceded += conceded;
        yellowCards += yellow;
        redCards += red;
        topHeight += height;
    }
}
