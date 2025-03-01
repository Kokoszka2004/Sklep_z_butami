#ifndef TRANSAKCJA_H
#define TRANSAKCJA_H

#include <string>
#include <vector>
#include "Produkt.h"
#include "Uzytkownik.h"
#include "Koszyk.h"  // Dodaj nagłówek koszyka

class Transakcja {
private:
    std::string idTransakcji;
    Uzytkownik uzytkownik;
    std::vector<Produkt> listaProduktow;
    double calkowitaCena;
    std::string dataTransakcji;
    Koszyk& koszyk;  // Referencja do koszyka

public:
    Transakcja(const std::string& id, const Uzytkownik& user, const std::vector<Produkt>& produkty, double cena, const std::string& data, Koszyk& koszyk);

    void potwierdzTransakcje();
    void anulujTransakcje();
    void pokazSzczegoly() const;
    void procesujPlatnosc();
};

#endif
