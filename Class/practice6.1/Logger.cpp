#include "Logger.h"

Logger::Logger(const std::string& filename) : file_(filename, std::ios::out | std::ios::app) {
    if (!file_.is_open()) {
        throw std::runtime_error("Unable to open log file");
    }
}

Logger::~Logger() {
    if (file_.is_open()) {
        file_.close();
    }
}

void Logger::log(const GreenMessage& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    file_ << "GreenMessage: " << message.getText() << ", " << message.getCounter() << std::endl;
}

void Logger::log(const BlueMessage& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    file_ << "BlueMessage: " << message.getValue1() << ", " << message.getValue2() << std::endl;
}

void Logger::log(const OrangeMessage& message) {
    std::lock_guard<std::mutex> lock(mutex_);
    file_ << "OrangeMessage: " << message.getText1() << ", " << message.getText2() << ", "
          << message.getNumber() << ", " << message.getValue() << std::endl;
}
