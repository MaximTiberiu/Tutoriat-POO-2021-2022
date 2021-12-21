#ifndef MODEL_01_COPILCUMINTE_H
#define MODEL_01_COPILCUMINTE_H

#include "Copil.h"

class CopilCuminte : public Copil {
private:
    int numarDulciuri{};

public:
    CopilCuminte() = default;
    ~CopilCuminte() override = default;
    CopilCuminte(const std::string &_nume, const std::string &_prenume, const std::string &_adresa, unsigned int _varsta,
                 unsigned int _numarFapteBune, const std::vector<std::shared_ptr<Jucarie>> &_jucarii, int _numarDulciuri);
    CopilCuminte(const CopilCuminte&) =  default;
    CopilCuminte &operator=(const CopilCuminte&) = default;

    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
};


#endif //MODEL_01_COPILCUMINTE_H
