#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "Messages.h"
#include "MessageDispatcher.h"
#include "Logger.h"

void generateMessages(MessageDispatcher& dispatcher) {
    std::srand(std::time(0));

    while (true) {
        int type = std::rand() % 3;
        switch (type) {
            case 0: {
                GreenMessage msg("GreenMessage", std::rand() % 100);
                dispatcher.publish(msg);
                break;
            }
            case 1: {
                BlueMessage msg(static_cast<double>(std::rand()) / RAND_MAX, static_cast<double>(std::rand()) / RAND_MAX);
                dispatcher.publish(msg);
                break;
            }
            case 2: {
                OrangeMessage msg("OrangeMessage1", "OrangeMessage2", std::rand() % 100, static_cast<double>(std::rand()) / RAND_MAX);
                dispatcher.publish(msg);
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    MessageDispatcher dispatcher;
    Logger logger("messages.log");

    dispatcher.subscribeToGreen([&logger](const GreenMessage& msg) {
        logger.log(msg);
    });

    dispatcher.subscribeToBlue([&logger](const BlueMessage& msg) {
        logger.log(msg);
    });

    dispatcher.subscribeToOrange([&logger](const OrangeMessage& msg) {
        logger.log(msg);
    });

    std::thread t1(generateMessages, std::ref(dispatcher));
    std::thread t2(generateMessages, std::ref(dispatcher));

    t1.join();
    t2.join();
    
    return 0;
}
