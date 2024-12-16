#include "Uzytkownik.h"
#include <iostream>

// Konstruktor
Uzytkownik::Uzytkownik() : nazwaUzytkownika("") {}

// Logowanie
bool Uzytkownik::zaloguj(BazaDanych& baza) {
    std::string nazwa, haslo;
    std::cout << "Podaj nazwe uzytkownika: ";
    std::cin >> nazwa;
    std::cout << "Podaj haslo: ";
    std::cin >> haslo;

    if (baza.weryfikujKonto(nazwa, haslo)) {
        nazwaUzytkownika = nazwa;
        std::cout << "Zalogowano pomyslnie!\n";
        return true;
    }
    else {
        std::cout << "Niepoprawna nazwa uzytkownika lub haslo.\n";
        return false;
    }
}

// Rejestracja
void Uzytkownik::zarejestruj(BazaDanych& baza) {
    std::string nazwa, haslo;
    std::cout << "Podaj nazwe uzytkownika: ";
    std::cin >> nazwa;

    if (baza.czyNazwaZajeta(nazwa)) {
        std::cout << "Nazwa uzytkownika jest juz zajeta.\n";
        return;
    }

    std::cout << "Podaj haslo: ";
    std::cin >> haslo;

    baza.dodajKonto(nazwa, haslo);
    std::cout << "Zarejestrowano pomyslnie! Mozesz sie teraz zalogowac.\n";
}

// Pobierz nazw? u?ytkownika
std::string Uzytkownik::getNazwaUzytkownika() const {
    return nazwaUzytkownika;
}
