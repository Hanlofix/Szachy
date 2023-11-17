#ifndef PUSTEPOLE_H
#define PUSTEPOLE_H

#include "figura.h"

/**
 * @file pustepole.h
 * @author Tomasz Wardak
 * @brief Klasa pochodna dziedzicząca publicznie po klasie bazowej Figura
 * @date 31-05-2022
 */

class PustePole: public Figura
{
public:
    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie figura
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie figura
     * @return Zwraca pusty wektor pozycji
      */
     vector<pair<int, int>> pobierzMozliweRuchy(int x, int y) override;
};

#endif // PUSTEPOLE_H
