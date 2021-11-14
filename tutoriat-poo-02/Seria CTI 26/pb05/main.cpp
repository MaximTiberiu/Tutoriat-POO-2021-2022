#include <iostream>

#include "./headers/Client.h"
#include "src/Casa.h"

int main() {

    Client c1("Popescu", 'F', 103.5, "C:\\Users\\maxim\\Desktop\\Tutoriat-POO-2021-2022\\tutoriat-poo-02\\Seria CTI 26\\pb05\\listaProduse\\lista1.txt");
    c1.addProdus("carne", 20, 2);
    c1.deleteProdus("suc", 3);
    c1.afisare();
    c1.totalPlata();
    Client c2("Ionescu", 'R', 20);
    c2.addProdus("carne", 22.5, 1);
    Casa casa(1, {c1, c2});
    casa.serveste();
    // std::find()
    // std::vector<int> v = {1, 2, 3, 4, 5, 6, 7} std::vector<int> v;
    // if (std::find(v.begin(), v.end(), 5) != v.end()) {...}
    return 0;
}
