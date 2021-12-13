#ifndef COLOCVIU_MODEL1_JUCARIEMODERNA_H
#define COLOCVIU_MODEL1_JUCARIEMODERNA_H

#include "JucarieEducativa.h"
#include "JucarieElectronica.h"

class JucarieModerna : public JucarieEducativa, public JucarieElectronica {
private:
    std::string brand;
    std::string model;

public:
    JucarieModerna() = default;
    ~JucarieModerna() override = default;
    JucarieModerna(const std::string&, float, const std::string&, const std::string&, const std::string&);
    JucarieModerna(const JucarieModerna&) = default;
    JucarieModerna & operator=(const JucarieModerna&) = default;

    void read(std::istream&) override;
    void print(std::ostream&) const override;
};


#endif //COLOCVIU_MODEL1_JUCARIEMODERNA_H
