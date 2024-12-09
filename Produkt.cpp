#include "Produkt.h"

using namespace std;

// Konstruktor
Produkt::Produkt(const std::string& id, const std::string& nazwa, const std::string& opis, double cena, int magazyn, int ilosc)
    : idProduktu(id), nazwa(nazwa), opis(opis), cena(cena), iloscWMagazynie(magazyn), ilosc(ilosc) {
}

// Gettery
string Produkt::getId() const {
    return idProduktu;
}

string Produkt::getNazwa() const {
    return nazwa;
}

string Produkt::getOpis() const {
    return opis;
}

double Produkt::getCena() const {
    return cena;
}

int Produkt::getIloscWMagazynie() const {
    return iloscWMagazynie;
}

int Produkt::getIlosc() const {
    return ilosc;
}

// Settery
void Produkt::ustawNowaCene(double nowaCena) {
    cena = nowaCena;
}

void Produkt::zmienIloscWMagazynie(int nowaIlosc) {
    iloscWMagazynie = nowaIlosc;
}
