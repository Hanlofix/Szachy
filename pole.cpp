#include "pole.h"

using namespace std;

//##################################
// METODA ODPOWIEDZIALNA ZA USTAWIENIE KOLORU I  NAZWY ZDJECIA (ATRYBUTOW PRYWATNYCH OBIEKTU KLASY FIGURA)
void Pole::ustawFigure(Figura *f, Kolor kolor, string nazwaIkony)
{
    figura = f;
    figura->ustawKolor(kolor);
    figura->ustawIkone(nazwaIkony);
}
//##################################
// METODA ZWRACAJACA WSKAZNIK NA FIGURE DLA KTOREJ ZOSTALA WYWOLANA TA METODA
Figura * Pole::pobierzFigura()
{
    return this->figura;
}
//##################################
//METODA ZWRACAJACA MOZLIWE RUCHY KTORE MOZEMY WYKONAC FIGURA STOJACA NA KONKRETNYM POLU
vector<pair<int, int>> Pole::pobierzMozliweRuchy(int x, int y)
{
    return figura->pobierzMozliweRuchy(x, y);
}
