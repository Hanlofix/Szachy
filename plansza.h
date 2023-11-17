#ifndef PLANSZA_H
#define PLANSZA_H

#include "Kolor.h"
#include "goniec.h"
#include "hetman.h"
#include "krol.h"
#include "pion.h"
#include "skoczek.h"
#include "wieza.h"
#include "pole.h"
#include "pustepole.h"

/**
 * @file plansza.h
 * @author Tomasz Wardak
 * @brief Klasa, której obiekt reprezentuje plansze, a zamieszczone w niej metody odpowiedzialne sa za jej obsluge
 * @date 31-05-2022
 */

class Plansza
{
private:
    Pole ***pola; // obiekt klasy Pole typu wskaznikowego bedacy wskaznikiem do dwuwymiarowej tablicy wskaznikow (w uproszczeniu)
public:
    /**
     * @brief Konstruktor klasy Plansza odpowiedzialny za poczatkowe ustawienie figur na planszy
     */
    Plansza();
    ~Plansza();

    /**
     * @brief Metoda zwracajaca wskaznik na pole o konkretnych wspolrzednych
     * @param x Pierwsza wspolrzedna pola
     * @param y Druga wspolrzedna pola
     * @return Zwraca wskaznik na pole o konkretnych wspolrzednych
     */
    Pole *pobierzPole(int x, int y);
    /**
     * @brief Metoda odpowiedzialna za przesuwanie figury z jej poczatkowej pozycji do pozycji koncowej
     * @param poprzedniaPozycja wspolrzedne pola, z ktorego ruszamy sie figura
     * @param nowaPozycja wspolrzedne pola, w ktore chcemy ruszyc sie figura
     */
    void przesunFigure(pair<int, int> poprzedniaPozycja, pair<int, int> nowaPozycja);
    bool czyKrolZostalZamatowany();
};

#endif // PLANSZA_H
