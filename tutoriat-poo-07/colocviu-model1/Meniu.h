#ifndef COLOCVIU_MODEL1_MENIU_H
#define COLOCVIU_MODEL1_MENIU_H

#include "Copil.h"

class Meniu {
private:
    static Meniu *instance;
    Meniu() = default;
    std::vector<std::shared_ptr<Copil>> copii;

public:
    static Meniu *getInstance();
    ~Meniu() = default;
    Meniu(const Meniu&) = default;
    Meniu& operator=(const Meniu&) = default;

    // functii
    void meniu();
    void adaugareCopii();
    void afisareCopii();
    void cautaCopil(const std::string& numeCopil);

};


#endif //COLOCVIU_MODEL1_MENIU_H
