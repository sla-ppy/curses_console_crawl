#include <ncurses.h>

int main() {

    // CURSES BASE SETTINGS:
    initscr(); // starts curses mode
    keypad(stdscr, TRUE); // enables reading of F1, F2, arrow keys, etc
    raw(); // ctrl characters are directly passed to the program without generating a signal
    noecho();

    printw("Press F2 to print Hello!\n" );
    printw("Press the arrow keys to simulate movement.\n");
    printw("Press q to quit the program.\n");

    bool terminalIsRunning{true};

    while (terminalIsRunning)
    {
        refresh(); // updates stdscr so we can see the new outputs

        int keyInput;
        keyInput = getch();

        // how to use F1-12 keys
        if (keyInput == KEY_F(2)) {
            printw("Hello!\n"); // print item
        }

        // basic quit
        if (keyInput == 'q') {
            printw("Quitting now...\n");
            getch();
            terminalIsRunning = false;
        }

        // movement prototype
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
    }

    endwin(); // ends curses mode

    return 0;
}