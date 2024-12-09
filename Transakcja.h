#ifndef TRANSAKCJA_H
#define TRANSAKCJA_H

#include <string>
#include <vector>
#include "Produkt.h"
#include "Uzytkownik.h"

class Transakcja {
private:
    std::string idTransakcji;           // Unikalny identyfikator transakcji
    Uzytkownik uzytkownik;              // Uzytkownik wykonujacy transakcje
    std::vector<Produkt> listaProduktów; // Lista produktow w transakcji
    double calkowitaCena;               // Calkowity koszt transakcji
    std::string dataTransakcji;         // Data transakcji (mozesz uzyc np. std::string na poczatek)

public:
    // Konstruktor
    Transakcja(const std::string& id, const Uzytkownik& uzytkownik, const std::vector<Produkt>& produkty, double cena, const std::string& data);

    // Metody
    void potwierdzTransakcje(); // Finalizacja transakcji
    void anulujTransakcje();    // Anulowanie transakcji
    void pokazSzczegoly() const; // Wyswietl szczegoly transakcji
};

#endif

