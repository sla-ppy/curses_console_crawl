#include <ncurses.h>
#include <cstring>

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

// inserting example from the manual to test, lol
void testExample() {
    start_color();			/* Start color functionality	*/

    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    printw("A Big string which i didn't care to type fully ");
    mvchgat(0, 0, -1, A_BLINK, 1, NULL);
    /*
     * First two parameters specify the position at which to start
     * Third parameter number of characters to update. -1 means till
     * end of line
     * Forth parameter is the normal attribute you wanted to give
     * to the character
     * Fifth is the color index. It is the index given during init_pair()
     * use 0 if you didn't want color
     * Sixth one is always NULL
     */
}

bool inputManager() {
    int keyInput;

    bool inputBeingManaged{true};

    while (inputBeingManaged) {

        keyInput = getch();

        // how to use F1-12 keys
        if (keyInput == KEY_F(2)) {
            printw("Hello!\n"); // print item
        }

        // basic quit
        if (keyInput == 'q') {
            printw("Quitting now...\n");
            getch();
            inputBeingManaged = false;
        }

        // movement prototype
        // FIXME: interestingly when you scroll up and down, it also works as KEY_UP and KEY_DOWN, why?
        if (keyInput == KEY_LEFT) {
            printw("We moved left.\n");
        }
        if (keyInput == KEY_RIGHT) {
            printw("We moved right.\n");
        }
        if (keyInput == KEY_UP) {
            printw("We moved UP.\n");
        }
        if (keyInput == KEY_DOWN) {
            printw("We moved down.\n");
        }

        // test example
        if (keyInput == 't') {
            testExample();
        }
    }
    return true;
}

int main() {

    // CURSES BASE SETTINGS:
    initscr(); // starts curses mode
    keypad(stdscr, TRUE); // enables reading of F1, F2, arrow keys, etc
    raw(); // ctrl characters are directly passed to the program without generating a signal
    noecho();

    printw("<F2> - print Hello!\n");
    printw("<Arrow keys> - simulate movement\n");
    printw("<q> - Quit\n");
    printw("<t> - Test example\n");

    bool terminalIsRunning{true};

    while (terminalIsRunning) {
        refresh(); // updates stdscr so we can see the new outputs
        inputManager();
        terminalIsRunning = false;
    }

    endwin(); // ends curses mode

    return 0;
}