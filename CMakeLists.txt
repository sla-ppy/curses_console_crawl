cmake_minimum_required(VERSION 3.19)
project(curses_console_crawl)

set(CMAKE_CXX_STANDARD 17)

# ncurses 1/2
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# where -Wall -Wextra -Wpedantic are extra compiler warnings
# include the -lpanel flag for <panel.h> library
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -lpanel")

# ncurses 2/2
add_executable(curses_console_crawl src/main.cpp src/Player.cpp src/Player.h src/Vector2.cpp src/Vector2.h)
target_link_libraries(curses_console_crawl ${CURSES_LIBRARIES})