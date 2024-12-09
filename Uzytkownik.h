#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <string>
#include "Koszyk.h"

class Uzytkownik {
private:
    std::string imie;
    std::string nazwisko;
    std::string email;
    std::string haslo;
    std::string nazwaUzytkownika;
    std::string adres;
    Koszyk koszyk;  // Kazdy uzytkownik ma swoj koszyk

public:
    // Konstruktor
    Uzytkownik(const std::string& imie, const std::string& nazwisko, const std::string& email,
        const std::string& haslo, const std::string& nazwaUzytkownika, const std::string& adres);

    // Gettery
    std::string getNazwaUzytkownika() const;
    std::string getEmail() const;

    // Operacje na koszyku
    Koszyk& getKoszyk();  // Zwraca referencje do koszyka uzytkownika

    // Metody uzytkownika
    void stworzKonto();
    void zalogujSie();
};

#endif

