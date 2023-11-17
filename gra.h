#ifndef GRA_H
#define GRA_H

#include "Kolor.h"
#include "goniec.h"
#include "hetman.h"
#include "krol.h"
#include "pion.h"
#include "skoczek.h"
#include "wieza.h"
#include "pole.h"
#include "plansza.h"
#include <string>
#include <vector>

/**
 * @file gra.h
 * @author Tomasz Wardak
 * @brief Klasa reprezentujaca pojedyncza gre.
 * @date 31-05-2022
 */

class Gra
{
public:
    /**
      * @brief Konstruktor klasy Gra tworzacy plansze, na ktorej beda prowadzone rozgrywki
      */
     Gra();
    //~Gra();
    /**
     * @brief Metoda odpowiedzialna za zmiane strony wykonujacej ruch
     * @return void
     */
    void ustawObecnyRuch();
    /**
     * @brief Metoda zwracajaca kolor gracza, który powinien wykonac kolejny ruch
     * @return Zwraca kolor gracza, który powinien wykonywac ruch
     */
    Kolor pobierzObecnyRuch();
    /**
     * @brief Metoda zwracajaca plansze, na ktorej toczy sie gra
     * @return zwraca wskaznik na plansze
     */
    Plansza *pobierzPlansze();
    /**
     * @brief Metoda odpowiedzialna w przypadku wygranej, remisu, badz poddania za ustawienie na calej planszy pustych pol
     * @return void
     */
    void zatrzymajPlansze();
    /**
     * @brief Metoda odpowiedzialna za ustawianie konca gry
     * @return void
     */
    void ustawInformacjeKoniecGry();
    /**
     * @brief Metoda zwracajaca informacje o koncu gry
     * @return Zwraca prawde, jezeli gra sie zakonczyla
     */
    bool pobierzInformacjeKoniecGry();
    /**
     * @brief Metoda ustawiajaca numer tury
     * @return void
     */
    void ustawNumerTury();
    /**
     * @brief Metoda zwracajaca obecny numer tury
     * @return Zwraca obecny numer tury
     */
    int pobierzNumerTury();
    /**
     * @brief Metoda ustawiajaca numer posuniecia
     * @param x zmienna okreslajaca, o ile zmieniamy licznik posuniec
     * @return void
     */
    void ustawNumerPosuniecia(int x);
    /**
     * @brief Metoda zwracajaca obecny numer posuniecia
     * @return Zwraca liczbe wykonanych posuniec
     */
    int pobierzNumerPosuniecia();
    /**
     * @brief Metoda odkladajaca w obiekcie klasy wektor ostatnio wykonany ruch
     * @param pozycja wspolrzedne ostatno wykonanego ruchu
     * @return void
     */
    void dodajRuchDoHistorii(pair<int,int> pozycja);
    /**
     * @brief Metoda zwracajaca historie wszystkich wykonanych ruchow
     * @return zwraca wektor zawierajacy wspolrzedne kazdego wykonanego ruchu
     */
    vector <pair<int,int>> pobierzHistorieRuchow();
    /**
     * @brief Metoda zapisujaca w obiekcie klasy wektor pozycje poczatkowa, z ktorej byl wykonywany ruch figura
     * @param pozycja wspolrzedne pola, z ktorego poruszyla sie figura
     * @return void
*/
    void dodajPozycjePoczatkowaDoHistorii(pair<int,int> pozycja);
    /**
     * @brief Metoda zwracajaca historie pozycji poczatkowych
     * @return Zwraca historie pozycji startowych figur, z miejsc z których sie ruszaly
     */
    vector <pair<int,int>> pobierzHistoriePozycjiPoczatkowych();
    /**
     * @brief Metoda zwracajaca informacje, czy nastapilo zatrzymanie gry
     * @return Zwraca prawde, gdy gra zostala zatrzymana(skonczona)
     */
    bool pobierzZatrzymanieGry();
    /**
     * @brief Metoda zapisujaca ostatnio zbita figure
     * @param figura wskaznik na ostatnio zbita fiure
     * @return void
     */
    void ustawOstatnioZbitaFigure(Figura *figura);
    /**
     * @brief Metoda zwracajaca ostatnio zbita figura
     * @return zwraca wskaznik na ostatnio zbita figure
     */
    Figura *pobierzOstatnioZbitaFigure();
    /**
     * @brief Metoda zapisujaca ostatnia pozycje poczatkowa, z ktorej byl wykonany ruch figura
     * @param wspolrzedne pola, z ktorego startowala figura
     */
    void ustawPozycjaPoczatkowa(pair<int,int> pozycja);
    /**
     * @brief Metoda zwracajaca ostatnia pozycje poczatkowa, z ktorej byl wykonany ruch figura
     * @return zwraca wspolrzedne pola, z ktorego startowala ostatnio poruszona figura
     */
    pair<int,int> pobierzPozycjaPoczatkowa();
    /**
     * @brief Metoda zapisujaca ostatnia pozadana pozycje koncowa figury, ktora sie ruszamy
     * @param pozycja wspolrzedne pola, na ktore probowano przesunac figure
     * @return void
     */
    void ustawPozycjaPozadanegoRuchu(pair<int,int> pozycja);
    /**
     * @brief Metoda zwracajaca ostatnia pozadana pozycje koncowa figury, ktora sie ruszamy
     * @return Zwraca wspolrzedne pola, w ktore chcielismy ruszyc sie figura
     */
    pair<int,int> pobierzPozycjaPozadanegoRuchu();
    /**
     * @brief Metoda zapisujaca figure, ktora zostal wykonany ostatni ruch
     * @param wskaznik na figure, ktora zostala przemieszczona w ostatnim ruchu
     * @return void
     */
    void ustawOstatnioPoruszonaFigura(Figura *figura);
    /**
     * @brief Metoda zwracajaca figure, ktora zostal wykonany ostatni ruch
     * @return zwraca wskaznik na figure, ktora zostala przemieszczona w ostatnim ruchu
     */
    Figura * pobierzOstatnioPoruszonaFigura();


private:

    Kolor obecnyRuch;
    Plansza *plansza;
    Figura * ostatnioZbitaFigura;
    Figura * ostatnioPoruszonaFigura;
    bool graZatrzymana = false;
    bool czyToKoniecGry = false;
    int numerPosuniecia = 0;
    int numerTury = 1;
    vector <pair<int, int>> historiaRuchow;
    vector <pair<int, int>> historiaPoczatkowychPol;
    pair <int, int> pozycjaPoczatkowa; //pozycja poczatkowa figury z ktorej rozwazamy jej dalsze ruchy
    pair <int, int> pozycjaPozadanegoRuchu; //miejsce w  ktore chcemy sie ruszyc

};

#endif // GRA_H
