#include "gra.h"
#include <QDebug>

//##################################
//KOSNTRUKTOR KLASY GRA, TWORZYMY NOWY OBIEKT KLASY PLANSZA
Gra::Gra()
{
    //konstruktor klasy gra tworzy obiekt klasy plansza
    // na ktorym beda prowadzone rozgrywki
    plansza = new Plansza();
    obecnyRuch = CZARNY;
}
//##################################
//DESTRUKTOR KLASY GRA
/*Gra::~Gra()
{

}*/
//##################################
// ZMIANA STRONY WYKONUJACEJ RUCH
void Gra::ustawObecnyRuch()
{
    if(obecnyRuch == CZARNY)
    {  obecnyRuch = BIALY;}
    else
    { obecnyRuch = CZARNY;}



}
//##################################
// METODA ZWRACAJACA KOLOR GRACZA KTORY POWINIEN WYKONAC KOLEJNY RUCH
Kolor Gra::pobierzObecnyRuch()
{
    return obecnyRuch;
}
//##################################
//METODA ZWRACAJACA PLANSZE NA KTOREJ TOCZY SIE GRA
Plansza* Gra::pobierzPlansze()
{
    return plansza;

}
//##################################
// USTAWIANIE KONCA GRY
void Gra::ustawInformacjeKoniecGry()
{
    this->czyToKoniecGry = plansza->czyKrolZostalZamatowany();
}
//##################################
//METODA ZWRACAJACA INFORMACJE O KONCU GRY
bool Gra::pobierzInformacjeKoniecGry()
{
    return czyToKoniecGry;
}
//##################################
//METODA ZAMRAZAJACA PLANSZE TZN. W PRZYPADKU WYGRANEJ, REMISU BADZ PODDANIA USTAWIA WSZEDZIE PUSTE POLA
void Gra::zatrzymajPlansze()
{
    //METODA KLASY GRA ODPOWIEDZIALNA ZA ZAMIANE WSZYSTKICH POL NA PLANSZY JAKO OBIEKTOW KLASY PUSTE POLE PO TO ZEBY NIE MOZNA BYLO WYKONAC ZADNYCH RUCHOW
    for(int i=0; i<8;i++)
    {
        for(int j=0; j<8;j++)
        {
            plansza->pobierzPole(i,j)->ustawFigure(new PustePole(), NIEWIDZIALNY,"");

        }
    }
    this->graZatrzymana =true;

}
//##################################
// METODA USTAWIAJACA NUMER TURY
void Gra::ustawNumerTury()
{
   this->numerTury = 1 + (this->numerPosuniecia/2);
}
//##################################
// METODA ZWRACAJACA OBECNY NUMER TURY
int Gra::pobierzNumerTury()
{
    return numerTury;
}
//##################################
// METODA USTAWIAJACA NUMER POSUNIECIA// W ZALEZNOSCI OD TEGO CZY SIE RUSZAMY CZY COFAMY RUCH DODAJE BADZ ODEJMUJE 1 OD ZMIENNEJ PRYWATNEJ KLASY numerPosuniecia
void Gra::ustawNumerPosuniecia(int x)
{   // BEZ ZNACZENIA TAK NAPRAWDE ALE WSKAZNIK THIS WSKAZUJE WSKAZUJE NA OBIEKT DLA KTOREGO ZOSTALA WYWOLANA TA METODA
    // JEZELI CHCEMY USTAWIC JAKAS WARTOSC BEZPIECZNIEJ JEST KORZYSTAC ZE WSKAZNIKA THIS PONIEWAZ WSKAZUJE NA KONKRETNY OBIEKT
    // W PRZYPADKU JEDNEJ PLANSZY NIE MA TO WIEKSZEGO ZNACZENIA ALE JEZELI BYSMY MIELI WIELE PLANSZ TO WSKAZNIK THIS JEDNOZNACZANIE
    // DALBY NAM INFORMACJE NA KTOREJ PLANSZY DOKONANO RUCHU I TRZEBA ZWIEKSZYC ZMIENNA numerPosuniecia
      //numerPosuniecia = numerPosuniecia + 1;
    this->numerPosuniecia = this->numerPosuniecia + x;
}
//##################################
// METODA ZWRACAJACA OBECNY NUMER POSUNIECIA
int Gra::pobierzNumerPosuniecia()
{
    return numerPosuniecia;
}
//##################################
// METODA ODKLADAJACA W OBIEKCIE KLASY WEKTOR OSTATNIO WYKONANY RUCH
void Gra::dodajRuchDoHistorii(pair<int,int> pozycja)
{
    this->historiaRuchow.push_back(pozycja);
}
//##################################
// METODA ZWRACAJACA HISTORIE RUCHOW
vector <pair<int,int>> Gra::pobierzHistorieRuchow()
{
    return historiaRuchow;
}
//##################################
// METODA ZWRACAJACA INFORMACJE CZY NASTAPILO ZATRZYMANIE GRY W WYNIKU WYGRANEJ, PODDANIA, BADZ ZGODZENIA SIE NA REMIS
bool Gra::pobierzZatrzymanieGry()
{
    return graZatrzymana;
}
//##################################
// METODA ODKLADAJACA W OBIEKCIE KLASY WEKTOR POZYCJE POCZATKOWA Z KTOREJ WYKONYWANY BYL OSTATNI RUCH
void Gra::dodajPozycjePoczatkowaDoHistorii(pair<int,int> pozycja)
{
    this->historiaPoczatkowychPol.push_back(pozycja);
}
//##################################
// METODA ZWRACAJACA HISTORIE POOZYCJI POCZATKOWYCH
vector <pair<int,int>> Gra::pobierzHistoriePozycjiPoczatkowych()
{
    return historiaPoczatkowychPol;
}
//##################################
// METODA ZAPISUJACA OSTATNIO ZBITA FIGURE
void Gra::ustawOstatnioZbitaFigure(Figura *figura)
{
    this->ostatnioZbitaFigura = figura;
}
//##################################
// METODA ZWRACAJACA WSKAZNIK NA OSTATNIO ZBITA FIGURE
Figura * Gra::pobierzOstatnioZbitaFigure()
{
    return ostatnioZbitaFigura;
}
//##################################
//METODA USTAWIAJACA ZMIENNA PRYWATNA KLASY MAINWINDOW pozycjaPoczatkowa MOWIACA GDZIE STALA POCZATKOWO FIGURA KTORA SIE RUSZYLISMY
void Gra::ustawPozycjaPoczatkowa(pair<int, int> pozycja)
{
    this->pozycjaPoczatkowa = pozycja;
}
//##################################
// METODA ZWRACAJACA POZYCJE POCZATKOWA FIGURY KTORA SIE RUSZYLISMY
pair<int, int> Gra::pobierzPozycjaPoczatkowa()
{
    return pozycjaPoczatkowa;
}
//##################################
// METODA USTAWIAJACA ZMIENNA PRYWATNA KLASY MAINWINDOW pozycjaPozadanegoRuchu, KTORA MOWI GDZIE CHCEMY SIE RUSZYC DANA FIGURA
void Gra::ustawPozycjaPozadanegoRuchu(pair<int, int> pozycja)
{
    this->pozycjaPozadanegoRuchu = pozycja;
}
//##################################
// METODA ZWRACAJACA POZADANA POZYCJE KONCOWA FIGURY KTORA SIE RUSZAMY
pair<int, int> Gra::pobierzPozycjaPozadanegoRuchu()
{
    return pozycjaPozadanegoRuchu;
}
//##################################
// METODA USTAWIAJACA ZMIENNA PRYWATNA KLASY GRA "ostatnioPoruszonaFigura" NA FIGURE KTORA OSTATNIO WYKONALISMY RUCH
void Gra::ustawOstatnioPoruszonaFigura(Figura *figura)
{
    this->ostatnioPoruszonaFigura = figura;
}
//##################################
// METODA ZWRACAJACA FIGURE KTORA OSTATNIO WYKONALISMY RUCH
Figura* Gra::pobierzOstatnioPoruszonaFigura()
{
    return ostatnioPoruszonaFigura;
}
