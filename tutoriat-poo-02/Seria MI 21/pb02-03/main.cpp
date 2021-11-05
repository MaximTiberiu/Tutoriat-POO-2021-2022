#include <iostream>
#include "./headers/Dreptunghi.h"

int main() {
    Punct p1(1, 2);
    Punct p2(3, -2);
    Dreptunghi d(p1, p2);
    std::cout << arie(d) << "\n";
    return 0;
}
