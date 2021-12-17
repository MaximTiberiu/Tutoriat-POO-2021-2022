#ifndef MODEL_01_JUCARIEMODERNA_H
#define MODEL_01_JUCARIEMODERNA_H

#include "JucarieEducativa.h"
#include "JucarieElectronica.h"

class JucarieModerna : public JucarieEducativa, public JucarieElectronica {
private:
    std::string brand;
    std::string model;

public:
    JucarieModerna() = default;
    ~JucarieModerna() override = default;
    JucarieModerna(const std::string &_denumire, float _dimensiune, const std::string &_tip, const std::string &_brand,
                   const std::string &_model);
    JucarieModerna(const JucarieModerna&) = default;
    JucarieModerna &operator=(const JucarieModerna&) = default;

    void read(std::istream &in) override;
    void print(std::ostream &out) const override;
};


#endif //MODEL_01_JUCARIEMODERNA_H
