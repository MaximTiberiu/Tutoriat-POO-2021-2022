#ifndef MODEL_01_MENIU_H
#define MODEL_01_MENIU_H

#include "Copil.h"

class Meniu {
private:
    static Meniu* instance;
    Meniu() = default;
    std::vector<std::shared_ptr<Copil>> copii;
public:
    ~Meniu() = default;
    static Meniu* getInstance();

    // functii
    static void meniu();
    void adaugareCopii();
    void afisareCopii();
    void cautaCopil(const std::string& numeCopil);
    void ordonareVarsta();
    void ordonareFapteBune();
    void adaugareFapteBune(int idCopil, int numarFapteBune);
    void raportJucarii();
};


#endif //MODEL_01_MENIU_H
