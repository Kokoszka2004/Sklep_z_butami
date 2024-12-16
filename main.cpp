#include <iostream>
#include "BazaDanych.h"
#include "Uzytkownik.h"
#include "Konto.h"


int main() {
    // Tworzymy baze danych
    BazaDanych baza;
    Uzytkownik uzytkownik;

    //------------------------------------------------------REJSTRACJA/LOGOWANIE------------------------------------------

    bool zalogowany = false;

    // Ekran logowania/rejestracji
    while (!zalogowany) {
        std::cout << "\n=== EKRAN LOGOWANIA ===\n";
        std::cout << "1. Zaloguj sie\n";
        std::cout << "2. Zarejestruj sie\n";
        std::cout << "Wybierz opcje: ";
        string wybor;
        std::cin >> wybor;

        if (wybor == "1") {
            zalogowany = uzytkownik.zaloguj(baza);
        }
        else if (wybor == "2") {
            uzytkownik.zarejestruj(baza);
        }
        else {
            std::cout << "Niepoprawny wybor. Sprobuj ponownie.\n";
        }
    }

    // Po zalogowaniu przechodzimy do menu g?ównego
    std::cout << "Witaj, " << uzytkownik.getNazwaUzytkownika() << "!\n";

    //------------------------------------------------------------MENU----------------------------------------------------------------
    
    int wybor = 0;
    while (wybor != 4) {
        std::cout << "\n=== MENU ===\n1. Nowosci\n2. Promocje\n3. Wyszukaj produkt\n4. Wyjdz\nWybierz: ";
        std::cin >> wybor;

        switch (wybor) {
        case 1:
            for (const auto& produkt : baza.pobierzNowosci()) {
                std::cout << produkt.getNazwa() << " | Cena: " << produkt.getCena() << " PLN\n";
            }
            break;
        case 2:
            for (const auto& produkt : baza.pobierzPromocje()) {
                std::cout << produkt.getNazwa() << " | Cena: " << produkt.getCena() << " PLN\n";
            }
            break;
        case 3: {
            std::string nazwa;
            std::cout << "Podaj nazwe produktu: ";
            std::cin >> nazwa;
            auto produkt = baza.wyszukajProdukt(nazwa);
            std::cout << produkt.getNazwa() << " | Cena: " << produkt.getCena() << " PLN\n";
            break;
        }
        case 4:
            std::cout << "Koniec programu.\n";
            break;
        default:
            std::cout << "Niepoprawny wybor!\n";
        }
    }

    //-------------------------------------------------------------------------------------------------------------------------------------
    

    return 0;
}
