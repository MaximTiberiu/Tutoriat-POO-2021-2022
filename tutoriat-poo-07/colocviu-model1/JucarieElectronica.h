#ifndef COLOCVIU_MODEL1_JUCARIEELECTRONICA_H
#define COLOCVIU_MODEL1_JUCARIEELECTRONICA_H

#include "Jucarie.h"

class JucarieElectronica : virtual public Jucarie {
protected:
    int numarBaterii{};

public:
    JucarieElectronica() = default;
    ~JucarieElectronica() override = default;
    JucarieElectronica(const std::string&, float, const std::string&, int);
    JucarieElectronica(const JucarieElectronica&) = default;
    JucarieElectronica & operator=(const JucarieElectronica&) = default;

    void read(std::istream&) override;
    void print(std::ostream&) const override;

};
#endif //COLOCVIU_MODEL1_JUCARIEELECTRONICA_H
