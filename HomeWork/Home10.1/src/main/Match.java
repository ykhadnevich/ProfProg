import java.util.Scanner;

public class Match {
    Team team1;
    Team team2;
    int goalsTeam1;
    int goalsTeam2;
    int yellowTeam1;
    int yellowTeam2;
    int redTeam1;
    int redTeam2;
    double topHeightTeam1;
    double topHeightTeam2;

    public Match(Team t1, Team t2) {
        this.team1 = t1;
        this.team2 = t2;
    }

    public void inputMatchData() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter goals scored by " + team1.name + ": ");
        goalsTeam1 = scanner.nextInt();
        System.out.println("Enter goals scored by " + team2.name + ": ");
        goalsTeam2 = scanner.nextInt();
        System.out.println("Enter yellow cards shown to " + team1.name + ": ");
        yellowTeam1 = scanner.nextInt();
        System.out.println("Enter yellow cards shown to " + team2.name + ": ");
        yellowTeam2 = scanner.nextInt();
        System.out.println("Enter red cards shown to " + team1.name + ": ");
        redTeam1 = scanner.nextInt();
        System.out.println("Enter red cards shown to " + team2.name + ": ");
        redTeam2 = scanner.nextInt();
        System.out.println("Enter top height reached by the ball for " + team1.name + ": ");
        topHeightTeam1 = scanner.nextDouble();
        System.out.println("Enter top height reached by the ball for " + team2.name + ": ");
        topHeightTeam2 = scanner.nextDouble();
    }

    public void updateTeams() {
        team1.updateStats(goalsTeam1, goalsTeam2, yellowTeam1, redTeam1, topHeightTeam1);
        team2.updateStats(goalsTeam2, goalsTeam1, yellowTeam2, redTeam2, topHeightTeam2);

        if (goalsTeam1 > goalsTeam2) {
            team1.points += 3.14;
            team2.points -= 0.5;
        } else if (goalsTeam1 < goalsTeam2) {
            team1.points -= 0.5;
            team2.points += 3.14;
        } else {
            team1.points += 2.71828;
            team2.points += 2.71828;
        }
    }
}
