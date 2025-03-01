#include <iostream>
#include <vector>
#include "BazaDanych.h"
#include "Uzytkownik.h"
#include "Koszyk.h"
#include "Transakcja.h"
#include "Produkt.h"

int main() {
    BazaDanych baza;
    Uzytkownik uzytkownik;
    Koszyk koszyk;

    // Utworzenie przykładowej transakcji
    Transakcja transakcja("transakcja_id", uzytkownik, {}, 0.0, "dzisiejsza_data", koszyk);

    bool zalogowany = false;



    // Logowanie lub rejestracja
    while (!zalogowany) {
        std::cout << "\n=== EKRAN LOGOWANIA ===\n";
        std::cout << "1. Zaloguj sie\n";
        std::cout << "2. Zarejestruj sie\n";
        std::cout << "Wybierz opcje: ";
        std::string wybor;
        std::cin >> wybor;

        if (wybor == "1") {
            zalogowany = uzytkownik.zaloguj(baza);
        } else if (wybor == "2") {
            uzytkownik.zarejestruj(baza);
        } else {
            std::cout << "Niepoprawny wybor. Sprobuj ponownie.\n";
        }
    }

    std::cout << "Witaj, " << uzytkownik.getNazwaUzytkownika() << "!\n";

    int wybor = 0;
    while (wybor != 5) {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1. Nowosci\n";
        std::cout << "2. Promocje\n";;
        std::cout << "3. Zarzadzaj koszykiem\n";
        std::cout << "4. Wyjdz\n";
        std::cout << "Wybierz: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1: {
                auto nowosci = baza.pobierzNowosci();
                for (size_t i = 0; i < nowosci.size(); i++) {
                    std::cout << i + 1 << ". " << nowosci[i].getNazwa() << " | Cena: " << nowosci[i].getCena() << " PLN\n";
                }
                std::cout << "Wybierz numer produktu, aby dodac do koszyka, lub 0 aby wrocic: ";
                int numerProduktu;
                std::cin >> numerProduktu;
                if (numerProduktu > 0 && numerProduktu <= nowosci.size()) {
                    koszyk.dodajDoKoszyka(nowosci[numerProduktu - 1], 1);
                }
                break;
            }
            case 2: {
                auto promocje = baza.pobierzPromocje();
                for (size_t i = 0; i < promocje.size(); i++) {
                    std::cout << i + 1 << ". " << promocje[i].getNazwa() << " | Cena: " << promocje[i].getCena() << " PLN\n";
                }
                std::cout << "Wybierz numer produktu, aby dodac do koszyka, lub 0 aby wrocic: ";
                int numerProduktu;
                std::cin >> numerProduktu;
                if (numerProduktu > 0 && numerProduktu <= promocje.size()) {
                    koszyk.dodajDoKoszyka(promocje[numerProduktu - 1], 1);
                }
                break;
            }

            case 3: {
                koszyk.pokazZawartosc();
                double total = koszyk.obliczCalkowitaCene();
                std::cout << "Calkowita cena produktow w koszyku: " << total << " PLN\n";

                std::cout << "1. Usun produkt z koszyka\n";
                std::cout << "2. Przejdz do platnosci\n";
                std::cout << "3. Powrot do menu glownego\n";
                std::cout << "Wybierz opcje: ";
                int zarzadzanie;
                std::cin >> zarzadzanie;

                if (zarzadzanie == 1) {
                    koszyk.pokazZawartosc();
                    std::cout << "Podaj numer produktu do usuniecia: ";
                    int indexProduktu;
                    std::cin >> indexProduktu;
                    if (indexProduktu > 0 && indexProduktu <= koszyk.ileProduktow()) {
                        koszyk.usunZKoszyka(indexProduktu - 1);
                        std::cout << "Produkt usuniety.\n";
                    } else {
                        std::cout << "Nieprawidlowy numer produktu.\n";
                    }
                } else if (zarzadzanie == 2) {
                    transakcja.procesujPlatnosc();
                }
                break;
            }
            case 4:
                std::cout << "Koniec programu.\n";
                exit(0);
                break;
            default:
                std::cout << "Niepoprawny wybor!\n";
        }
    }

    return 0;
}
