#ifndef POLE_H
#define POLE_H

#include "figura.h"

using namespace std;

/**
 * @file pole.h
 * @author Tomasz Wardak
 * @brief Klasa, której obiekty reprezentują pojedyncze pola na planszy, na których ustawiane sa figury
 * @date 31-05-2022
 */

class Pole
{
public:
    /**
     * @brief Metoda odpowiedzialna za ustawienie koloru i nazwy zdjecia danej figury (atrybutow prywatnych obiektu klasy Figura)
     * @param figura wskaznik na konkretna figure
     * @param kolor kolor figury
     * @param nazwaIkony sciezka do zdjecia figury
     * @return void
     */
    void ustawFigure(Figura *figura, Kolor kolor, string nazwaIkony);
    /**
     * @brief Metoda zwracajaca wskaznik na figure dla ktorej zostala wywolana ta metoda
     * @return zwraca wskaznik na figure
     */
    Figura *pobierzFigura();
    /**
     * @brief Metoda kalkulująca mozliwe do wykonania ruchy figury znajdujacej sie na danym polu
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie figura
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie figura
     * @return Zwraca wektor pozycji, gdzie figura moze sie ruszyc z danego pola
     */
    vector<pair<int, int>> pobierzMozliweRuchy(int x, int y);
private:
    /**
     * @brief Wskaznik na figure, ktora stoi na danym polu
     */
    Figura *figura;
};

#endif // POLE_H
