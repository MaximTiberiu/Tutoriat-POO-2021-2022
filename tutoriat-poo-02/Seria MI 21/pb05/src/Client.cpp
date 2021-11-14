#include <fstream>
#include <iostream>
#include "../headers/Client.h"

Client::Client(const std::string &_nume, char _id, float _suma_maxima) {
    this->nume = _nume;
    this->id = _id;
    this->suma_maxima = _suma_maxima;
}

Client::Client(const std::string &_nume, char _id, float _suma_maxima, const std::string &_lista_cumparaturi) {
    this->nume = _nume;
    this->id = _id;
    this->suma_maxima = _suma_maxima;

    std::ifstream fin;
    fin.open(_lista_cumparaturi, std::ios::in);

    if (!fin) {
        std::cerr << "Can't open!\n";
    }

    std::string denumire;
    float pret;
    int numar_produse;

    while(fin >> numar_produse >> pret >> denumire) {
        this->produse.emplace_back(denumire, pret, numar_produse);
    }

    fin.close();
}

void Client::afisare() {
    std::cout << this->nume << " " << this->id << " " << this->suma_maxima << "\nPRODUSE:\n";
    for (auto & produs : produse) {
        std::cout << produs.getDenumire() << " " << produs.getPret() << " " << produs.getNumarProduse() << "\n";
    }
}

void Client::addProdus(Produs produs, int numarProduse) {
    for (int i = 0 ; i < this->produse.size() ; i++) {
        if(this->produse[i].getDenumire() == produs.getDenumire() && this->produse[i].getPret() == produs.getPret()) {
            this->produse[i].setNumarProduse(this->produse[i].getNumarProduse() + numarProduse);
            return;
        }
    }

    this->produse.emplace_back(produs.getDenumire(), produs.getPret(), numarProduse);
}

void Client::deleteProdus(Produs produs, int numarProduse) {
    for (int i = 0 ; i < this->produse.size() ; i++) {
        if(this->produse[i].getDenumire() == produs.getDenumire() && this->produse[i].getPret() == produs.getPret()) {
            if (this->produse[i].getNumarProduse() <= numarProduse) {
                produse.erase(produse.begin() + i);
            } else {
                this->produse[i].setNumarProduse(this->produse[i].getNumarProduse() - numarProduse);
            }
        }
    }
}

float Client::totalPlata() {
    float total = 0;
    for (auto & produs : produse) {
        total += produs.getPret() * produs.getNumarProduse();
    }

    if(this->id == 'F') {
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
