cmake_minimum_required(VERSION 3.19)
project(curses_console_crawl)

set(CMAKE_CXX_STANDARD 17)

# ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# add flags for compiler warnings
if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif ()

# ncurses
add_executable(curses_console_crawl src/main.cpp)
target_link_libraries(curses_console_crawl ${CURSES_LIBRARIES})