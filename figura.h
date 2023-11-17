#ifndef FIGURA_H
#define FIGURA_H

#include "Kolor.h"
#include <string>
#include <vector>



using namespace std;

/**
 * @file figura.h
 * @author Tomasz Wardak
 * @brief Klasa bazowa, ktora opisuje zachowania dziedziczacych po niej figur
 * @date 31-05-2022
 */

class Figura
{
public:
    Figura();
    ~Figura();
    /**
     * @brief Metoda ustawiajaca kolor figury, na rzecz, ktorej zostala wywolana
     * @param kolor jaki ma miec dana figura
     * @return void
     */
    void ustawKolor(Kolor kolor);
    /**
     * @brief Metoda ustawiajaca nazwe ikony, z ktorej bedzie odczytywane jej zdjecie
     * @param nazwaIkony sciezka do zdjecia figury
     * @return void
     */
    void ustawIkone(string nazwaIkony);
    /**
     * @brief Metoda zwracajaca kolor figury
     * @return Zwraca kolor figury
     */
    Kolor pobierzKolor();
    /**
     * @brief Metoda zwracajaca sciezke do zdjecia
     * @return zwraca sciezke do zdjecia danej figury
     */
    string pobierzNazweIkony();
    /**
     * @brief Wirtualna metoda, przeciazana w klasach pochodnych
     * @param x Pierwsza wspolrzedna pola na, którym znajduje sie figura
     * @param y Druga wspolrzedna pola na, ktorym znajduje sie figura
     * @return Zwraca wektor pozycji, gdzie figura moze sie ruszyc
     */
    virtual vector<pair<int, int>> pobierzMozliweRuchy(int x, int y);
    /**
     * @brief Metoda sprawdzajaca, czy figura stojaca na danym polu nalezy do przeciwnika
     * @param pozycjaKoncowa wspolrzedne pola, na ktorym stoi figura
     * @return zwraca prawde, jezeli dana figura jest figura przeciwnika
     */
    bool toFiguraPrzeciwnika(pair <int, int> pozycjaKoncowa);
    /**
     * @brief Metoda sprawdzajaca, czy dane pole jest puste
     * @param wspolrzedne sprawdzanego pola
     * @return zwraca prawde, jezeli dane pole jest puste
     */
    bool poleJestPuste(pair<int,int> pozycjaKoncowa);

protected:
    vector<pair<int,int>> ruchy;
private:

    Kolor kolor;
    string nazwaIkony;

};

#endif // FIGURA_H
