#include "Zamowienie.h"
#include <iostream>

// Konstruktor
Zamowienie::Zamowienie(const std::string& id, const std::vector<Produkt>& produkty, const std::string& status)
    : idZamowienia(id), listaProduktow(produkty), statusZamowienia(status) {
}

// Finalizuje zamowienie
void Zamowienie::finalizujZamowienie() {
    std::cout << "Zamowienie " << idZamowienia << " zostalo sfinalizowane." << std::endl;
}

// Edytuje zamowienie
void Zamowienie::edytujZamowienie() {
    std::cout << "Edytowanie zamowienia: " << idZamowienia << std::endl;
}
