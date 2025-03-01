#ifndef KOSZYK_H
#define KOSZYK_H

#include <vector>
#include "Produkt.h"

class Koszyk {
private:
    std::vector<Produkt> listaProduktow;  // Lista produkt�w w koszyku

public:
    void dodajDoKoszyka(Produkt& produkt, int ilosc);
    void usunZKoszyka(int index);  // Usuwa produkt z koszyka na podstawie indeksu
    void wyczyscKoszyk();         // Usuwa wszystkie produkty z koszyka
    void pokazZawartosc() const;  // Wy�wietla zawarto�� koszyka
    double obliczCalkowitaCene() const;  // Oblicza ca�kowit� cen� koszyka
    int ileProduktow() const;     // Zwraca liczb� produkt�w w koszyku
};

#endif
