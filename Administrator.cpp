#include "Administrator.h"
#include <iostream>

Administrator::Administrator(const std::string& poziom) : poziomUprawnien(poziom) {}

void Administrator::dodajNowyProdukt(Produkt& produkt) {
    std::cout << "Dodano nowy produkt: " << produkt.getNazwa() << std::endl;
}

void Administrator::zmienCeneProduktu(Produkt& produkt, double nowaCena) {
    produkt.ustawNowaCene(nowaCena);  // Poprawne wywo³anie metody ustawNowaCene
    std::cout << "Zmieniono cene produktu na: " << nowaCena << " PLN" << std::endl;
}
