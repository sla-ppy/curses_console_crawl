#include <ncurses.h>
// apperently <panel.h> is already included and linked properly with my current CMake setup
#include <panel.h>

/*
 *  Things Im interested in:
 *
 *  1. Print smth to middle of the screen
 *  2. Be able to resize the console screen while auto-adjusting current screen.
 *  3. When we reach the current last row, we do clear from the first player input, smth like that. Unsure.
 *  4. // int ch;
 *        while((ch = getch()) != KEY_F(1)) {}
 *
 *
 */

void playMenu() {
    printw("We are on the play screen.");
}

int main() {
    initscr(); // start curses mode

    // TODO: new window for the setting descriptins on main menu, new game options, all that sweet stuff
    //WINDOW *create_newwin(int height, int width, int starty, int starx);
    //WINDOW *WINDOW_MENU;
    //delwin(WINDOW_MENU);

    // base terminal settings:
    noecho(); // disables echo
    keypad(stdscr, TRUE); // enables F 1-12 keys, arrow keys

    printw("Program starting up.\n"
           "Press anything to continue!\n");
    refresh(); // actually render previous string
    getch();

    bool onTitleScreen{TRUE};

    // most functions using coordinates with curses has yx instead of xy thats why i follow this convention
    int STR_SCREEN_COL = getmaxy(stdscr); // Y
    int STR_SCREEN_ROW = getmaxx(stdscr); // X

    while (onTitleScreen) {
        // TODO: clearScreen() goes here! find cool way to do that, maybe ncurses sister libraries?
        int menuChoice;

        mvprintw(STR_SCREEN_COL / 2, STR_SCREEN_ROW / 2, "1. Play\n"
                                                         "2. Quit\n"
        );
        menuChoice = getch();

        switch (menuChoice) {
            case 1:
                playMenu();
                break;

            case 2:
                printw("Quitting now...");
                onTitleScreen = false;
                getch();
                break;

            default:
                printw("Choose an option to continue.");
                break;
        }
        onTitleScreen = false;
    }

    endwin(); // end curses mode
    return 0; // end of program
}