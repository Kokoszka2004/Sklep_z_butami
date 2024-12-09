#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include <string>
#include <vector>
#include "Produkt.h"

class Zamowienie {
private:
    std::string idZamowienia;
    std::vector<Produkt> listaProduktow;
    std::string statusZamowienia;

public:
    Zamowienie(const std::string& id, const std::vector<Produkt>& produkty, const std::string& status);
    void finalizujZamowienie();
    void edytujZamowienie();
};

#endif

