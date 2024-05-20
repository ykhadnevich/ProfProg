#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

const std::string DATABASE_FILE = "user_stats.txt";
const std::string SECRET_WORD = "bread";

// You have a list of functions like void doSomething(std::unordered_map<std::string, int>& obj)
// It actually means that we should have some encapsulation
// class SomeReasonableName {
// public:
//  // maybe appropriate constructor
//    void doSomething1();
//    void doSomething2();
//    ...
// private:
//    std::unordered_map<std::string, int> userStats;
//}

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

    // Just a note in some cases if we know that we will return from if else we can rewrite code to have it more linear instead of nested if-else like
    if (name == SECRET_WORD) {
        exterminateAll(userStats);
        return 0;
    }

    if (deleteFlag) {
        resetUser(name, userStats);
        return 0;
    }

    if (userStats.find(name) == userStats.end()) {
        userStats[name] = 0;
        // We can use println instead:
        std::println("Welcome, {}!", name);
        //std::cout << "Welcome, " << name << "!" << std::endl;
    } else {
        userStats[name]++;
        // We can use println instead:
        std::println("Hello again(x{}), {}!", userStats[name], name);
        //std::cout << "Hello again(x" << userStats[name] << "), " << name << "!" << std::endl;
    }
    saveDatabase(userStats);

    return 0;
}
