#include "figura.h"
#include<gra.h>
#include <string>

using namespace std;
extern Gra *gra;

//##################################
// KONSTRUKTOR KLASY FIGURA
Figura::Figura()
{
//PUSTO
}
//##################################
// DESTRUKTOR KLASY FIGURA
Figura::~Figura()
{
//PUSTO
}
//##################################
// METODA ODPOWIEDZIALNA ZA USTAWIANIE KOLORU FIGURY NA RZECZ KTOREJ ZOSTALA WYWOLANA
void Figura::ustawKolor(Kolor kolor)
{
 this->kolor = kolor;
}
//##################################
// METODA ZWRACAJACA KOLOR DANEJ FIGURY
Kolor Figura::pobierzKolor()
{
    return kolor;
}
//##################################
// METODA ODPOWIEDZIALNA ZA USTAWIANIE NAZWY IKONY FIGURY NA RZECZ KTOREJ ZOSTALA WYWOLANA
void Figura::ustawIkone(string nazwaIkony)
{
 this->nazwaIkony = nazwaIkony;
}
//##################################
// METODA ZWRACAJACA NAZWE IKONY DANEJ FIGURY
string Figura::pobierzNazweIkony()
{
    return nazwaIkony;
}
//##################################
//METODA WIRTUALNA, KTOREJ PRAWDZIWA IMPLEMENTACJA JEST W KAZDEJ Z FIGUR
vector<pair<int, int>> Figura::pobierzMozliweRuchy(int x, int y)
{
  /*  return vector<pair<int, int>>();*/
}
//##################################
// METODA SPRAWDZAJACA CZY FIGURA STOJACA NA DANYM POLU NALEZY DO PRZECIWNIKA
bool Figura::toFiguraPrzeciwnika(pair<int,int> pozycjaKoncowa) {
    Kolor c = gra->pobierzPlansze()->pobierzPole(pozycjaKoncowa.first, pozycjaKoncowa.second)->pobierzFigura()->pobierzKolor();
    if(c != gra->pobierzObecnyRuch() && c != NIEWIDZIALNY)
        return true;
    return false;
}
//##################################
// METODA SPRAWDZAJACA CZY DANE POLE JEST PUSTE
bool Figura::poleJestPuste(pair<int,int> pozycjaKoncowa) {
    if (dynamic_cast<PustePole*>(gra->pobierzPlansze()->pobierzPole(pozycjaKoncowa.first, pozycjaKoncowa.second)->pobierzFigura()))
        return true;
    return false;
}
//##################################
