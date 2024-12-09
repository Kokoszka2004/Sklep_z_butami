#include "OstatecznePodsumowanie.h"

// Konstruktor
OstatecznePodsumowanie::OstatecznePodsumowanie(double kwota) : kwota(kwota) {}

// Oblicza laczna cene
double OstatecznePodsumowanie::obliczLacznaCene() const {
    return kwota;
}
