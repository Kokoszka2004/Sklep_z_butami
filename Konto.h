#ifndef KONTO_H
#define KONTO_H

#include <string>

class Konto {
public:
    std::string nazwaUzytkownika;
    std::string haslo;
    std::string email;

    Konto(const std::string& nazwa = "", const std::string& haslo = "", const std::string& email = "");
};

#endif