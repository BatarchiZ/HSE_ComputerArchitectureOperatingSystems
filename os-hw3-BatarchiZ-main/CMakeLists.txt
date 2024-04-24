cmake_minimum_required(VERSION 3.23)
project(HW3_RegExp C)

set(CMAKE_C_STANDARD 99)

add_executable(HW3_RegExp main.c)
add_executable(matches findMatches.c)
add_executable(Final synthesize.c)
add_executable(MATCHES match.c)