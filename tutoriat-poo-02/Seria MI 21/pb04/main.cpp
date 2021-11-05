#include <iostream>

class Complex {
private:
    float re;
    float img;

public:
    Complex();
    Complex(float _re, float _img);

    void afisare();

    Complex operator+(const Complex & c);
    Complex operator*(const Complex & c);
};

Complex::Complex() {
    this->re = 0;
    this->img = 0;
}

Complex::Complex(float _re, float _img) {
    this->re = _re;
    this->img = _img;
}

void Complex::afisare() {
    std::cout << re;
    if (img >= 0) {
        std::cout << "+" << img << "i\n";
    } else {
        std::cout << img << "i\n";
    }
}

Complex Complex::operator+(const Complex &c) {
    Complex sum;
    sum.re = re + c.re;
    sum.img = img + c.img;
    return sum;
}

Complex Complex::operator*(const Complex &c) {
    Complex prod;
    prod.re = re * c.re - img *  c.img;
    prod.img = c.re * img + c.img * re;
    return prod;
}

int main() {
    Complex c1(1, 2);
    Complex c2(1, 2);
    Complex sum = c1 + c2;
    Complex prod = c1 * c2;
    sum.afisare();
    prod.afisare();
    return 0;
}
