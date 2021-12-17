#ifndef MODEL_01_JUCARIEEDUCATIVA_H
#define MODEL_01_JUCARIEEDUCATIVA_H

#include "Jucarie.h"

class JucarieEducativa : virtual public Jucarie {
protected:
    std::string abilitate;

public:
    JucarieEducativa() = default;
    ~JucarieEducativa() override = default;
    JucarieEducativa(const std::string &_denumire, float _dimensiune, const std::string &_tip, const std::string &_abilitate);
    JucarieEducativa(const JucarieEducativa&) = default;
    JucarieEducativa & operator=(const JucarieEducativa&) = default;

    void read (std::istream& in) override;
    void print(std::ostream& out) const override;
};


#endif //MODEL_01_JUCARIEEDUCATIVA_H
