#include "../src/order.h"
#include <cassert>
#include <iostream>

void test_creation() {
    Money m(100);
    assert(m.get_amount() == 100);
    try {
        Money n(-5);
        assert(false);
    } catch (std::invalid_argument&) {}
}

void test_plus_operator() {
    Money a(100), b(50);
    Money c = a + b;
    assert(c.get_amount() == 150);
}

void test_discount() {
    Money m(1000);
    m.apply_discount(0);
    assert(m.get_amount() == 1000);
    m.apply_discount(100);
    assert(m.get_amount() == 0);
    try {
        m.apply_discount(-5);
        assert(false);
    } catch (std::invalid_argument&) {}
}

void test_vat() {
    Money m(1000);
    m.apply_vat(0);
    assert(m.get_amount() == 1000);
    m.apply_vat(20);
    assert(m.get_amount() == 1200);
}

int main() {
    test_creation();
    test_plus_operator();
    test_discount();
    test_vat();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
