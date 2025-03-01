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
    dodajProdukt(Produkt("P001", "Nike Air Force 1", "Biale, klasyczne buty. Sportowe oraz na codzien.", 550.0, 150, 1));
    dodajProdukt(Produkt("P002", "Yeezy 350", "Buty od Kanyego Westa. Lekkie, wygodne z nowowczesnym designem.", 400.0, 165, 1));
    dodajProdukt(Produkt("P003", "New Balance 550", "Wygodne buty skorzane z klasycznym designem.", 450.0, 230, 1));
    dodajProdukt(Produkt("P004", "Nike Dunk", "Ikoniczne buty sportowe oraz na codzien.", 750.0, 120, 1));
    dodajProdukt(Produkt("P005", "Converse Chuck Taylor", "Trampki do chodzenia po miescie z wygodna podeszwa.", 190.0, 230, 1));
    dodajProdukt(Produkt("P006", "Adidas Predator", "Korki do gry w pilke nozna.", 250.0, 170, 1));
    dodajProdukt(Produkt("P007", "Sandaly Mojrzeszki RL9", "", 1.0, 230, 1));
    dodajProdukt(Produkt("P008", "Nike CR7", "", 7777.0, 230, 1));
    dodajProdukt(Produkt("P009", "Yeezy Slide", "", 390.0, 230, 1));
    dodajProdukt(Produkt("P010", "Buty klauna", "", 4200.0, 230, 1));
    std::cout << "Produkty zostaly zainicjalizowane.\n";
}

// Dodaje produkt do bazy
void BazaDanych::dodajProdukt(const Produkt& produkt) {
    produkty.push_back(produkt);
}

// Pobiera nowo?ci
std::vector<Produkt> BazaDanych::pobierzNowosci() const {
    std::vector<Produkt> nowosci;
    for (size_t i = 0; i < produkty.size() && i < 5; ++i) {
        nowosci.push_back(produkty[i]);
    }
    return nowosci;
}

// Pobiera promocje
std::vector<Produkt> BazaDanych::pobierzPromocje() const {
    std::vector<Produkt> promocje;
    for (size_t i = 5; i < produkty.size() && i < 10; ++i) {
        promocje.push_back(produkty[i]);
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