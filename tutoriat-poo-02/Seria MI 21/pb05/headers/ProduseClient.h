#ifndef PB05_PRODUSECLIENT_H
#define PB05_PRODUSECLIENT_H

#include "Produs.h"

class ProduseClient : public Produs {
private:
    int numarProduse;

public:
    ProduseClient(const std::string &denumire, float pret, int numarProduse);

    int getNumarProduse() const;
    void setNumarProduse(int numarProduse);
};

#endif //PB05_PRODUSECLIENT_H
