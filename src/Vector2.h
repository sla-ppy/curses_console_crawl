#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#include<iostream>

// Vector Class:
// - Positions for player, enemies, objects, rooms even?
// - Pathfinding for enemies, player spells, ranged weapons

struct Vector2 {
public:
    int x;
    int y;

    Vector2();
    ~Vector2();

    void print() const;
};

#endif // VECTOR_MATH_H
