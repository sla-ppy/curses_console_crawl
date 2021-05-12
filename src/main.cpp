#include <iostream>
#include <ncurses.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);

void destroy_win(WINDOW *local_win);

int main() {

    initscr();
    printw("Hello World !!!");
    refresh();
    getch();
    // restore terminal settings before exit
    endwin();

    return 0;
}