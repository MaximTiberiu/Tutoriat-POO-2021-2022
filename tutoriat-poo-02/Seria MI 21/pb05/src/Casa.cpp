#include <iostream>
#include "../headers/Casa.h"

Casa::Casa(int numarCasa, const std::vector<Client> &clienti) {
    this->numarCasa = numarCasa;
    this->clienti = clienti;
}

void Casa::serveste() {
    for (int i = 0 ; i < clienti.size() ; i++) {
        if(clienti[i].totalPlata() != -1) {
            std::cout << "Achitat!\n";
//            clienti.erase(clienti.begin() + i);
        } else {
            std::cout << "Nu se poate face plata!\n";
        }
    }
}
