#include "Konto.h"

// Konstruktor
Konto::Konto(const std::string& nazwa, const std::string& haslo, const std::string& email)
    : nazwaUzytkownika(nazwa), haslo(haslo), email(email) {
}
