cmake_minimum_required(VERSION 3.1)

project(run)

find_package(Threads)

add_executable(run
    Source.cpp
    figure.cpp
    rectangle.cpp
    rhombus.cpp
    Subscriber.cpp
    trapezoid.cpp
    point.cpp
    vector.cpp)
set_property(TARGET run PROPERTY CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Werror")

target_link_libraries(run ${CMAKE_THREAD_LIBS_INIT})