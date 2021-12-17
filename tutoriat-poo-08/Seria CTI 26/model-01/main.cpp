#include <iostream>

#include "Copil.h"

int main() {
    Copil *c = new Copil;
    c->read(std::cin);
    c->print(std::cout);
    return 0;
}
