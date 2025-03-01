#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>

class Produkt {
private:
    std::string idProduktu;
    std::string nazwa;
    std::string opis;
    double cena;
    int iloscWMagazynie;
    int ilosc;
    int rozmiar;

public:
    Produkt(const std::string& id, const std::string& nazwa, const std::string& opis, double cena, int magazyn, int ilosc, int rozmiar = 0);

    // Gettery
    std::string getId() const;
    std::string getNazwa() const;
    double getCena() const;

    // Settery
    void ustawNowaCene(double nowaCena);  // Metoda do ustawiania nowej ceny
    void ustawRozmiar(int nowyRozmiar);   // Setter dla rozmiaru
    int getRozmiar() const;               // Getter dla rozmiaru
};

#endif
