#ifndef P05_PRODUS_H
#define P05_PRODUS_H

#include <string>

class Produs {
private:
    std::string denumire;
    float pret;

public:
    Produs() = default;
    Produs(std::string _denumire, float _pret);
    ~Produs() = default;

    const std::string &getDenumire() const;

    void setDenumire(const std::string &denumire);

    float getPret() const;

    void setPret(float pret);
};

#endif //P05_PRODUS_H
