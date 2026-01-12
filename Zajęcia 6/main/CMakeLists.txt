cmake_minimum_required(VERSION 3.10)
project(plik C)

set(CMAKE_C_STANDARD 11)

add_executable(plik
        main.c
        data.c
        data.h
        analysis.c
        analysis.h
        display.c
        display.h
)