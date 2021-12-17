
#ifndef MODEL_01_JUCARIEELECTRONICA_H
#define MODEL_01_JUCARIEELECTRONICA_H

#include "Jucarie.h"

class JucarieElectronica : virtual public Jucarie {
protected:
    int numarBaterii{};

public:
    JucarieElectronica() = default;
    ~JucarieElectronica() override = default;
    JucarieElectronica(const std::string &_denumire, float _dimensiune, const std::string &_tip, int _numarBaterii);
    JucarieElectronica(const JucarieElectronica&) = default;
    JucarieElectronica & operator=(const JucarieElectronica&) = default;

    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
};


#endif //MODEL_01_JUCARIEELECTRONICA_H
