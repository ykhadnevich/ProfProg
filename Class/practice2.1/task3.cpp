#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

const std::string DATABASE_FILE = "user_stats.txt";
const std::string SECRET_WORD = "bread";

void loadDatabase(std::unordered_map<std::string, int>& userStats) {
    std::ifstream infile(DATABASE_FILE);
    if (!infile.is_open()) return;

    std::string name;
    int count;
    while (infile >> name >> count) {
        userStats[name] = count;
    }

    infile.close();
}

void saveDatabase(const std::unordered_map<std::string, int>& userStats) {
    std::ofstream outfile(DATABASE_FILE);
    for (const auto& entry : userStats) {
        outfile << entry.first << " " << entry.second << std::endl;
    }

    outfile.close();
}

void resetUser(const std::string& name, std::unordered_map<std::string, int>& userStats) {
    userStats.erase(name);
    std::cout << "Statistics for " << name << " have been reset." << std::endl;
    saveDatabase(userStats);
}

void exterminateAll(std::unordered_map<std::string, int>& userStats) {
    userStats.clear();
    std::cout << "All history exterminated." << std::endl;
    saveDatabase(userStats);
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <name> [delete]" << std::endl;
        return 1;
    }

    std::string name = argv[1];
    bool deleteFlag = (argc == 3 && std::string(argv[2]) == "delete");

    std::unordered_map<std::string, int> userStats;
    loadDatabase(userStats);

    if (name == SECRET_WORD) {
        exterminateAll(userStats);
    } else if (deleteFlag) {
        resetUser(name, userStats);
    } else {
        if (userStats.find(name) == userStats.end()) {
            userStats[name] = 0;
            std::cout << "Welcome, " << name << "!" << std::endl;
        } else {
            userStats[name]++;
            std::cout << "Hello again(x" << userStats[name] << "), " << name << "!" << std::endl;
        }
        saveDatabase(userStats);
    }

    return 0;
}
