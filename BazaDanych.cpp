#include "BazaDanych.h"
#include <iostream>

// Implementacje metod (na razie proste szkielety)
bool BazaDanych::sprawdzDostepnoscNazwy(const std::string& nazwa) const {
    std::cout << "Sprawdzanie dostepnosci nazwy: " << nazwa << std::endl;
    return true; // Na razie zawsze zwraca true
}

void BazaDanych::zapiszKonto(const Konto& konto) {
    std::cout << "Zapisano konto: " << konto.getNazwaUzytkownika() << std::endl;
}

Konto BazaDanych::stworzKonto(const std::string& nazwa, const std::string& haslo, const std::string& email) {
    return Konto(nazwa, haslo, email);
}

bool BazaDanych::sprawdzDaneLogowania(const std::string& nazwa, const std::string& haslo) const {
    std::cout << "Sprawdzanie danych logowania: " << nazwa << std::endl;
    return true; // Na razie zawsze zwraca true
}

void BazaDanych::zapiszProdukt(const Produkt& produkt) {
    std::cout << "Zapisano produkt: " << produkt.getNazwa() << std::endl;
}
