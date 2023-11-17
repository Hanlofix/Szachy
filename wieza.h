#ifndef WIEZA_H
#define WIEZA_H

#include "figura.h"

/**
 * @file wieza.h
 * @author Tomasz Wardak
 * @brief Klasa pochodna dziedzicząca publicznie po klasie bazowej Figura
 * @date 31-05-2022
 */

class Wieza: public Figura
{
public:
    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy Wieza
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie Wieza
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie Wieza
     * @return Zwraca wektor pozycji, gdzie figura (Wieza) moze sie ruszyc
     */
    vector<pair<int, int>> pobierzMozliweRuchy(int x, int y) override;
};

#endif // WIEZA_H
