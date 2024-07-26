#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <atomic> // Add this line
#include "MessageDispatcher.h"
#include "Logger.h"

// Random number generator setup
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> messageTypeDist(0, 2);
std::uniform_int_distribution<> intDist(0, 100);
std::uniform_real_distribution<> doubleDist(0.0, 100.0);
std::uniform_int_distribution<> counterDist(1, 10);

std::atomic<bool> stopGeneration(false);

void generateMessages(MessageDispatcher& dispatcher) {
    while (!stopGeneration.load()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
        
        int messageType = messageTypeDist(gen);
        switch (messageType) {
            case 0: {
                // GreenMessage
                GreenMessage greenMessage("Sample Message", counterDist(gen));
                dispatcher.publish(greenMessage);
                break;
            }
            case 1: {
                // BlueMessage
                BlueMessage blueMessage(doubleDist(gen), doubleDist(gen));
                dispatcher.publish(blueMessage);
                break;
            }
            case 2: {
                // OrangeMessage
                OrangeMessage orangeMessage("First", "Second", intDist(gen), doubleDist(gen));
                dispatcher.publish(orangeMessage);
                break;
            }
        }
    }
}

int main() {
    MessageDispatcher dispatcher;

    Logger logger("log.txt");

    // Subscribe to messages
    dispatcher.subscribeToGreen([&logger](const GreenMessage& message) {
        logger.log(message);
    });

    dispatcher.subscribeToBlue([&logger](const BlueMessage& message) {
        logger.log(message);
    });

    dispatcher.subscribeToOrange([&logger](const OrangeMessage& message) {
        logger.log(message);
    });

    // Start message generation in a separate thread
    std::thread generatorThread(generateMessages, std::ref(dispatcher));

    // Run for a while
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // Signal generator thread to stop and wait for it to finish
    stopGeneration.store(true);
    generatorThread.join();

    return 0;
}
