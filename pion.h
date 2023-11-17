#ifndef PION_H
#define PION_H

#include "figura.h"

/**
 * @file pion.h
 * @author Tomasz Wardak
 * @brief Klasa pochodna dziedzicząca publicznie po klasie bazowej Figura
 * @date 31-05-2022
 */

class Pion:public Figura
{
public:
    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy Pionem
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie Pion
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie Pion
     * @return Zwraca wektor pozycji, gdzie figura (Pion) moze sie ruszyc
     */
    vector<pair<int, int>> pobierzMozliweRuchy(int x, int y) override;
};

#endif // PION_H
