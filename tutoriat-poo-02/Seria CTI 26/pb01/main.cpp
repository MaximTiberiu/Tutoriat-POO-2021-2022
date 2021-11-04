#include <iostream>

class Fractie {
private:
    int numarator;
    int numitor;
    void simplifica();

public:
    Fractie(int _numarator = 0, int _numitor = 1);
    Fractie(const Fractie& fractie);
    ~Fractie() = default;
    void citire();
    void afisare();

    friend Fractie suma(const Fractie& f1, const Fractie& f2);
    friend Fractie produs(const Fractie& f1, const Fractie& f2);

    friend std::istream  & operator >>(std::istream & in, Fractie & fractie);
    friend std::ostream  & operator <<(std::ostream & out, Fractie & fractie);
};

Fractie::Fractie(int _numarator, int _numitor) {
    this->numarator = _numarator;
    this->numitor = _numitor;
    simplifica();
}

Fractie::Fractie(const Fractie &fractie) {
    this->numarator = fractie.numarator;
    this->numitor = fractie.numitor;
    simplifica();
}

void Fractie::citire() {
    std::cin >> numarator >> numitor;
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
    Fractie rezultat(numarator, numitor);
    return rezultat;
}

Fractie produs(const Fractie &f1, const Fractie &f2) {
    int numarator = f1.numarator * f2.numarator;
    int numitor = f1.numitor * f2.numitor;
    Fractie rezultat(numarator, numitor);
    return rezultat;
}

std::istream  & operator >>(std::istream & in, Fractie & fractie) {
    in >> fractie.numarator >> fractie.numitor;
    return in;
}

std::ostream  & operator <<(std::ostream & out, Fractie & fractie) {
    out << fractie.numarator << "/" << fractie.numitor << "\n";
    return out;
}

int main() {
    Fractie f(1, 2);
    Fractie g(1, 3);

    Fractie sum = suma(f, g);
    Fractie prod = produs(f, g);
    sum.afisare();
    std::cout << prod;
    return 0;
}
