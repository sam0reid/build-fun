
#include <iostream>

#include <calculator/calculator.hpp>

int main() {
    double a = 1.0;
    double b = 2.0;
    auto calculator = calculator::SpecialCalculator();
    std::cout << "computing..." << std::endl;
    auto res = calculator.add(a, b);
    std::cout << a << " + " << b << " = "  << res << std::endl;
    return 0;
}