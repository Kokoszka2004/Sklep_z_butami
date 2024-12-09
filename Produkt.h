#ifndef PRODUKT_H
#define PRODUKT_H

using namespace std;

#include <string>

class Produkt {
private:
    string idProduktu;     // Unikalny identyfikator produktu
    string nazwa;          // Nazwa produktu
    string opis;           // Opis produktu
    double cena;                // Cena produktu
    int iloscWMagazynie;        // Ilo?? dost?pna w magazynie
    int ilosc;                  // Ilo?? zamawiana

public:
    // Konstruktor
    Produkt(const string& id, const string& nazwa, const string& opis, double cena, int magazyn, int ilosc);

    // Gettery
    string getId() const;          // Zwraca ID produktu
    string getNazwa() const;       // Zwraca nazw? produktu
    string getOpis() const;        // Zwraca opis produktu
    double getCena() const;             // Zwraca cen? produktu
    int getIloscWMagazynie() const;     // Zwraca ilo?? w magazynie
    int getIlosc() const;               // Zwraca ilo?? zamawian?

    // Settery
    void ustawNowaCene(double nowaCena);       // Ustawia now? cen? produktu
    void zmienIloscWMagazynie(int nowaIlosc);  // Aktualizuje ilo?? w magazynie
};

#endif

