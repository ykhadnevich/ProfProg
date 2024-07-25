#include <iostream>
#include <memory>

class PaymentGateway {
public:
    virtual void processPayment(double amount) = 0;
    virtual void processRefund(double amount) = 0;
};

class PayPalGateway {
public:
    void pay(double amount) {
        std::cout << "Processing PayPal payment: $" << amount << std::endl;
        // PayPal payment logic
    }

    void refund(double amount) {
        std::cout << "Processing PayPal refund: $" << amount << std::endl;
        // PayPal refund logic
    }
};

class PayPalAdapter : public PaymentGateway {
private:
    PayPalGateway paypalGateway;

public:
    void processPayment(double amount) override {
        paypalGateway.pay(amount);
    }

    void processRefund(double amount) override {
        paypalGateway.refund(amount);
    }
};

class StripeGateway {
public:
    void charge(double amount) {
        std::cout << "Processing Stripe payment: $" << amount << std::endl;
        // Stripe payment logic
    }

    void refund(double amount) {
        std::cout << "Processing Stripe refund: $" << amount << std::endl;
        // Stripe refund logic
    }
};

class StripeAdapter : public PaymentGateway {
private:
    StripeGateway stripeGateway;

public:
    void processPayment(double amount) override {
        stripeGateway.charge(amount);
    }

    void processRefund(double amount) override {
        stripeGateway.refund(amount);
    }
};

void processPayment(PaymentGateway& gateway, double amount) {
    gateway.processPayment(amount);
}

void processRefund(PaymentGateway& gateway, double amount) {
    gateway.processRefund(amount);
}

int main() {
    std::unique_ptr<PaymentGateway> paypalAdapter = std::make_unique<PayPalAdapter>();
    std::unique_ptr<PaymentGateway> stripeAdapter = std::make_unique<StripeAdapter>();

    // Process payments using PayPal
    processPayment(*paypalAdapter, 100.0);
    processRefund(*paypalAdapter, 50.0);

    std::cout << std::endl;

    // Process payments using Stripe
    processPayment(*stripeAdapter, 200.0);
    processRefund(*stripeAdapter, 75.0);

    return 0;
}
