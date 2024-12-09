#ifndef BAZADANYCH_H
#define BAZADANYCH_H

#include <string>
#include <vector>
#include "Konto.h"
#include "Produkt.h"

class BazaDanych {
public:
    // Metody do obs?ugi bazy danych
    bool sprawdzDostepnoscNazwy(const std::string& nazwa) const;
    void zapiszKonto(const Konto& konto);
    Konto stworzKonto(const std::string& nazwa, const std::string& haslo, const std::string& email);
    bool sprawdzDaneLogowania(const std::string& nazwa, const std::string& haslo) const;
    void zapiszProdukt(const Produkt& produkt);
};

#endif

