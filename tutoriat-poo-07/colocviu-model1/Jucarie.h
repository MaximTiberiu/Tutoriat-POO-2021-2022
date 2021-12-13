#ifndef COLOCVIU_MODEL1_JUCARIE_H
#define COLOCVIU_MODEL1_JUCARIE_H

#include <iostream>

class Jucarie {
protected:
    std::string denumire;
    float dimensiune{};
    std::string tip;

public:
    Jucarie() = default;
    virtual ~Jucarie() = default;

    Jucarie(const std::string&, float, const std::string&);
    Jucarie(const Jucarie&) = default;
    Jucarie & operator=(const Jucarie&) = default;

    friend std::istream& operator>>(std::istream&, Jucarie&);
    friend std::ostream& operator<<(std::ostream&, const Jucarie&);

    virtual void read(std::istream&);
    virtual void print(std::ostream&) const;

};

#endif //COLOCVIU_MODEL1_JUCARIE_H
