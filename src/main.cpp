#include <ncurses.h>
#include <string.h>

// inserting example from the manual
void testExample() {
    char msg[] = "Just a string";        /* message to be appeared on the screen */
    int row, col;                /* to store the number of rows and *
					 * the number of columns of the screen */
    initscr();                /* start the curses mode */
    getmaxyx(stdscr, row, col);        /* get the number of rows and columns */
    mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
    /* print the message at the center of the screen */
    mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
    printw("Try resizing your window(if possible) and then run this program again");
    refresh();
    getch();
    endwin();
}

// awful code
// basically tried to use std::vector to always be able to change the message and constantly resize the window at the same time, didn't work
void resizeTest() {
    char msg[] = "Hi, I am the center of the terminal."; // msg to appear on screen
    int row, col;

    getmaxyx(stdscr, col, row); // get number of rows and cols

    if (row > 20 && col > 10) {
        mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
        mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
        printw("Try resizing your window(if possible) and then run this program again");
        refresh();
    }
    if (row > 40 && col > 20) {
        mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
        mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
        printw("Try resizing your window(if possible) and then run this program again");
        refresh();
    }
    if (row > 60 && col > 30) {
        mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
        mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
        printw("Try resizing your window(if possible) and then run this program again");
        refresh();
    }
    if (row > 80 && col > 40) {
        mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
        mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
        printw("Try resizing your window(if possible) and then run this program again");
        refresh();
    }
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

        resizeTest();
        inputManager();

        terminalIsRunning = false;
    }

    endwin(); // ends curses mode

    return 0;
}