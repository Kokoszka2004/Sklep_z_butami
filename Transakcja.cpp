#include "Transakcja.h"
#include <iostream>

Transakcja::Transakcja(const std::string& id, const Uzytkownik& user, const std::vector<Produkt>& produkty, double cena, const std::string& data, Koszyk& koszyk)
    : idTransakcji(id), uzytkownik(user), listaProduktow(produkty), calkowitaCena(cena), dataTransakcji(data), koszyk(koszyk) {}

void Transakcja::potwierdzTransakcje() {
    std::cout << "Transakcja potwierdzona.\n";
    std::cout << "Laczna kwota: " << calkowitaCena << " PLN\n";
}

void Transakcja::anulujTransakcje() {
    std::cout << "Transakcja anulowana.\n";
}

void Transakcja::pokazSzczegoly() const {
    std::cout << "Szczegoly transakcji:\n";
    std::cout << "ID: " << idTransakcji << "\n";
    std::cout << "Data: " << dataTransakcji << "\n";
    std::cout << "Uzytkownik: " << uzytkownik.getNazwaUzytkownika() << "\n";
    std::cout << "Produkty:\n";
    for (const auto& produkt : listaProduktow) {
        std::cout << " - " << produkt.getNazwa() << " | Cena: " << produkt.getCena() << " PLN\n";
    }
    std::cout << "Laczna cena: " << calkowitaCena << " PLN\n";
}

void Transakcja::procesujPlatnosc() {
    std::cout << "Wybierz metode platnosci:\n";
    std::cout << "1. Karta kredytowa\n";
    std::cout << "2. Blik\n";
    std::cout << "3. PayPal\n";
    std::cout << "Wybierz: ";
    int metodaPlatnosci;
    std::cin >> metodaPlatnosci;
    std::string dane;

    switch (metodaPlatnosci) {
    case 1: {
        std::cout << "Wpisz 16 cyfr numeru karty: ";
        std::cin >> dane;
        if (dane.length() != 16) {
            std::cout << "Nieprawidlowy numer karty. Musi zawierac 16 cyfr.\n";
            return;
        }
        std::cout << "Dokonano zakupu za pomoca karty kredytowej.\n";
        break;
    }
    case 2: {
        std::cout << "Wpisz 6 cyfr kodu BLIK: ";
        std::cin >> dane;
        if (dane.length() != 6) {
            std::cout << "Nieprawidlowy kod BLIK. Musi zawierac 6 cyfr.\n";
            return;
        }
        std::cout << "Dokonano zakupu za pomoca BLIK.\n";
        break;
    }
    case 3: {
        std::string email, haslo;
        std::cout << "Wpisz email PayPal: ";
        std::cin >> email;
        std::cout << "Wpisz haslo PayPal: ";
        std::cin >> haslo;
        std::cout << "Dokonano zakupu za pomoca PayPal.\n";
        break;
    }
    default:
        std::cout << "Nieprawidlowy wybor metody platnosci.\n";
        return;
    }

    // Oproznianie koszyka po dokonaniu platnosci
    koszyk.wyczyscKoszyk();
}
