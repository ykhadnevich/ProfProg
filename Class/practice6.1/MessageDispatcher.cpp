// MessageDispatcher.cpp
#include "MessageDispatcher.h"

// Definitions for MessageDispatcher methods
MessageDispatcher::MessageDispatcher() {
    for (size_t i = 0; i < numWorkers_; ++i) {
        workers_.emplace_back(&MessageDispatcher::workerThread, this);
    }
}

MessageDispatcher::~MessageDispatcher() {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stop_ = true;
    }
    condVar_.notify_all();
    for (std::thread &worker : workers_) {
        worker.join();
    }
}

void MessageDispatcher::publish(const GreenMessage& message) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        greenQueue_.push(message);
    }
    condVar_.notify_one();
}

void MessageDispatcher::publish(const BlueMessage& message) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        blueQueue_.push(message);
    }
    condVar_.notify_one();
}

void MessageDispatcher::publish(const OrangeMessage& message) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        orangeQueue_.push(message);
    }
    condVar_.notify_one();
}

void MessageDispatcher::subscribeToGreen(std::function<void(const GreenMessage&)> subscriber) {
    std::lock_guard<std::mutex> lock(mutex_);
    greenSubscribers_.push_back(subscriber);
}

void MessageDispatcher::subscribeToBlue(std::function<void(const BlueMessage&)> subscriber) {
    std::lock_guard<std::mutex> lock(mutex_);
    blueSubscribers_.push_back(subscriber);
}

void MessageDispatcher::subscribeToOrange(std::function<void(const OrangeMessage&)> subscriber) {
    std::lock_guard<std::mutex> lock(mutex_);
    orangeSubscribers_.push_back(subscriber);
}

void MessageDispatcher::workerThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex_);
        condVar_.wait(lock, [this] {
            return stop_ || !greenQueue_.empty() || !blueQueue_.empty() || !orangeQueue_.empty();
        });

        if (stop_) return;

        while (!greenQueue_.empty()) {
            GreenMessage message = greenQueue_.front();
            greenQueue_.pop();
            for (const auto& subscriber : greenSubscribers_) {
                subscriber(message);
            }
        }

        while (!blueQueue_.empty()) {
            BlueMessage message = blueQueue_.front();
            blueQueue_.pop();
            for (const auto& subscriber : blueSubscribers_) {
                subscriber(message);
            }
        }

        while (!orangeQueue_.empty()) {
            OrangeMessage message = orangeQueue_.front();
            orangeQueue_.pop();
            for (const auto& subscriber : orangeSubscribers_) {
                subscriber(message);
            }
        }
    }
}
