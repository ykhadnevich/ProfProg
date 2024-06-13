#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>
#include "Messages.h"

class Logger {
public:
    Logger(const std::string& filename) : file_(filename, std::ios::out | std::ios::app) {
        if (!file_.is_open()) {
            throw std::runtime_error("Unable to open log file");
        }
    }

    ~Logger() {
        if (file_.is_open()) {
            file_.close();
        }
    }

    void log(const GreenMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        file_ << "GreenMessage: " << message.getText() << ", " << message.getCounter() << std::endl;
    }

    void log(const BlueMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        file_ << "BlueMessage: " << message.getValue1() << ", " << message.getValue2() << std::endl;
    }

    void log(const OrangeMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        file_ << "OrangeMessage: " << message.getText1() << ", " << message.getText2() << ", "
              << message.getNumber() << ", " << message.getValue() << std::endl;
    }

private:
    std::ofstream file_;
    std::mutex mutex_;
};

#endif // LOGGER_H
