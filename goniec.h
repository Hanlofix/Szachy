#ifndef GONIEC_H
#define GONIEC_H

#include "figura.h"

/**
 * @file goniec.h
 * @author Tomasz Wardak
 * @brief Klasa pochodna dziedzicząca publicznie po klasie bazowej Figura
 * @date 31-05-2022
 */
class Goniec: public Figura
{
public:
    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy Goncem
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie Goniec
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie Goniec
     * @return Zwraca wektor pozycji, gdzie figura (Goniec) moze sie ruszyc
     */
    vector<pair<int, int>> pobierzMozliweRuchy(int x, int y) override;
};

#endif // GONIEC_H
