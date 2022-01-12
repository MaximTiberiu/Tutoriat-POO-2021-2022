#include "Companie.h"

Companie::Companie(const std::string &_denumireCompanie, int _anInfiintare, const std::string &_sediu,
                   const std::string &_codICAO, const std::string &_codIATA,
                   const std::vector<std::string> &_destinatii, const std::vector<std::shared_ptr<Zbor>> &_zboruri) {
    this->denumireCompanie = _denumireCompanie;
    this->anInfiintare = _anInfiintare;
    this->sediu = _sediu;
    this->codICAO = _codICAO;
    this->codIATA = _codIATA;
    this->destinatii = _destinatii;
    this->zboruri = _zboruri;
}

void Companie::setTipCompanie(const std::string &_tipCompanie) {
    Companie::tipCompanie = _tipCompanie;
}

void Companie::read(std::istream &in) {
    std::cout << "Denumire companie: ";
    in >> denumireCompanie;

    std::cout << "An infiintare: ";
    in >> anInfiintare;

    std::cout << "Cod ICAO: ";
    in >> codICAO;

    std::cout << "Cod IATA: ";
    in >> codIATA;

    std::cout << "****Destinatii****\n";
    std::cout << "Numar destinatii: ";
    int nrDestinatii;
    in >> nrDestinatii;

    for (int i = 0 ; i < nrDestinatii ; i++) {
        std::string tempDestinatie;
        std::cout << "Destinatia #" << i + 1 << ": ";
        in >> tempDestinatie;
        destinatii.push_back(tempDestinatie);
    }

    int optiuneCompanie, conditieCitire = 0;
    while (conditieCitire == 0) {
        std::cout << "Tip Companie (1: Low-Cost; 2: de Linie): ";
        in >> optiuneCompanie;
        conditieCitire = 1;
        try {
            if (optiuneCompanie < 1 || optiuneCompanie > 2) {
                throw  optiuneCompanie;
            }
            switch (optiuneCompanie) {
                case 1: {
                    tipCompanie = "low-cost";
                    break;
                }
                case 2: {
                    tipCompanie = "linie";
                    break;
                }
            }
        } catch (...) {
            std::cout << "Eroare citire tip companie!\n";
            conditieCitire = 0;
        }
    }

    // zboruri

}

void Companie::print(std::ostream &out) const {
    out << "Denumire companie: " << denumireCompanie << "\n";
    out << "An infiintare: " << anInfiintare << "\n";
    out << "Cod ICAO: " << codICAO << "\n";
    out << "Cod IATA: " << codIATA << "\n";
    out << "Tip Companie: " << tipCompanie << "\n";
    out << "Destinatii:\n";
    for (auto & destinatie : destinatii) {
        out << destinatie << "\n";
    }
    out << "Zboruri:\n";
    for(auto & zbor : zboruri) {
//        zbor->print(out);
    }
}

std::istream &operator>>(std::istream &in, Companie &companie) {
    companie.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Companie &companie) {
    companie.print(out);
    return out;
}
