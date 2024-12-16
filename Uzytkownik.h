#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <string>
#include "BazaDanych.h"

class Uzytkownik {
private:
    std::string nazwaUzytkownika;

public:
    Uzytkownik();

    // Logowanie
    bool zaloguj(BazaDanych& baza);

    // Rejestracja
    void zarejestruj(BazaDanych& baza);

    // Pobierz nazw? u?ytkownika
    std::string getNazwaUzytkownika() const;
};

#endif
