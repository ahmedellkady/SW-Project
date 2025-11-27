cmake_minimum_required(VERSION 3.29)
project(Movie)

set(CMAKE_CXX_STANDARD 20)

add_executable(Movie main.cpp
        User.cpp
        User.h
        ShowTime.cpp
        ShowTime.h
        Movie.cpp
        Movie.h
        Customer.cpp
        Customer.h
        Admin.cpp
        Admin.h
        globals.h
        globals.cpp
)
