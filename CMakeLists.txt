cmake_minimum_required(VERSION 3.10)

# Set the project name
project(8051emu)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
file(GLOB SOURCES "src/*.cpp" "src/*.c")
add_executable(8051emu ${SOURCES})

# Include directories
include_directories(include)

# Link libraries (if any)
# target_link_libraries(8051emu <library_name>)