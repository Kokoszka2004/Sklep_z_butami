#include "Uzytkownik.h"
#include <iostream>

// Konstruktor
Uzytkownik::Uzytkownik(const std::string& imie, const std::string& nazwisko, const std::string& email,
    const std::string& haslo, const std::string& nazwaUzytkownika, const std::string& adres)
    : imie(imie), nazwisko(nazwisko), email(email), haslo(haslo), nazwaUzytkownika(nazwaUzytkownika), adres(adres) {
}

// Gettery
std::string Uzytkownik::getNazwaUzytkownika() const {
    return nazwaUzytkownika;
}

std::string Uzytkownik::getEmail() const {
    return email;
}

// Operacje na koszyku
Koszyk& Uzytkownik::getKoszyk() {
    return koszyk;
}

// Stworz konto (placeholder)
void Uzytkownik::stworzKonto() {
    std::cout << "Tworzenie konta dla: " << nazwaUzytkownika << std::endl;
}

// Zaloguj sie (placeholder)
void Uzytkownik::zalogujSie() {
    std::cout << "Uzytkownik " << nazwaUzytkownika << " zalogowany." << std::endl;
}
