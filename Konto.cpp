#include "Konto.h"

// Konstruktor
Konto::Konto(const std::string& nazwa, const std::string& haslo, const std::string& email)
    : nazwaUzytkownika(nazwa), haslo(haslo), email(email) {
}

// Pobiera nazwe uzytkownika
std::string Konto::getNazwaUzytkownika() const {
    return nazwaUzytkownika;
}

// Weryfikuje dane logowania
bool Konto::weryfikujDane(const std::string& nazwa, const std::string& haslo) const {
    return this->nazwaUzytkownika == nazwa && this->haslo == haslo;
}
