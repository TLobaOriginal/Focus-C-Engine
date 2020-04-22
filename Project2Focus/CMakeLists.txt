cmake_minimum_required(VERSION 3.15)
project(Project2Focus C)

set(CMAKE_C_STANDARD 11)

add_executable(Project2Focus main.c Initialiser.c Initialiser.h game.c game.h logic.c logic.h Stack.c Stack.h Turn.c Turn.h)