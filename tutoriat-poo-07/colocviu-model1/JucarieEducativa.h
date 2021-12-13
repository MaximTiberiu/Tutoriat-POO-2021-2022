#ifndef COLOCVIU_MODEL1_JUCARIEEDUCATIVA_H
#define COLOCVIU_MODEL1_JUCARIEEDUCATIVA_H

#include "Jucarie.h"

class JucarieEducativa : virtual public Jucarie {
protected:
    std::string abilitate;

public:
    JucarieEducativa() = default;
    ~JucarieEducativa() override = default;
    JucarieEducativa(const std::string&, float, const std::string&, const std::string&);
    JucarieEducativa(const JucarieEducativa&) = default;
    JucarieEducativa & operator=(const JucarieEducativa&) = default;

    void read(std::istream&) override;
    void print(std::ostream&) const override;
};

#endif //COLOCVIU_MODEL1_JUCARIEEDUCATIVA_H
