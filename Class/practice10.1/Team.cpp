#include "Team.h"

Team::Team(const std::string &name) : name(name) {}

void Team::updateStats(int scored, int conceded, int yellow, int red, double height) {
    goals_scored += scored;
    goals_conceded += conceded;
    yellow_cards += yellow;
    red_cards += red;
    top_height += height;
}
