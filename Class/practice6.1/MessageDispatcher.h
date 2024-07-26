#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H

#include <functional>
#include <vector>
#include <queue>
#include <thread>
#include <condition_variable>
#include "Messages.h"

class MessageDispatcher {
public:
    MessageDispatcher();
    ~MessageDispatcher();

    void publish(const GreenMessage& message);
    void publish(const BlueMessage& message);
    void publish(const OrangeMessage& message);

    void subscribeToGreen(std::function<void(const GreenMessage&)> subscriber);
    void subscribeToBlue(std::function<void(const BlueMessage&)> subscriber);
    void subscribeToOrange(std::function<void(const OrangeMessage&)> subscriber);

private:
    void workerThread();

    std::mutex mutex_;
    std::condition_variable condVar_;
    std::queue<GreenMessage> greenQueue_;
    std::queue<BlueMessage> blueQueue_;
    std::queue<OrangeMessage> orangeQueue_;
    std::vector<std::function<void(const GreenMessage&)>> greenSubscribers_;
    std::vector<std::function<void(const BlueMessage&)>> blueSubscribers_;
    std::vector<std::function<void(const OrangeMessage&)>> orangeSubscribers_;
    std::vector<std::thread> workers_;
    const size_t numWorkers_ = std::thread::hardware_concurrency(); // Use number of hardware threads
    bool stop_ = false;
};

#endif // MESSAGEDISPATCHER_H
