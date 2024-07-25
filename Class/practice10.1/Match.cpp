#include <iostream>
#include "Match.h"

Match::Match(Team &t1, Team &t2) : team1(t1), team2(t2) {}

void Match::inputMatchData() {
    std::cout << "Enter goals scored by " << team1.name << ": ";
    std::cin >> goals_team1;
    std::cout << "Enter goals scored by " << team2.name << ": ";
    std::cin >> goals_team2;
    std::cout << "Enter yellow cards shown to " << team1.name << ": ";
    std::cin >> yellow_team1;
    std::cout << "Enter yellow cards shown to " << team2.name << ": ";
    std::cin >> yellow_team2;
    std::cout << "Enter red cards shown to " << team1.name << ": ";
    std::cin >> red_team1;
    std::cout << "Enter red cards shown to " << team2.name << ": ";
    std::cin >> red_team2;
    std::cout << "Enter top height reached by the ball for " << team1.name << ": ";
    std::cin >> top_height_team1;
    std::cout << "Enter top height reached by the ball for " << team2.name << ": ";
    std::cin >> top_height_team2;
}

void Match::updateTeams() {
    team1.updateStats(goals_team1, goals_team2, yellow_team1, red_team1, top_height_team1);
    team2.updateStats(goals_team2, goals_team1, yellow_team2, red_team2, top_height_team2);

    if (goals_team1 > goals_team2) {
        team1.points += 3.14;
        team2.points -= 0.5;
    } else if (goals_team1 < goals_team2) {
        team1.points -= 0.5;
        team2.points += 3.14;
    } else {
        team1.points += 2.71828;
        team2.points += 2.71828;
    }
}
