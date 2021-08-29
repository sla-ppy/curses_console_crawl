#include <iostream>
#include <ncurses.h>
#include <vector>

#include "Player.h"
#include "Vector2.h"

int main() {
    // define player
    Player player;
    // set spawn position
    player.pos.x = 2;
    player.pos.y = 3;
    player.print();

    // define gamemap

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if ( y == player.pos.y) {
                std::cout << '@';
            } else {
                std::cout << '.';
            }
        }

        std::cout << '\n';
    }



    return 0; // end of program
}