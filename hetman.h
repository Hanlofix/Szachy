#ifndef HETMAN_H
#define HETMAN_H

#include "figura.h"

/**
 * @file hetman.h
 * @author Tomasz Wardak
 * @brief Klasa pochodna dziedzicząca publicznie po klasie bazowej Figura
 * @date 31-05-2022
 */

class Hetman: public Figura
{
public:
    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy Hetmanem
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie Hetman
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie Hetman
     * @return Zwraca wektor pozycji, gdzie figura (Hetman) moze sie ruszyc
     */
    vector<pair<int, int>> pobierzMozliweRuchy(int x, int y) override;
};

#endif // HETMAN_H
