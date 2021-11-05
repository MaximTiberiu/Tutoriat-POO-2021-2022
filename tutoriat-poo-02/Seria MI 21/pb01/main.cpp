#include <iostream>
#include <fstream>

class Fractie {
private:
    int numarator;
    int numitor;
    void simplifica();

public:
    Fractie(int _numarator = 0, int _numitor = 1);
    ~Fractie() = default;
    Fractie(const Fractie & fractie);

    void citire();
    void afisare();

    friend Fractie suma(const Fractie &f1, const Fractie &f2);
    friend Fractie produs(const Fractie &f1, const Fractie &f2);

    friend std::istream & operator >>(std::istream & in, Fractie & fractie);
    friend std::ostream & operator <<(std::ostream & out, const Fractie & fractie);
};

Fractie::Fractie(int _numarator, int _numitor) {
    this->numarator = _numarator;
    this->numitor = _numitor;
    simplifica();
}

Fractie::Fractie(const Fractie &fractie) {
    this->numarator = fractie.numarator;
    this->numitor = fractie.numitor;
}

void Fractie::citire() {
    std::cin >> numarator >> numitor;
    simplifica();
}

void Fractie::afisare() {
    std::cout << numarator << "/" << numitor << "\n";
}

void Fractie::simplifica() {
    int a = numarator, b = numitor;

    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }

    numarator /= a;
    numitor /= a;
}

Fractie suma(const Fractie &f1, const Fractie &f2) {
    int numarator = f1.numarator * f2.numitor + f2.numarator * f1.numitor;
    int numitor = f1.numitor * f2.numitor;
    Fractie res(numarator, numitor);
    return res;
}

Fractie produs(const Fractie &f1, const Fractie &f2) {
    int numarator = f1.numarator * f2.numarator;
    int numitor = f1.numitor * f2.numitor;
    Fractie res(numarator, numitor);
    return res;
}

std::istream &operator>>(std::istream &in, Fractie &fractie) {
    in >> fractie.numarator >> fractie.numitor;
    fractie.simplifica();
    return in;
}

std::ostream &operator<<(std::ostream &out, const Fractie &fractie) {
    out << fractie.numarator << "/" << fractie.numitor << "\n";
    return out;
}

int main() {
    Fractie f1(2, 6);
    Fractie f2(2, 4);
    Fractie sum = suma(f1, f2);
    Fractie prod = produs(f1, f2);
    sum.afisare();
    prod.afisare();

    Fractie f3;
    std::cin >> f3;
    std::cout << f3;
    return 0;
}
