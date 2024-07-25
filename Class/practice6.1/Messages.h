#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>

class GreenMessage {
public:
    GreenMessage(const std::string& text, int counter) : text_(text), counter_(counter) {}
    std::string getText() const { return text_; }
    int getCounter() const { return counter_; }

private:
    std::string text_;
    int counter_;
};

class BlueMessage {
public:
    BlueMessage(double value1, double value2) : value1_(value1), value2_(value2) {}
    double getValue1() const { return value1_; }
    double getValue2() const { return value2_; }

private:
    double value1_;
    double value2_;
};

class OrangeMessage {
public:
    OrangeMessage(const std::string& text1, const std::string& text2, int number, double value)
        : text1_(text1), text2_(text2), number_(number), value_(value) {}
    std::string getText1() const { return text1_; }
    std::string getText2() const { return text2_; }
    int getNumber() const { return number_; }
    double getValue() const { return value_; }

private:
    std::string text1_;
    std::string text2_;
    int number_;
    double value_;
};

#endif // MESSAGES_H
