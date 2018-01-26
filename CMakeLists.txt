cmake_minimum_required(VERSION 3.9)
project(TDT4102)

set(CMAKE_CXX_STANDARD 17)

add_executable(oving1 "Oving 1/oving1.cpp")

add_executable(oving2 "Oving 2/oving2.cpp")

add_executable(oving3 "Oving 3/main.cpp" "Oving 3/cannonball.h" "Oving 3/cannonball.cpp" "Oving 3/utilities.h" "Oving 3/utilities.cpp")

add_executable(oving4 "Oving 4/main.cpp" "Oving 4/utilities.h" "Oving 4/utilities.cpp" "Oving 4/tests.h" "Oving 4/tests.cpp" "Oving 4/mastermind.h" "Oving 4/mastermind.cpp")