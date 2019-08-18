cmake_minimum_required(VERSION 3.2.2)
project(display C)

set(CMAKE_C_STANDARD 99)
add_executable(display src/main.c src/bcm2835.c src/it8951.c src/miniGUI.c src/AsciiLib.c)

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
target_link_libraries(display ${PNG_LIBRARY})