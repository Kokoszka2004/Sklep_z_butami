#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "Produkt.h"
#include "Transakcja.h"

class Administrator {
private:
    std::string poziomUprawnien; // Poziom uprawnien administratora

public:
    // Konstruktor
    Administrator(const std::string& poziom);

    // Zarzadzanie produktami
    void dodajNowyProdukt(Produkt& produkt);
    void zmienCeneProduktu(Produkt& produkt, double nowaCena);

    // Przegladanie transakcji
    void przegladajTransakcje(const std::vector<Transakcja>& listaTransakcji) const;
};

#endif

