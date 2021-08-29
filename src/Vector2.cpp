#include "Vector2.h"

Vector2::Vector2() {
    x = 0;
    y = 0;
}

Vector2::~Vector2() {

}

void Vector2::print() const {
    std::cout << "X coordinate: " << Vector2::x << '\n';
    std::cout << "Y coordinate: " << Vector2::y << '\n';
}