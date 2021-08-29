#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>

#include "Vector2.h"

class Player {
private:
    int hp{0};
    int gold{0};

public:
    Vector2 pos;

    Player();
    ~Player();

    void print() const;
};

#endif // PLAYER_H
