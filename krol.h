#ifndef KROL_H
#define KROL_H

#include "figura.h"

/**
 * @file krol.h
 * @author Tomasz Wardak
 * @brief Klasa pochodna dziedzicząca publicznie po klasie bazowej Figura
 * @date 31-05-2022
 */

class Krol:public Figura
{
public:

    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy Krolem
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie Krol
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie Krol
     * @return Zwraca wektor pozycji, gdzie figura (Krol) moze sie ruszyc
     */
    vector<pair<int, int>> pobierzMozliweRuchy(int x, int y) override;
};

#endif // KROL_H
