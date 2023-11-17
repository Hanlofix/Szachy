#include "plansza.h"

//##################################
// KONSTRUKTOR KLASY PLANSZA
Plansza::Plansza()
{   //POCZATKOWE USTAWIENIE FIGUR NA PLANSZY

    //wskaznik na dwu-wymiarowa tablice wskaznikow (tak naprawde nie ma dwuwymiarowej tablicy wskaznikow)
    //pola to wskaznik do jednowymiarowej tablicy wskaznikow, gdzie te wskazniki są wskaznikiami na 1 element kazdego wiersza
    //gdzie w kazdym wierszu mamy 8 obiektow klasy pole typu wskaznikowego
    //''Deklarując tablicę dynamiczną należy zadeklarować wskaźnik tego samego typu co elementy tablicy.''

    //deklaracja pola w pliku nagłowkowym Pole ***pola;
    //pola jest wskaźnikiem do pierwszego elementu jednowymiarowej tablicy wskaznikow
    //na pierwsze elementy kazdego wiersza, gdzie w kazdym wierszu mammy 8 obiektow
    //klasy Pole typu wskaznikowego
    //ROZRYSOWANE W ZESZYCIE DOPYTAC

    pola = new Pole**[8];
    for(int i = 0; i < 8;i++)
    {
        pola[i] = new Pole*[8];//tablica 8 wskaznikow do pierwszego elementu kazdego wiersza
        for(int j = 0; j < 8; j++)
        {
            pola[i][j] = new Pole(); //wskaznik na konkretne pole

            if(i == 0)
            { //USTAWIENIE CIEZKICH FIGURY CZARNEGO GRACZA NA PLANSZY
                if(j == 0 || j == 7)
                {pola[i][j]->ustawFigure(new Wieza(), CZARNY, ":/zdjecia/wieza_czarna.png");}
                if(j == 1 || j == 6)
                {pola[i][j]->ustawFigure(new Skoczek(), CZARNY, ":/zdjecia/skoczek_czarny.png");}
                if(j == 2 || j == 5)
                {pola[i][j]->ustawFigure(new Goniec(), CZARNY, ":/zdjecia/goniec_czarny.png");}
                if(j == 3)
                {pola[i][j]->ustawFigure(new Hetman(), CZARNY, ":/zdjecia/hetman_czarny.png");}
                if(j == 4)
                {pola[i][j]->ustawFigure(new Krol(), CZARNY, ":/zdjecia/krolowa_czarna.png");}
            }

            if(i == 1)
            {//USTAWIENIE PIONOW CZARNEGO GRACZA NA PLANSZY
                pola[i][j]->ustawFigure(new Pion(), CZARNY,":/zdjecia/pion_czarny.png");
            }

            if(i == 6)
            {//USTAWIENIE PIONOW BIALEGO GRACZA NA PLANSZY
                pola[i][j]->ustawFigure(new Pion(), BIALY,":/zdjecia/pion_bialy.png");
            }


            if(i == 7)
            { //USTAWIENIE CIEZKICH FIGURY BIALEGO GRACZA NA PLANSZY
                if(j == 0 || j == 7)
                {pola[i][j]->ustawFigure(new Wieza(), BIALY, ":/zdjecia/wieza_biala.png");}
                if(j == 1 || j == 6)
                {pola[i][j]->ustawFigure(new Skoczek(), BIALY, ":/zdjecia/skoczek_bialy.png");}
                if(j == 2 || j == 5)
                {pola[i][j]->ustawFigure(new Goniec(), BIALY, ":/zdjecia/goniec_bialy.png");}
                if(j == 3)
                {pola[i][j]->ustawFigure(new Hetman(), BIALY, ":/zdjecia/hetman_bialy.png");}
                if(j == 4)
                {pola[i][j]->ustawFigure(new Krol(), BIALY, ":/zdjecia/krolowa_biala.png");}
            }

            if(i > 1 && i < 6) //USTAWIENIE PUSTYCH POL W MIEJSCU GDZIE NIE MAMY FIGUR
            {
                pola[i][j]->ustawFigure(new PustePole(), NIEWIDZIALNY, "");
            }



        }

    }
}
//##################################
// DESTRUKTOR KLASY PLANSZA-KASOWANIE PLANSZY PO ROZGRYWCE
Plansza::~Plansza()
{
for (int i=0; i<8;i++)
{
    delete [] pola[i]; //KASUJEMY POJEDYNCZE WIERSZE Z 8 OBIEKTAMI KLASY POLE
}
delete [] pola;
}
//##################################
// METODA ZWRACAJACA WSKAZNIK NA POLE O KONKRETNYCH WSPOLRZEDNYCH
Pole* Plansza::pobierzPole(int x, int y)
{
    return pola[x][y];
}
//##################################
// METODA ODPOWIEDZIALNA ZA PRZESUWANIE FIGURY Z JEJ POCZATKOWEJ POZYCJI DO TEJ WYBRANEJ PRZEZ GRACZA
// W MIEJSCU POZYCJI POCZATKOWEJ USTAWIANY JEST OBIEKT KLASY PUSTEPOLE()
void Plansza::przesunFigure(pair<int, int> poprzedniaPozycja, pair<int, int> nowaPozycja)
{
    //POBIERAMY POZYCJE Z KTOREJ PRZESUWAMY FIGURE
    //POLE TO ZOSTANIE ZASTAPIONE FIGURA "PUSTEPOLE"
    int x0 = poprzedniaPozycja.first;
    int y0 = poprzedniaPozycja.second;

    //POBIERAMY WSPOLRZEDNE NOWEJ POZYCJI NA PLANSZY
    int x = nowaPozycja.first;
    int y = nowaPozycja.second;

    //POBIERAMY FIGURE STOJACA NA POZYCJI(X0,Y0) ORAZ JEJ KOLOR(MUSIMY WIEDZIEC DO KTOREGO GRACZA NALEZY)

    Figura * figura = pola[x0][y0]->pobierzFigura();
    Kolor kolor = figura->pobierzKolor();

    // DYNAMICZNE RZUTOWANIE PO SPRAWDZENIU KOLORU
    //SPRAWDZAMY JAKI TYP FIGURY STAŁ NA POZYCJI POCZATKOWEJ I TEJ SAMEJ KLASY OBIEKT USTAWIAMY NA NOWYM POLU TWORZAC OBIEKT TEJ KLASY
    if(kolor == NIEWIDZIALNY)
    {
        if(dynamic_cast<PustePole*>(figura))
        {pola[x][y]->ustawFigure(new PustePole(), NIEWIDZIALNY, "");}
    }
    else if(kolor == CZARNY)
    {
        if(dynamic_cast<Wieza*>(figura))
        {pola[x][y]->ustawFigure(new Wieza(), CZARNY, ":/zdjecia/wieza_czarna.png");}
        if(dynamic_cast<Skoczek*>(figura))
        {pola[x][y]->ustawFigure(new Skoczek(), CZARNY, ":/zdjecia/skoczek_czarny.png");}
        if(dynamic_cast<Goniec*>(figura))
        {pola[x][y]->ustawFigure(new Goniec(), CZARNY, ":/zdjecia/goniec_czarny.png");}
        if(dynamic_cast<Hetman*>(figura))
        {pola[x][y]->ustawFigure(new Hetman(), CZARNY, ":/zdjecia/hetman_czarny.png");}
        if(dynamic_cast<Krol*>(figura))
        {pola[x][y]->ustawFigure(new Krol(), CZARNY, ":/zdjecia/krolowa_czarna.png");}
        if(dynamic_cast<Pion*>(figura))
        {pola[x][y]->ustawFigure(new Pion(), CZARNY, ":/zdjecia/pion_czarny.png");}
    }
    else if(kolor == BIALY)
    {
        if(dynamic_cast<Wieza*>(figura))
        {pola[x][y]->ustawFigure(new Wieza(), BIALY, ":/zdjecia/wieza_biala.png");}
        if(dynamic_cast<Skoczek*>(figura))
        {pola[x][y]->ustawFigure(new Skoczek(), BIALY, ":/zdjecia/skoczek_bialy.png");}
        if(dynamic_cast<Goniec*>(figura))
        {pola[x][y]->ustawFigure(new Goniec(), BIALY, ":/zdjecia/goniec_bialy.png");}
        if(dynamic_cast<Hetman*>(figura))
        {pola[x][y]->ustawFigure(new Hetman(), BIALY, ":/zdjecia/hetman_bialy.png");}
        if(dynamic_cast<Krol*>(figura))
        {pola[x][y]->ustawFigure(new Krol(), BIALY, ":/zdjecia/krolowa_biala.png");}
        if(dynamic_cast<Pion*>(figura))
        {pola[x][y]->ustawFigure(new Pion(), BIALY, ":/zdjecia/pion_bialy.png");}
    }
    // W MIEJSCU Z KTOREGO SIE RUSZALISMY USTAWIAMY FIGURE BEDACA OBIEKTEM KLASY PUSTEPOLE()
    pola[x0][y0]->ustawFigure(new PustePole(),NIEWIDZIALNY, "");

}
//##################################
//UPROSZCZONY WARUNEK MATOWANIA KROLA
//DO ZMIANY
bool Plansza::czyKrolZostalZamatowany()
{// JEZELI LICZBA KROLI JEST ROZNA OD 2 KONCZYMY ROZGRYWKE
    int liczbaKroli = 0;
    for (int i = 0; i < 8 ;i++) {
        for (int j = 0; j < 8 ;j++){
            if (dynamic_cast<Krol*>(pobierzPole(i,j)->pobierzFigura())) {
                liczbaKroli++;
            }
            if(liczbaKroli == 2) {
                return false;
            }
        }
    }
    if (liczbaKroli < 2)
        return true;
}
//##################################
