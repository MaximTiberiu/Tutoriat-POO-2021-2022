#ifndef PB02_03_DREPTUNGHI_H
#define PB02_03_DREPTUNGHI_H

#include "Punct.h"

class Dreptunghi {
private:
    Punct p1;
    Punct p2;

public:
    Dreptunghi();
    Dreptunghi(int x_p1, int y_p1, int x_p2, int y_p2);
    Dreptunghi(Punct p1, Punct p2);
    ~Dreptunghi() = default;

    const Punct &getP1() const;
    void setP1(const Punct &p1);

    const Punct &getP2() const;
    void setP2(const Punct &p2);

    friend double arie(const Dreptunghi& dreptunghi);
};

#endif //PB02_03_DREPTUNGHI_H
