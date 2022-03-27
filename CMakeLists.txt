cmake_minimum_required(VERSION 3.16)
project(makro_vekor C)

set(CMAKE_C_STANDARD 99)

add_executable(makro_vekor main.c com_vector.c com_vector.h)
