#include "Player.h"

Player::Player() {
    std::cout << "Player constructor called." << '\n';
    hp = 10;
    gold = 15;
};

Player::~Player() {
    std::cout << "Player destructor called." << '\n';
};


void Player::print() const {
    std::cout << '\n';
    std::cout << "Player Information: " << '\n';
    std::cout << "HP: " << Player::hp << '\n';
    std::cout << "Gold: " << Player::gold << '\n';
    std::cout << "Position: " << "X: " << Player::pos.x << " " << "Y: " << Player::pos.y << '\n';
    std::cout << '\n';
}