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
    printw("Upper left corner           "); addch(ACS_ULCORNER); printw("\n");
    printw("Lower left corner           "); addch(ACS_LLCORNER); printw("\n");
    printw("Lower right corner          "); addch(ACS_LRCORNER); printw("\n");
    printw("Tee pointing right          "); addch(ACS_LTEE); printw("\n");
    printw("Tee pointing left           "); addch(ACS_RTEE); printw("\n");
    printw("Tee pointing up             "); addch(ACS_BTEE); printw("\n");
    printw("Tee pointing down           "); addch(ACS_TTEE); printw("\n");
    printw("Horizontal line             "); addch(ACS_HLINE); printw("\n");
    printw("Vertical line               "); addch(ACS_VLINE); printw("\n");
    printw("Large Plus or cross over    "); addch(ACS_PLUS); printw("\n");
    printw("Scan Line 1                 "); addch(ACS_S1); printw("\n");
    printw("Scan Line 3                 "); addch(ACS_S3); printw("\n");
    printw("Scan Line 7                 "); addch(ACS_S7); printw("\n");
    printw("Scan Line 9                 "); addch(ACS_S9); printw("\n");
    printw("Diamond                     "); addch(ACS_DIAMOND); printw("\n");
    printw("Checker board (stipple)     "); addch(ACS_CKBOARD); printw("\n");
    printw("Degree Symbol               "); addch(ACS_DEGREE); printw("\n");
    printw("Plus/Minus Symbol           "); addch(ACS_PLMINUS); printw("\n");
    printw("Bullet                      "); addch(ACS_BULLET); printw("\n");
    printw("Arrow Pointing Left         "); addch(ACS_LARROW); printw("\n");
    printw("Arrow Pointing Right        "); addch(ACS_RARROW); printw("\n");
    printw("Arrow Pointing Down         "); addch(ACS_DARROW); printw("\n");
    printw("Arrow Pointing Up           "); addch(ACS_UARROW); printw("\n");
    printw("Board of squares            "); addch(ACS_BOARD); printw("\n");
    printw("Lantern Symbol              "); addch(ACS_LANTERN); printw("\n");
    printw("Solid Square Block          "); addch(ACS_BLOCK); printw("\n");
    printw("Less/Equal sign             "); addch(ACS_LEQUAL); printw("\n");
    printw("Greater/Equal sign          "); addch(ACS_GEQUAL); printw("\n");
    printw("Pi                          "); addch(ACS_PI); printw("\n");
    printw("Not equal                   "); addch(ACS_NEQUAL); printw("\n");
    printw("UK pound sign               "); addch(ACS_STERLING); printw("\n");

    refresh();
    getch();
    endwin();
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