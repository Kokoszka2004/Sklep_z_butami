#include "Koszyk.h"
#include <iostream>

void Koszyk::dodajDoKoszyka(Produkt& produkt, int ilosc) {
    float rozmiar;
    std::cout << "Podaj rozmiar produktu: ";
    std::cin >> rozmiar;
    if (rozmiar < 32 || rozmiar > 52) {
        std::cout << "Podano nieprawidlowy rozmiar" << std::endl;
        
    }
    else {
        produkt.ustawRozmiar(rozmiar);
        listaProduktow.push_back(produkt);
        std::cout << "Dodano produkt do koszyka: " << produkt.getNazwa() << " | Rozmiar: " << rozmiar << "\n";
    }
}

void Koszyk::usunZKoszyka(int index) {
    if (index >= 0 && index < listaProduktow.size()) {
        listaProduktow.erase(listaProduktow.begin() + index);
        std::cout << "Produkt usuniety z koszyka.\n";
    }
    else {
        std::cout << "Nieprawidlowy indeks produktu.\n";
    }
}

void Koszyk::wyczyscKoszyk() {
    listaProduktow.clear();
    std::cout << "Koszyk zostal oprozniony.\n";
}

void Koszyk::pokazZawartosc() const {
    if (listaProduktow.empty()) {
        std::cout << "Koszyk jest pusty.\n";
    }
    else {
        std::cout << "Zawartosc koszyka:\n";
        int index = 1;
        for (const auto& produkt : listaProduktow) {
            std::cout << index++ << ". " << produkt.getNazwa() << " | Cena: " << produkt.getCena()
                << " PLN | Rozmiar: " << produkt.getRozmiar() << "\n";
        }
    }
}

double Koszyk::obliczCalkowitaCene() const {
    double suma = 0.0;
    for (const auto& produkt : listaProduktow) {
        suma += produkt.getCena();
    }
    return suma;
}

int Koszyk::ileProduktow() const {
    return listaProduktow.size();
}
