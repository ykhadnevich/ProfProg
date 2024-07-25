#ifndef BOOKRECOMMENDER_H
#define BOOKRECOMMENDER_H

#include <vector>
#include <string>

class BookRecommender {
private:
    std::vector<std::string> books;

public:
    BookRecommender();
    std::string getRandomBook();
    void recommendBook();
};

#endif // BOOKRECOMMENDER_H
