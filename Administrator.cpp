#include "Administrator.h"
#include <iostream>

// Konstruktor
Administrator::Administrator(const std::string& poziom) : poziomUprawnien(poziom) {}

// Dodaj nowy produkt
void Administrator::dodajNowyProdukt(Produkt& produkt) {
    std::cout << "Dodano nowy produkt: " << produkt.getNazwa() << std::endl;
}

// Zmien cene produktu
void Administrator::zmienCeneProduktu(Produkt& produkt, double nowaCena) {
    produkt.ustawNowaCene(nowaCena);
    std::cout << "Zmieniono cene produktu na: " << nowaCena << " PLN" << std::endl;
}

// Przegladaj transakcje
void Administrator::przegladajTransakcje(const std::vector<Transakcja>& listaTransakcji) const {
    std::cout << "Lista transakcji:" << std::endl;
    for (const auto& transakcja : listaTransakcji) {
        transakcja.pokazSzczegoly();
    }
}
