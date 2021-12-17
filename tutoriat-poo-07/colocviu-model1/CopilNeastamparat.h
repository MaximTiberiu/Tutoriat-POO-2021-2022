#ifndef COLOCVIU_MODEL1_COPILNEASTAMPARAT_H
#define COLOCVIU_MODEL1_COPILNEASTAMPARAT_H

#include "Copil.h"

class CopilNeastamparat : public Copil {
private:
    int numarCarbuni{};

public:
    CopilNeastamparat() = default;
    ~CopilNeastamparat() override = default;
    CopilNeastamparat(const std::string&, const std::string&, const std::string&, int, int, const std::vector<std::shared_ptr<Jucarie>>&, int);
    CopilNeastamparat(const CopilNeastamparat&) = default;
    CopilNeastamparat & operator=(const CopilNeastamparat&) =default;

    void read(std::istream&) override;
    void print(std::ostream&) const override;
};


#endif //COLOCVIU_MODEL1_COPILNEASTAMPARAT_H
