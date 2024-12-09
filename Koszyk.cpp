#include "Koszyk.h"
#include <iostream>

// Dodaj produkt do koszyka
void Koszyk::dodajDoKoszyka(const Produkt& produkt) {
    listaProduktow.push_back(produkt);
}

// Usun produkt z koszyka po ID
void Koszyk::usunZKoszyka(const std::string& idProduktu) {
    for (auto it = listaProduktow.begin(); it != listaProduktow.end(); ++it) {
        if (it->getId() == idProduktu) {
            listaProduktow.erase(it);
            break;
        }
    }
}

// Wyczysc koszyk
void Koszyk::wyczyscKoszyk() {
    listaProduktow.clear();
}

// Wyswietl produkty w koszyku
void Koszyk::pokazZawartosc() const {
    std::cout << "Zawartosc koszyka:\n";
    for (const auto& produkt : listaProduktow) {
        std::cout << " - " << produkt.getNazwa() << " | Cena: " << produkt.getCena() << " PLN\n";
    }
    if (listaProduktow.empty()) {
        std::cout << "Koszyk jest pusty.\n";
    }
}
