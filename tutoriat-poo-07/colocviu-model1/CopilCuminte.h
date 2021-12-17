#ifndef COLOCVIU_MODEL1_COPILCUMINTE_H
#define COLOCVIU_MODEL1_COPILCUMINTE_H

#include "Copil.h"

class CopilCuminte : public Copil {
private:
    int numarDulciuri{};

public:
    CopilCuminte() = default;
    ~CopilCuminte() override = default;
    CopilCuminte(const std::string&, const std::string&, const std::string&, int, int, const std::vector<std::shared_ptr<Jucarie>>&, int);
    CopilCuminte(const CopilCuminte&) = default;
    CopilCuminte & operator=(const CopilCuminte&) =default;

    void read(std::istream&) override;
    void print(std::ostream&) const override;
};


#endif //COLOCVIU_MODEL1_COPILCUMINTE_H
