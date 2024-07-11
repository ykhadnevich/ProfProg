#ifndef TEAM_H
#define TEAM_H

#include <string>

class Team {
public:
    std::string name;
    int goals_scored = 0;
    int goals_conceded = 0;
    int yellow_cards = 0;
    int red_cards = 0;
    double top_height = 0.0;
    double points = 0.0;

    Team(const std::string &name);

    void updateStats(int scored, int conceded, int yellow, int red, double height);
};

#endif // TEAM_H
