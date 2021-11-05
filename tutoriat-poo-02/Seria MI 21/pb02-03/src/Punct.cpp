#include "../headers/Punct.h"

Punct::Punct() {
    this->x = 0;
    this->y = 0;
}

Punct::Punct(int x, int y) {
    this->x = x;
    this->y = y;
}

int Punct::getX() const {
    return x;
}

void Punct::setX(int x) {
    Punct::x = x;
}

int Punct::getY() const {
    return y;
}

void Punct::setY(int y) {
    Punct::y = y;
}
