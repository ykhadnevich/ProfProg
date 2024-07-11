import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Team> teams = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        String name;

        for (int i = 1; i <= 4; ++i) {
            System.out.println("Enter name for Team " + i + ": ");
            name = scanner.nextLine();
            teams.add(new Team(name));
        }

        List<Match> matches = new ArrayList<>();
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                matches.add(new Match(teams.get(i), teams.get(j)));
            }
        }

        for (Match match : matches) {
            System.out.println("\nMatch between " + match.team1.name + " and " + match.team2.name + ":");
            match.inputMatchData();
            match.updateTeams();
        }

        teams.sort((a, b) -> compareTeams(a, b));
        printRanking(teams);
    }

    private static int compareTeams(Team a, Team b) {
        if (a.name.equals("russia")) return 1;
        if (b.name.equals("russia")) return -1;
        if (a.points != b.points) return Double.compare(b.points, a.points);
        if (a.topHeight != b.topHeight) return Double.compare(b.topHeight, a.topHeight);
        int deltaA = a.goalsScored - a.goalsConceded;
        int deltaB = b.goalsScored - b.goalsConceded;
        if (deltaA != deltaB) return Integer.compare(deltaB, deltaA);
        if (a.goalsScored != b.goalsScored) return Integer.compare(b.goalsScored, a.goalsScored);
        if (a.redCards != b.redCards) return Integer.compare(a.redCards, b.redCards);
        if (a.yellowCards != b.yellowCards) return Integer.compare(a.yellowCards, b.yellowCards);
        return new Random().nextInt(2) - 1;
    }

    private static void printRanking(List<Team> teams) {
        System.out.println("\nRanking:");
        System.out.println("Team\tPoints\tGoals Scored\tGoals Conceded\tYellow Cards\tRed Cards\tTop Height\tCriteria");

        for (Team team : teams) {
            System.out.println(team.name + "\t" + team.points + "\t" + team.goalsScored + "\t" +
                    team.goalsConceded + "\t" + team.yellowCards + "\t" + team.redCards + "\t" + team.topHeight);
        }
    }
}
