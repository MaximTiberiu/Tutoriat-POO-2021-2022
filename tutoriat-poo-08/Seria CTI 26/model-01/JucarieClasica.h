#ifndef MODEL_01_JUCARIECLASICA_H
#define MODEL_01_JUCARIECLASICA_H

#include "Jucarie.h"

class JucarieClasica : public Jucarie {
private:
    std::string material;
    std::string culoare;

public:
    JucarieClasica() = default;
    ~JucarieClasica() override = default;
    JucarieClasica(const std::string &_denumire, float _dimensiune, const std::string &_tip,
                   const std::string &_material, const std::string &_culoare);
    JucarieClasica(const JucarieClasica&) = default;
    JucarieClasica & operator=(const JucarieClasica&) = default;

    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
};


#endif //MODEL_01_JUCARIECLASICA_H
