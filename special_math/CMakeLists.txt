
cmake_minimum_required(VERSION 3.20)
project(special_math)
set(CMAKE_CXX_STANDARD 17)

# 1. Create a static library 
add_library(special_math STATIC ${CMAKE_CURRENT_LIST_DIR}/src/add.cpp)
target_include_directories(special_math PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 2. Set this variable so that the headers are included in the install
set_target_properties(special_math PROPERTIES PUBLIC_HEADER "include/special_math/add.hpp")

# 3. Install the library
include(GNUInstallDirs)
install(
    TARGETS special_math
    EXPORT special_mathTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/special_math
)

# 4. Mate this to the previous install command (tied by EXPORT variable)
install(EXPORT special_mathTargets
    FILE special_mathConfig.cmake
    NAMESPACE special_math::
    DESTINATION cmake/special_math)