#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ranges>
#include "Team.h"
#include "Match.h"

void printRanking(const std::vector<Team> &teams) {
    std::cout << "\nRanking:\n";
    std::cout << "Team\tPoints\tGoals Scored\tGoals Conceded\tYellow Cards\tRed Cards\tTop Height\n";
    for (const auto &team : teams) {
        std::cout << team.name << "\t" << team.points << "\t" << team.goals_scored << "\t"
                  << team.goals_conceded << "\t" << team.yellow_cards << "\t" << team.red_cards << "\t"
                  << team.top_height << "\n";
    }
}

bool compareTeams(const Team &a, const Team &b) {
    if (a.points != b.points) return a.points > b.points;
    if (a.top_height != b.top_height) return a.top_height > b.top_height;
    int delta_a = a.goals_scored - a.goals_conceded;
    int delta_b = b.goals_scored - b.goals_conceded;
    if (delta_a != delta_b) return delta_a > delta_b;
    if (a.goals_scored != b.goals_scored) return a.goals_scored > b.goals_scored;
    if (a.red_cards != b.red_cards) return a.red_cards < b.red_cards;
    if (a.yellow_cards != b.yellow_cards) return a.yellow_cards < b.yellow_cards;
    return rand() % 2;
}

int main() {
    std::vector<Team> teams;
    std::string name;
    for (int i = 1; i <= 4; ++i) {
        std::cout << "Enter name for Team " << i << ": ";
        std::cin >> name;
        teams.emplace_back(name);
    }

    std::vector<Match> matches;
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            matches.emplace_back(teams[i], teams[j]);
        }
    }

    for (auto &match : matches) {
        std::cout << "\nMatch between " << match.team1.name << " and " << match.team2.name << ":\n";
        match.inputMatchData();
        match.updateTeams();
    }

    std::ranges::sort(teams, compareTeams);
    printRanking(teams);

    return 0;
}
