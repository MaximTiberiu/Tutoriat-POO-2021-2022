#include <fstream>
#include <iostream>
#include "../headers/Client.h"

Client::Client(std::string _nume, char _id, float _suma_maxima) {
    this->nume = _nume;
    this->id = _id;
    this->suma_maxima = _suma_maxima;
}

Client::Client(std::string _nume, char _id, float _suma_maxima, std::string lista_cumparaturi) {
    this->nume = _nume;
    this->id = _id;
    this->suma_maxima = _suma_maxima;

    std::ifstream fin;
    fin.open(lista_cumparaturi, std::ios::in);

    if (!fin) {
        std::cerr << "Can't open!\n";
    }

    std::string denumire;
    float pret;
    while (fin >> pret >> denumire) {
        this->produse.emplace_back(denumire, pret);
    }

    fin.close();
}

void Client::afisare() {
    std::cout << this->nume << " " << this->id << " " << this->suma_maxima << "\nPRODUSE:\n";
    for (auto & produs : produse) {
        std::cout << produs.getDenumire() << " " << produs.getPret() << "\n";
    }
}
