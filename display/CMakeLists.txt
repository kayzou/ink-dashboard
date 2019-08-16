cmake_minimum_required(VERSION 3.14)
project(display C)

set(CMAKE_C_STANDARD 99)

include_directories(lib/IT8951 lib/BCM2835)

add_executable(display main.c lib/BCM2835/bcm2835.c lib/IT8951/it8951.c lib/IT8951/miniGUI.c lib/IT8951/AsciiLib.c)

