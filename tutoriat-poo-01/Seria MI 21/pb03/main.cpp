#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

class Punct {
private:
    int abscisa;
    int ordonata;

public:
    Punct();
    Punct(int _abcisa, int _ordonata);
    ~Punct() = default;

    int getAbscisa() const;
    void setAbscisa(int abscisa);

    int getOrdonata() const;
    void setOrdonata(int ordonata);
};

Punct::Punct(int _abcisa, int _ordonata) {
    this->abscisa = _abcisa;
    this->ordonata = _ordonata;
}

int Punct::getAbscisa() const {
    return abscisa;
}

void Punct::setAbscisa(int _abscisa) {
    Punct::abscisa = _abscisa;
}

int Punct::getOrdonata() const {
    return ordonata;
}

void Punct::setOrdonata(int _ordonata) {
    Punct::ordonata = _ordonata;
}

class Dreptunghi {
private:
    Punct punct_1;
    Punct punct_2;

public:
    Dreptunghi() = default;
    Dreptunghi(int x_p1, int y_p1, int x_p2, int y_p2);
    Dreptunghi(Punct p1, Punct p2);
    ~Dreptunghi() = default;

    const Punct &getPunct1() const;
    void setPunct1(const Punct &punct1);

    const Punct &getPunct2() const;
    void setPunct2(const Punct &punct2);

    friend double arie(const Dreptunghi& dreptunghi);
};

//Dreptunghi::Dreptunghi() {
//    this->punct_1.setAbscisa(0);
//    this->punct_1.setOrdonata(0);
//
//    this->punct_2.setAbscisa(0);
//    this->punct_2.setOrdonata(0);
//}

Dreptunghi::Dreptunghi(int x_p1, int y_p1, int x_p2, int y_p2) {
    this->punct_1.setAbscisa(x_p1);
    this->punct_1.setOrdonata(y_p1);

    this->punct_2.setAbscisa(x_p2);
    this->punct_2.setOrdonata(y_p2);
}



const Punct &Dreptunghi::getPunct1() const {
    return punct_1;
}

void Dreptunghi::setPunct1(const Punct &punct1) {
    punct_1 = punct1;
}

const Punct &Dreptunghi::getPunct2() const {
    return punct_2;
}

void Dreptunghi::setPunct2(const Punct &punct2) {
    punct_2 = punct2;
}

double arie(const Dreptunghi &dreptunghi) {
    /*
     *  (x_p1, y_p2)                    (x_p2, y_p2)
     *
     *  (x_p1, y_p1)                    (x_p2, y_p1)
     */
    int x_p1 = dreptunghi.punct_1.getAbscisa();
    int y_p1 = dreptunghi.punct_1.getOrdonata();

    int x_p2 = dreptunghi.punct_2.getAbscisa();
    int y_p2 = dreptunghi.punct_2.getOrdonata();
    double L = std::sqrt(std::pow(x_p2 - x_p1, 2));
    double l = std::sqrt(std::pow(y_p2 - y_p1, 2));
    return L * l;
}

Dreptunghi::Dreptunghi(Punct p1, Punct p2) {
    this->punct_1 = p1;
    this->punct_2 = p2;
}

Punct::Punct() {
    abscisa = 0;
    ordonata = 0;
}

int main() {
    Punct p1(1, 2);
    Punct p2(5, -2);
    Dreptunghi dreptunghi(p1, p2);
    Dreptunghi d(1, 1, 2, 3);
    std::cout << arie(dreptunghi);

    std::vector<int> preturi;
    std::vector<std::string> denumire_produs;

    std::ifstream fin;
    fin.open("D:\\TUTORIATE 2020-2021\\SEMESTRUL 1\\Tutoriat POO - Seriile 21 & 26\\Tutoriat-POO-2021-2022\\tutoriat-poo-01\\Seria MI\\pb03\\data.txt", std::ios::in);

    int pret;
    std::string denumire;
    if(!fin)
        std::cerr << "Can't open :(\n";

    while(fin >> pret >> denumire) {
        std::cout << pret << " " << denumire << "\n";
        preturi.push_back(pret);
        denumire_produs.push_back(denumire);
    }

    for (auto & pret : preturi) {
        std::cout << pret << " ";
    }
    std::cout << "\n";
    for (auto & denumire : denumire_produs) {
        std::cout << denumire << " ";
    }

    fin.close();

}
