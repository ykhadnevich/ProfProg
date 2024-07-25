#include "BookRecommender.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

BookRecommender::BookRecommender() {
    books = {
        "The Topographer’s Clown",
        "The Chamber of Beaver",
        "The Ironer of Kanban",
        "The Piglet of Tire",
        "The Border of the Unix",
        "The Half-Time Convince",
        "The Earthly Pillows",
        "The Censorship of the Ping",
        "The True Powers",
        "The Overturn of the Ling"
    };
    std::srand(std::time(0));  // Seed random number generator
}

std::string BookRecommender::getRandomBook() {
    if (books.empty()) {
        return "";
    }
    int index = std::rand() % books.size();
    return books[index];
}

void BookRecommender::recommendBook() {
    while (!books.empty()) {
        std::string book = getRandomBook();
        std::cout << "We recommend you to read: " << book << std::endl;
        std::cout << "Do you like this book? (yes/no): ";
        std::string response;
        std::cin >> response;

        if (response == "yes") {
            std::cout << "Great! Enjoy your book." << std::endl;
            return;
        } else if (response == "no") {
            books.erase(std::remove(books.begin(), books.end(), book), books.end());
        } else {
            std::cout << "Invalid response. Please enter 'yes' or 'no'." << std::endl;
        }
    }
    std::cout << "Adios amigo!" << std::endl;
}
