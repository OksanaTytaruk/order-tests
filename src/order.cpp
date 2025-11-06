#include "order.h"
#include <stdexcept>
#include <cmath>

Money::Money(int kopiyky) {
    if (kopiyky < 0) throw std::invalid_argument("Negative value not allowed");
    amount = kopiyky;
}

Money Money::operator+(const Money& other) const {
    return Money(amount + other.amount);
}

Money& Money::operator+=(const Money& other) {
    amount += other.amount;
    return *this;
}

bool Money::operator==(const Money& other) const {
    return amount == other.amount;
}

void Money::apply_discount(double percent) {
    if (percent < 0 || percent > 100)
        throw std::invalid_argument("Invalid discount percent");
    amount = std::round(amount * (1 - percent / 100.0));
}

void Money::apply_vat(double percent) {
    if (percent < 0 || percent > 100)
        throw std::invalid_argument("Invalid VAT percent");
    amount = std::round(amount * (1 + percent / 100.0));
}
