#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

class UserStatsManager {
private:
    const std::string DATABASE_FILE = "user_stats.txt";
    const std::string SECRET_WORD = "bread";
    std::unordered_map<std::string, int> userStats;

    void loadDatabase() {
        std::ifstream infile(DATABASE_FILE);
        if (!infile.is_open()) return;

        std::string name;
        int count;
        while (infile >> name >> count) {
            userStats[name] = count;
        }

        infile.close();
    }

    void saveDatabase() const {
        std::ofstream outfile(DATABASE_FILE);
        for (const auto& entry : userStats) {
            outfile << entry.first << " " << entry.second << std::endl;
        }

        outfile.close();
    }

public:
    UserStatsManager() {
        loadDatabase();
    }

    void resetUser(const std::string& name) {
        userStats.erase(name);
        std::cout << "Statistics for " << name << " have been reset." << std::endl;
        saveDatabase();
    }

    void exterminateAll() {
        userStats.clear();
        std::cout << "All history exterminated." << std::endl;
        saveDatabase();
    }

    void processUser(const std::string& name) {
        if (name == SECRET_WORD) {
            exterminateAll();
        } else {
            if (userStats.find(name) == userStats.end()) {
                userStats[name] = 0;
                std::cout << "Welcome, " << name << "!" << std::endl;
            } else {
                userStats[name]++;
                std::cout << "Hello again(x" << userStats[name] << "), " << name << "!" << std::endl;
            }
            saveDatabase();
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <name> [delete]" << std::endl;
        return 1;
    }

    std::string name = argv[1];
    bool deleteFlag = (argc == 3 && std::string(argv[2]) == "delete");

    UserStatsManager statsManager;
    if (deleteFlag) {
        statsManager.resetUser(name);
    } else {
        statsManager.processUser(name);
    }

    return 0;
}
