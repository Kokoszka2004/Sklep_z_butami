#ifndef KOSZYK_H
#define KOSZYK_H

#include <vector>
#include "Produkt.h"

class Koszyk {
private:
    std::vector<Produkt> listaProduktow;  // Lista produktów w koszyku

public:
    void dodajDoKoszyka(Produkt& produkt, int ilosc);
    void usunZKoszyka(int index);  // Usuwa produkt z koszyka na podstawie indeksu
    void wyczyscKoszyk();         // Usuwa wszystkie produkty z koszyka
    void pokazZawartosc() const;  // Wyœwietla zawartoœæ koszyka
    double obliczCalkowitaCene() const;  // Oblicza ca³kowit¹ cenê koszyka
    int ileProduktow() const;     // Zwraca liczbê produktów w koszyku
};

#endif
