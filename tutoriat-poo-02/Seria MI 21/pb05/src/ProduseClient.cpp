//
// Created by Tiberiu on 11/12/2021.
//

#include "../headers/ProduseClient.h"

ProduseClient::ProduseClient(const std::string &denumire, float pret, int numarProduse) : Produs(denumire, pret),
                                                                                          numarProduse(numarProduse) {}

int ProduseClient::getNumarProduse() const {
    return numarProduse;
}

void ProduseClient::setNumarProduse(int numarProduse) {
    ProduseClient::numarProduse = numarProduse;
}
