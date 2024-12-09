#ifndef KONTO_H
#define KONTO_H

#include <string>

class Konto {
private:
    std::string nazwaUzytkownika;
    std::string haslo;
    std::string email;

public:
    Konto(const std::string& nazwa, const std::string& haslo, const std::string& email);
    std::string getNazwaUzytkownika() const;
    bool weryfikujDane(const std::string& nazwa, const std::string& haslo) const;
};

#endif
