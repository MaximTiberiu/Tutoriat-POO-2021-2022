#include <iostream>
#include "./headers/Dreptunghi.h"

int main() {
    Punct p1(1, 2);
    Punct p2(5, -2);
    Dreptunghi dreptunghi(p1, p2);
    std::cout << arie(dreptunghi) << "\n";
    return 0;
}
