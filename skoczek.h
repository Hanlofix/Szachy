#ifndef SKOCZEK_H
#define SKOCZEK_H

#include "figura.h"

/**
 * @file skoczek.h
 * @author Tomasz Wardak
 * @brief Klasa pochodna dziedzicząca publicznie po klasie bazowej Figura
 * @date 31-05-2022
 */

class Skoczek:public Figura
{
public:
    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy Skoczkiem
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie Skoczek
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie Skoczek
     * @return Zwraca wektor pozycji, gdzie figura (skoczek) moze sie ruszyc
     */
    vector<pair<int, int>> pobierzMozliweRuchy(int x, int y) override;
};

#endif // SKOCZEK_H
