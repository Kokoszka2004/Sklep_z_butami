#include "Transakcja.h"
#include <iostream>

// Konstruktor
Transakcja::Transakcja(const std::string& id, const Uzytkownik& uzytkownik, const std::vector<Produkt>& produkty, double cena, const std::string& data)
    : idTransakcji(id), uzytkownik(uzytkownik), listaProduktów(produkty), calkowitaCena(cena), dataTransakcji(data) {
}

// Finalizacja transakcji
void Transakcja::potwierdzTransakcje() {
    std::cout << "Transakcja " << idTransakcji << " zostala potwierdzona." << std::endl;
    std::cout << "Laczna kwota: " << calkowitaCena << " PLN" << std::endl;
}

// Anulowanie transakcji
void Transakcja::anulujTransakcje() {
    std::cout << "Transakcja " << idTransakcji << " zostala anulowana." << std::endl;
}

// Wyswietl szczegoly transakcji
void Transakcja::pokazSzczegoly() const {
    std::cout << "Szczegoly transakcji:\n";
    std::cout << "ID: " << idTransakcji << "\n";
    std::cout << "Data: " << dataTransakcji << "\n";
    std::cout << "Uzytkownik: " << uzytkownik.getNazwaUzytkownika() << "\n";
    std::cout << "Produkty:\n";
    for (const auto& produkt : listaProduktów) {
        std::cout << " - " << produkt.getNazwa() << " | Cena: " << produkt.getCena() << " PLN\n";
    }
    std::cout << "Laczna cena: " << calkowitaCena << " PLN\n";
}
