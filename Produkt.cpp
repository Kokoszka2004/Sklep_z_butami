#include "Produkt.h"

Produkt::Produkt(const std::string& id, const std::string& nazwa, const std::string& opis, double cena, int magazyn, int ilosc, int rozmiar)
    : idProduktu(id), nazwa(nazwa), opis(opis), cena(cena), iloscWMagazynie(magazyn), ilosc(ilosc), rozmiar(rozmiar) {}

// Gettery
std::string Produkt::getId() const { return idProduktu; }
std::string Produkt::getNazwa() const { return nazwa; }
double Produkt::getCena() const { return cena; }

// Setter dla nowej ceny
void Produkt::ustawNowaCene(double nowaCena) {
    cena = nowaCena;
}

// Setter i getter dla rozmiaru
void Produkt::ustawRozmiar(int nowyRozmiar) {
    rozmiar = nowyRozmiar;
}

int Produkt::getRozmiar() const {
    return rozmiar;
}
