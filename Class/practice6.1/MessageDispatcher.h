#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H

#include <iostream>
#include <functional>
#include <vector>
#include <mutex>
#include "Messages.h"

class MessageDispatcher {
public:
    void publish(const GreenMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& subscriber : greenSubscribers_) {
            subscriber(message);
        }
    }

    void publish(const BlueMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& subscriber : blueSubscribers_) {
            subscriber(message);
        }
    }

    void publish(const OrangeMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& subscriber : orangeSubscribers_) {
            subscriber(message);
        }
    }

    void subscribeToGreen(std::function<void(const GreenMessage&)> subscriber) {
        std::lock_guard<std::mutex> lock(mutex_);
        greenSubscribers_.push_back(subscriber);
    }

    void subscribeToBlue(std::function<void(const BlueMessage&)> subscriber) {
        std::lock_guard<std::mutex> lock(mutex_);
        blueSubscribers_.push_back(subscriber);
    }

    void subscribeToOrange(std::function<void(const OrangeMessage&)> subscriber) {
        std::lock_guard<std::mutex> lock(mutex_);
        orangeSubscribers_.push_back(subscriber);
    }

private:
    std::mutex mutex_;
    std::vector<std::function<void(const GreenMessage&)>> greenSubscribers_;
    std::vector<std::function<void(const BlueMessage&)>> blueSubscribers_;
    std::vector<std::function<void(const OrangeMessage&)>> orangeSubscribers_;
};

#endif // MESSAGEDISPATCHER_H
