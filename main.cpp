#include <iostream>
#include "Produkt.h"
#include "Koszyk.h"
#include "Uzytkownik.h"
#include "Transakcja.h"
#include "Administrator.h"
#include "Platnosc.h"
#include "Zamowienie.h"
#include "BazaDanych.h"
#include "OstatecznePodsumowanie.h"
#include "Konto.h"

using namespace std;

int main() {



    /*TESTOWANIE PRODUKTU
    // Tworzenie obiektu Produkt
    Produkt laptop("P001", "Laptop", "Wysokiej jakosci laptop", 3000.0, 10, 1);

    // Wyswietlanie informacji o produkcie
    std::cout << "Produkt: " << laptop.getNazwa() << "\n";
    std::cout << "Opis: " << laptop.getOpis() << "\n";
    std::cout << "Cena: " << laptop.getCena() << "\n";
    std::cout << "Ilosc w magazynie: " << laptop.getIloscWMagazynie() << "\n";

    // Aktualizacja ceny
    laptop.ustawNowaCene(2500.0);
    std::cout << "Nowa cena: " << laptop.getCena() << "\n";

    // Aktualizacja ilosci w magazynie
    laptop.zmienIloscWMagazynie(20);
    std::cout << "Nowa ilosc w magazynie: " << laptop.getIloscWMagazynie() << "\n";
    */



    /*TESTOWANIE KOSZYKA
    // Tworzymy koszyk
    Koszyk koszyk;

    // Dodajemy produkty
    Produkt laptop("P001", "Laptop", "Wysokiej jako?ci laptop", 3000.0, 10, 1);
    Produkt myszka("P002", "Myszka", "Bezprzewodowa myszka", 150.0, 20, 1);

    koszyk.dodajDoKoszyka(laptop);
    koszyk.dodajDoKoszyka(myszka);

    // Wyswietlamy zawartosc koszyka
    koszyk.pokazZawartosc();

    // Usuwamy produkt z koszyka
    koszyk.usunZKoszyka("P001");
    koszyk.pokazZawartosc();

    // Wyczysc koszyk
    koszyk.wyczyscKoszyk();
    koszyk.pokazZawartosc();
    */



    /*TESOTWANIE UZYTKOWNIKA
    // Tworzymy uzytkownika
    Uzytkownik uzytkownik("Jan", "Kowalski", "jan.kowalski@example.com", "haslo123", "janek", "Warszawa");

    // Wyswietlamy nazwe uzytkownika
    std::cout << "Witaj, " << uzytkownik.getNazwaUzytkownika() << "!" << std::endl;

    // Dodajemy produkty do koszyka uzytkownika
    Produkt laptop("P001", "Laptop", "Wysokiej jakosci laptop", 3000.0, 10, 1);
    Produkt myszka("P002", "Myszka", "Bezprzewodowa myszka", 150.0, 20, 1);

    uzytkownik.getKoszyk().dodajDoKoszyka(laptop);
    uzytkownik.getKoszyk().dodajDoKoszyka(myszka);

    // Wyswietlamy zawartosc koszyka uzytkownika
    uzytkownik.getKoszyk().pokazZawartosc();

    // Zaloguj uzytkownika
    uzytkownik.zalogujSie();
    */


    /*TESTOWANIE TRANSAKCJI
    // Tworzymy uzytkownika
    Uzytkownik uzytkownik("Anna", "Nowak", "anna.nowak@example.com", "haslo321", "ania", "Krakow");

    // Tworzymy produkty
    Produkt laptop("P001", "Laptop", "Wysokiej jakosci laptop", 3000.0, 10, 1);
    Produkt myszka("P002", "Myszka", "Bezprzewodowa myszka", 150.0, 20, 1);

    // Dodajemy produkty do koszyka uzytkownika
    uzytkownik.getKoszyk().dodajDoKoszyka(laptop);
    uzytkownik.getKoszyk().dodajDoKoszyka(myszka);

    // Tworzymy liste produktow z koszyka
    std::vector<Produkt> produkty = { laptop, myszka };

    // Obliczamy laczna cene
    double calkowitaCena = laptop.getCena() + myszka.getCena();

    // Tworzymy transakcje
    Transakcja transakcja("T001", uzytkownik, produkty, calkowitaCena, "2024-12-09");

    // Wyswietlamy szczegoly transakcji
    transakcja.pokazSzczegoly();

    // Potwierdzamy transakcje
    transakcja.potwierdzTransakcje();

    // Anulujemy transakcje (przyklad)
    transakcja.anulujTransakcje();
    */



    /*TESOTWANIE ADMINISTRATORA
    // Tworzymy administratora
    Administrator admin("Pelne uprawnienia");

    // Tworzymy produkty
    Produkt laptop("P001", "Laptop", "Wysokiej jakosci laptop", 3000.0, 10, 1);
    Produkt myszka("P002", "Myszka", "Bezprzewodowa myszka", 150.0, 20, 1);

    // Dodajemy produkty
    admin.dodajNowyProdukt(laptop);
    admin.dodajNowyProdukt(myszka);
 
    // Zmieniamy cene produktu
    admin.zmienCeneProduktu(laptop, 2800.0);

    // Tworzymy transakcje do przegladania
    std::vector<Produkt> produkty = { laptop, myszka };
    Transakcja transakcja("T001", Uzytkownik("Jan", "Kowalski", "jan.kowalski@example.com", "haslo123", "janek", "Warszawa"), produkty, 2950.0, "2024-12-09");

    std::vector<Transakcja> listaTransakcji = { transakcja };
    admin.przegladajTransakcje(listaTransakcji);
    */

    // Tworzenie bazy danych
    BazaDanych bazaDanych;

    // Dodawanie produktow do bazy
    Produkt laptop("P001", "Laptop", "Wysokiej jakosci laptop", 3000.0, 10, 1);
    Produkt myszka("P002", "Myszka", "Bezprzewodowa myszka", 150.0, 20, 1);
    bazaDanych.zapiszProdukt(laptop);
    bazaDanych.zapiszProdukt(myszka);

    // Tworzenie uzytkownika
    Uzytkownik uzytkownik("Jan", "Kowalski", "jan.kowalski@example.com", "haslo123", "janek", "Warszawa");
    bazaDanych.zapiszKonto(Konto("janek", "haslo123", "jan.kowalski@example.com"));

    // Dodawanie produktow do koszyka uzytkownika
    uzytkownik.getKoszyk().dodajDoKoszyka(laptop);
    uzytkownik.getKoszyk().dodajDoKoszyka(myszka);

    // Wyswietlanie zawartosci koszyka
    std::cout << "Zawartosc koszyka uzytkownika:\n";
    uzytkownik.getKoszyk().pokazZawartosc();

    // Tworzenie transakcji
    std::vector<Produkt> produktyKoszyk = { laptop, myszka };
    double lacznaCena = laptop.getCena() + myszka.getCena();
    Transakcja transakcja("T001", uzytkownik, produktyKoszyk, lacznaCena, "2024-12-10");
    transakcja.pokazSzczegoly();

    // Finalizacja transakcji
    transakcja.potwierdzTransakcje();

    // Administrator zarzadza produktami
    Administrator admin("Pelne uprawnienia");
    admin.zmienCeneProduktu(laptop, 2500.0);

    // Tworzenie zamowienia na podstawie koszyka
    Zamowienie zamowienie("Z001", produktyKoszyk, "Oczekuje na realizacje");
    zamowienie.finalizujZamowienie();

    // Wyswietlanie szczegolow zamowienia
    std::cout << "\nSzczegoly zamowienia:\n";
    zamowienie.finalizujZamowienie();



	return 0;
}