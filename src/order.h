#pragma once
#include <stdexcept>

class Money {
    int amount; // зберігається в копійках
public:
    Money(int kopiyky = 0);
    Money operator+(const Money& other) const;
    Money& operator+=(const Money& other);
    bool operator==(const Money& other) const;
    void apply_discount(double percent);
    void apply_vat(double percent);
    int get_amount() const { return amount; }
};
