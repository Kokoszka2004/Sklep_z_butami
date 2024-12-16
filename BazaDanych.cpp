#include "BazaDanych.h"
#include <iostream>
#include <fstream>

// Konstruktor
BazaDanych::BazaDanych() {
    inicjalizujProdukty(); // Dodanie domy?lnych produktów
    wczytajKontaZPliku();
}

// Inicjalizuje przyk?adowe produkty
void BazaDanych::inicjalizujProdukty() {
    dodajProdukt(Produkt("P001", "Laptop", "Nowy model laptopa", 3500.0, 10, 1));
    dodajProdukt(Produkt("P002", "Smartfon", "Najnowszy smartfon", 2500.0, 15, 1));
    dodajProdukt(Produkt("P003", "Sluchawki", "Wysokiej jakosci sluchawki", 150.0, 20, 1));
    std::cout << "Produkty zostaly zainicjalizowane.\n";
}

// Dodaje produkt do bazy
void BazaDanych::dodajProdukt(const Produkt& produkt) {
    produkty.push_back(produkt);
}

// Pobiera nowo?ci
std::vector<Produkt> BazaDanych::pobierzNowosci() const {
    std::vector<Produkt> nowosci;
    for (size_t i = 0; i < produkty.size() && i < 2; ++i) {
        nowosci.push_back(produkty[i]);
    }
    return nowosci;
}

// Pobiera promocje
std::vector<Produkt> BazaDanych::pobierzPromocje() const {
    std::vector<Produkt> promocje;
    for (const auto& produkt : produkty) {
        if (produkt.getCena() < 2000) {
            promocje.push_back(produkt);
        }
    }
    return promocje;
}

// Wyszukuje produkt po nazwie
Produkt BazaDanych::wyszukajProdukt(const std::string& nazwa) const {
    for (const auto& produkt : produkty) {
        if (produkt.getNazwa() == nazwa) {
            return produkt;
        }
    }
    return Produkt("", "Nie znaleziono", "", 0.0, 0, 0);
}


// Wczytuje konta z pliku
void BazaDanych::wczytajKontaZPliku() {
    std::ifstream plik(plikKonta);
    if (!plik) {
        std::cerr << "Nie znaleziono pliku z kontami. Tworzenie nowego.\n";
        return;
    }

    std::string nazwa, haslo;
    while (plik >> nazwa >> haslo) {
        konta.emplace_back(nazwa, haslo);
    }
    plik.close();
    std::cout << "Wczytano " << konta.size() << " kont z pliku.\n";
}

// Zapisuje konta do pliku
void BazaDanych::zapiszKontaDoPliku() const {
    std::ofstream plik(plikKonta);
    if (!plik) {
        std::cerr << "Nie mozna otworzyc pliku do zapisu.\n";
        return;
    }

    for (const auto& konto : konta) {
        plik << konto.first << " " << konto.second << "\n";
    }
    plik.close();
}

// Dodaje nowe konto
void BazaDanych::dodajKonto(const std::string& nazwa, const std::string& haslo) {
    konta.emplace_back(nazwa, haslo);
    zapiszKontaDoPliku(); // Aktualizujemy plik
    std::cout << "Dodano konto: " << nazwa << "\n";
}

// Weryfikuje dane logowania
bool BazaDanych::weryfikujKonto(const std::string& nazwa, const std::string& haslo) const {
    for (const auto& konto : konta) {
        if (konto.first == nazwa && konto.second == haslo) {
            return true;
        }
    }
    return false;
}

// Sprawdza, czy nazwa u?ytkownika jest zaj?ta
bool BazaDanych::czyNazwaZajeta(const std::string& nazwa) const {
    for (const auto& konto : konta) {
        if (konto.first == nazwa) {
            return true;
        }
    }
    return false;
}