#include <iostream>
#include <vector>

#include "./headers/Client.h"
#include "headers/Casa.h"

int main() {
    Client c1("Popescu", 'F', 106.7, "C:\\Users\\maxim\\Desktop\\Tutoriat-POO-2021-2022\\tutoriat-poo-02\\Seria MI 21\\pb05\\listeCumparaturi\\lista1.txt");
    Client c2("ionescu", 'F', 105);

    Casa casa1(1, {c1, c2});

    Produs p1("apa", 5);
    Produs p2("paine", 2);
    Produs p3("carne", 50);

    c2.addProdus(p1, 3);
    c2.addProdus(p2, 5);
    c2.addProdus(p2, 2);
    c2.deleteProdus(p1, 6);
    c2.deleteProdus(p2, 5);
    c2.addProdus(p3, 5);

    casa1.serveste();
    return 0;
}
