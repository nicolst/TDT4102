cmake_minimum_required(VERSION 3.9)
project(TDT4102)

set(CMAKE_CXX_STANDARD 17)

add_executable(oving1 "Oving 1/oving1.cpp")

add_executable(oving2 "Oving 2/oving2.cpp")

add_executable(oving3 "Oving 3/main.cpp" "Oving 3/cannonball.h" "Oving 3/cannonball.cpp" "Oving 3/utilities.h" "Oving 3/utilities.cpp")

add_executable(oving4 "Oving 4/main.cpp" "Oving 4/utilities.h" "Oving 4/utilities.cpp" "Oving 4/tests.h" "Oving 4/tests.cpp" "Oving 4/mastermind.h" "Oving 4/mastermind.cpp")

add_executable(oving5 "Oving 5/main.cpp" "Oving 5/card.h" "Oving 5/card.cpp" "Oving 5/carddeck.h" "Oving 5/carddeck.cpp" "Oving 5/blackjack.h" "Oving 5/blackjack.cpp")

add_executable(oving6 "Oving 6/main.cpp" "Oving 6/Car.h" "Oving 6/Car.cpp" "Oving 6/Person.h" "Oving 6/Person.cpp" "Oving 6/game.h" "Oving 6/game.cpp" "Oving 6/GameObjects.h" "Oving 6/GameObjects.cpp" "Oving 6/cannonball.h" "Oving 6/cannonball.cpp" "Oving 6/utilities.h" "Oving 6/utilities.cpp")
target_link_libraries(oving6 sfml-graphics-d sfml-system-d sfml-window-d)