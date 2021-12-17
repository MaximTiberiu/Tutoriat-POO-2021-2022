#ifndef MODEL_01_JUCARIE_H
#define MODEL_01_JUCARIE_H

#include <iostream>

class Jucarie {
protected:
    std::string denumire;
    float dimensiune{};
    std::string tip;

public:
    Jucarie() = default;
    virtual ~Jucarie() = default;
    Jucarie(const std::string &_denumire, float _dimensiune, const std::string &_tip);
    Jucarie(const Jucarie&) = default;
    Jucarie &operator=(const Jucarie&) = default;

    friend std::istream& operator>>(std::istream& in, Jucarie& jucarie);
    friend std::ostream& operator<<(std::ostream& out, const Jucarie& jucarie);

    virtual void read(std::istream& in);
    virtual void print(std::ostream& out) const;
};


#endif //MODEL_01_JUCARIE_H
