
#include "special_math/add.hpp"
#include <iostream>

namespace special_math {

double special_add(double a, double b) {
    std::cout << "Invoked special_add" << std::endl;
    return a + b;
}

} // namespace special_math