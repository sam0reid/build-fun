
#include "calculator/calculator.hpp"

#include <iostream>

#include <special_math/add.hpp>

namespace calculator {
    double SpecialCalculator::add(double a, double b) {
        std::cout << "Invoked calculator add" << std::endl;
        return special_math::special_add(a, b);
    }
}