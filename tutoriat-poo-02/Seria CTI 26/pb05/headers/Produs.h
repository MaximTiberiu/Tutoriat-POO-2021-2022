#ifndef P05_PRODUS_H
#define P05_PRODUS_H

#include <string>

class Produs {
private:
    std::string denumire;
    float pret;
    int numar_produse;

public:
    Produs() = default;
    Produs(std::string _denumire, float _pret, int _numar_produse);
    ~Produs() = default;

    const std::string &getDenumire() const;
    void setDenumire(const std::string &denumire);

    float getPret() const;
    void setPret(float pret);

    int getNumarProduse() const;
    void setNumarProduse(int numarProduse);

//    friend std::ostream & operator <<(std::ostream & out, const Produs &produs);
};

#endif //P05_PRODUS_H
