#ifndef BAZADANYCH_H
#define BAZADANYCH_H

#include <vector>
#include "Produkt.h"

class BazaDanych {
private:
    std::vector<Produkt> produkty; // Lista wszystkich produktów w bazie

    std::vector<std::pair<std::string, std::string>> konta; // Nazwa u?ytkownika i has?o
    const std::string plikKonta = "konta.txt";

    void wczytajKontaZPliku();
    void zapiszKontaDoPliku() const;
    // Inicjalizuje przyk?adowe produkty
    void inicjalizujProdukty();

public:
    // Konstruktor
    BazaDanych();

    // Dodaje produkt do bazy
    void dodajProdukt(const Produkt& produkt);

    // Pobiera nowo?ci
    std::vector<Produkt> pobierzNowosci() const;

    // Pobiera promocje
    std::vector<Produkt> pobierzPromocje() const;

    // Wyszukuje produkt po nazwie
    Produkt wyszukajProdukt(const std::string& nazwa) const;

    // Dodaje nowego u?ytkownika do bazy
    void dodajKonto(const std::string& nazwa, const std::string& haslo);

    // Sprawdza, czy konto istnieje (do logowania)
    bool weryfikujKonto(const std::string& nazwa, const std::string& haslo) const;

    // Sprawdza, czy nazwa u?ytkownika jest zaj?ta (do rejestracji)
    bool czyNazwaZajeta(const std::string& nazwa) const;
};

#endif
