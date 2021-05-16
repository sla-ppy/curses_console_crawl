## Project Description:
curses-console-crawl will hopefully be a console-based dungeon crawling roguelike game.
I am using the ncurses.h library to give me the graphical edge that I need to have the neat output!
<div>

To compile:
```
g++ -Wall -Wextra -Wpedantic  -lncurses src/main.cpp -o curses-console-crawl
```
Where:
* -Wall -Wextra -Wpedantic -> turns on warnings during compilation
* -lcurses -> links the program with ncurses
* -o curses-console-crawl -> names the generated file curses-console-crawl, also has the capability to place the file in a specific location if you desire

To launch:
```
./curses-console-crawl
```
