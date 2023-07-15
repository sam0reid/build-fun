
cmake_minimum_required(VERSION 3.20)
project(calculator)
set(CMAKE_CXX_STANDARD 17)

# 0. Add this path to the search paths so we can find special_math
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_LIST_DIR}/../install)
find_package(special_math CONFIG REQUIRED)

# 1. Create a static library 
add_library(calculator SHARED ${CMAKE_CURRENT_LIST_DIR}/src/calculator.cpp)
target_link_libraries(calculator PRIVATE special_math::special_math)

target_include_directories(calculator PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 2. Set this variable so that the headers are included in the install
set_target_properties(calculator PROPERTIES PUBLIC_HEADER "include/calculator/calculator.hpp")

# 3. Install the library
include(GNUInstallDirs)
install(
    TARGETS calculator
    EXPORT calculatorTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/calculator
)

# 4. Mate this to the previous install command (tied by EXPORT variable)
install(EXPORT calculatorTargets
    FILE calculatorConfig.cmake
    NAMESPACE calculator::
    DESTINATION cmake/calculator)