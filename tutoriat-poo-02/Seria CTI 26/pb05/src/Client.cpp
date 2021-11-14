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
    int numarProduse;
    while (fin >> numarProduse >> pret >> denumire) {
        this->produse.emplace_back(denumire, pret, numarProduse);
    }

    fin.close();
}

void Client::afisare() {
    std::cout << this->nume << " " << this->id << " " << this->suma_maxima << "\nPRODUSE:\n";
    for (auto & produs : produse) {
        std::cout << produs.getDenumire() << " " << produs.getPret() << " " << produs.getNumarProduse() << "\n";
    }
}

void Client::addProdus(const std::string &denumireProdus, float pretProdus, int numarProduse) {
    this->produse.emplace_back(denumireProdus, pretProdus, numarProduse);
}

void Client::deleteProdus(const std::string &denumireProdus, int numarProduse) {
    for (int i = 0; i < this->produse.size() ; i++) {
        if (this->produse[i].getDenumire() == denumireProdus) {
            if (numarProduse >= this->produse[i].getNumarProduse()) {
                produse.erase(produse.begin() + i);
            } else {
                this->produse[i].setNumarProduse(this->produse[i].getNumarProduse() - numarProduse);
            }
        }
    }
}

float Client::totalPlata() {
    float total = 0;
    for (auto & produs : this->produse) {
        total += produs.getPret() * produs.getNumarProduse();
    }

    if (this->id == 'F') {
        total = total * 0.9;
    }
    if (total <= this->suma_maxima) {
        std::cout << total << "\n";
        return total;
    } else {
        std::cout << "Clientul nu are suma de bani necesara achitarii!\n";
        return -1;
    }

}
