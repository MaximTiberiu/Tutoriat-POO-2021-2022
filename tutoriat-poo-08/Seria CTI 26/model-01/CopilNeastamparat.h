#ifndef MODEL_01_COPILNEASTAMPARAT_H
#define MODEL_01_COPILNEASTAMPARAT_H

#include "Copil.h"

class CopilNeastamparat : public Copil {
private:
    int numarCarbuni{};

public:
    CopilNeastamparat() = default;
    ~CopilNeastamparat() override = default;
    CopilNeastamparat(const std::string &_nume, const std::string &_prenume, const std::string &_adresa, unsigned int _varsta,
                 unsigned int _numarFapteBune, const std::vector<std::shared_ptr<Jucarie>> &_jucarii, int _numarCarbuni);
    CopilNeastamparat(const CopilNeastamparat&) =  default;
    CopilNeastamparat &operator=(const CopilNeastamparat&) = default;

    void read(std::istream& in) override;
    void print(std::ostream& out) const override;
};


#endif //MODEL_01_COPILNEASTAMPARAT_H
