#ifndef MATCH_H
#define MATCH_H

#include "Team.h"

class Match {
public:
    Team &team1;
    Team &team2;
    int goals_team1;
    int goals_team2;
    int yellow_team1;
    int yellow_team2;
    int red_team1;
    int red_team2;
    double top_height_team1;
    double top_height_team2;

    Match(Team &t1, Team &t2);

    void inputMatchData();
    void updateTeams();
};

#endif // MATCH_H
