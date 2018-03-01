cmake_minimum_required(VERSION 3.9)
project(TDT4102)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules/" ${CMAKE_MODULE_PATH})
#set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "D:\\SFML-2.4.2")
#set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH})

#Find the SFML lib
#find_package(SFML 2 REQUIRED graphics window)
#include_directories(${SFML_INCLUDE_DIR})

add_executable(oving1 "Oving 1/oving1.cpp")

add_executable(oving2 "Oving 2/oving2.cpp")

add_executable(oving3 "Oving 3/main.cpp" "Oving 3/cannonball.h" "Oving 3/cannonball.cpp" "Oving 3/utilities.h" "Oving 3/utilities.cpp")

add_executable(oving4 "Oving 4/main.cpp" "Oving 4/utilities.h" "Oving 4/utilities.cpp" "Oving 4/tests.h" "Oving 4/tests.cpp" "Oving 4/mastermind.h" "Oving 4/mastermind.cpp")

add_executable(oving5 "Oving 5/main.cpp" "Oving 5/card.h" "Oving 5/card.cpp" "Oving 5/carddeck.h" "Oving 5/carddeck.cpp" "Oving 5/blackjack.h" "Oving 5/blackjack.cpp")

add_executable(oving6 "Oving 6/game.cpp" "Oving 6/main.cpp" "Oving 6/Car.h" "Oving 6/Car.cpp" "Oving 6/Person.h" "Oving 6/Person.cpp" "Oving 6/GameObjects.h" "Oving 6/GameObjects.cpp" "Oving 6/cannonball.h" "Oving 6/cannonball.cpp" "Oving 6/utilities.h" "Oving 6/utilities.cpp")
#target_link_libraries(oving6 sfml-graphics-d sfml-system-d sfml-window-d)
#target_link_libraries(oving6 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
#target_link_libraries(oving6 sfml-graphics sfml-window)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "D:/SFML-2.4.2/" ${CMAKE_PREFIX_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(oving6 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

add_executable(oving7 "Oving 7/main.cpp" "Oving 7/fibonacci.h" "Oving 7/fibonacci.cpp" "Oving 7/matrix.h" "Oving 7/matrix.cpp" "Oving 7/dummy.h" "Oving 7/dummy.cpp")