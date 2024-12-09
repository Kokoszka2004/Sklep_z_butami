#ifndef KOSZYK_H
#define KOSZYK_H

#include <vector>
#include "Produkt.h"

class Koszyk {
private:
    std::vector<Produkt> listaProduktow;  // Lista produktow w koszyku

public:
    // Dodaj produkt do koszyka
    void dodajDoKoszyka(const Produkt& produkt);

    // Usun produkt z koszyka
    void usunZKoszyka(const std::string& idProduktu);

    // Wyczysc koszyk
    void wyczyscKoszyk();

    // Wyswietl produkty w koszyku
    void pokazZawartosc() const;
};

#endif

