#include "Meniu.h"

int main() {
    Meniu *meniu = Meniu::getInstance();
    meniu->adaugareCopii();
    meniu->cautaCopil("Popa");
    return 0;
}
