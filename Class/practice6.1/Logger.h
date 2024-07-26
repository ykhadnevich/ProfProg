#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>
#include "Messages.h"

class Logger {
public:
    Logger(const std::string& filename);
    ~Logger();
    void log(const GreenMessage& message);
    void log(const BlueMessage& message);
    void log(const OrangeMessage& message);

private:
    std::ofstream file_;
    std::mutex mutex_;
};

#endif // LOGGER_H
