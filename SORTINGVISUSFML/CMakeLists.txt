cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")
project(SFML)

# Source files
set(SOURCES
    main.cpp
    otherfunctionss.cpp
    sortingalgorithms.cpp
)

# Add your project executable
add_executable(testsfml ${SOURCES})
find_package(SFML REQUIRED COMPONENTS system window graphics)
target_link_libraries(testsfml PRIVATE sfml-graphics sfml-window sfml-system)
