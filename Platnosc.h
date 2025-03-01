#ifndef PLATNOSC_H
#define PLATNOSC_H

#include <string>

class Platnosc {
protected:
    std::string typPlatnosci;

public:
    Platnosc(const std::string& typ);
    virtual void wykonajPlatnosc() = 0;
    virtual ~Platnosc() {}
};

#endif

