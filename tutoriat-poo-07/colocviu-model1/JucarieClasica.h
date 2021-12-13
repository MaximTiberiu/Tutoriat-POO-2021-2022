#ifndef COLOCVIU_MODEL1_JUCARIECLASICA_H
#define COLOCVIU_MODEL1_JUCARIECLASICA_H

#include "Jucarie.h"

class JucarieClasica : public Jucarie {
private:
    std::string material;
    std::string culoare;

public:
    JucarieClasica() = default;
    ~JucarieClasica() override = default;
    JucarieClasica(const std::string&, float, const std::string&, const std::string&, const std::string&);
    JucarieClasica(const JucarieClasica&) = default;
    JucarieClasica & operator=(const JucarieClasica&) = default;

    void read(std::istream&) override;
    void print(std::ostream&) const override;
};

#endif //COLOCVIU_MODEL1_JUCARIECLASICA_H
