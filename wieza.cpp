#include "wieza.h"


//##################################
//METODA ZWRACAJACA WSZYSTKIE MOZLIWE RUCHY KTORE MOZEMY WYKONAC WIEZA W DANEJ SYTUACJI
vector <pair<int, int>> Wieza::pobierzMozliweRuchy(int x, int y)
{
    ruchy.clear();
    // MUSIMY ROZPATRZEC 4 PRZYPADKI- WIEZA MOZE PORUSZAC SIE LEWO<->PRAWO, GORA<->DOL

    int mozliwe_ruchy[] ={1, 2, 3, 4, 5, 6, 7};// WIEZA MOZE PORUSZAC O DOWOLNA LICZBE POL W PO PROSTEJ :)... O ILE NIC NIE STOI NA PRZESZKODZIE

//SZUKAM RUCHOW WIEZĄ W GORE PLANSZY
    for(int i=0; i<7;i++)
    {

        int nowyX = x - mozliwe_ruchy[i];
        int nowyY = y;

        if(nowyX >= 0 && nowyX <= 7)
        {
            pair<int,int> pozycja(nowyX,nowyY);

            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == false) //JEZELI NAPOTKAMY SWOJA FIGURE TO PRZERYWAMY DZIALANIE PETLI I DALSZE SPRAWDZANIE
            {
                break;
            }
            if(poleJestPuste(pozycja) == true) //JEZELI POLE JEST PUSTE I WCZESNIEJ NIE NAPOTKAŁEM ZADNYCH FIGUR
            {                                                      // TO DODAJE POLE DO MOZLIWYCH DO WYKONANIA RUCHOW
                ruchy.push_back(pozycja);
                continue;
            }
            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == true) // JEZELI JEST TO FIGURA PRZECIWNIKA TO MOGE JA ZBIC, JEZELI NIE TO NIE MOGE PORUSZYC SIE NA TO POLE
            {
                ruchy.push_back(pozycja);
                break;
            }
        }
    }
//SZUKAM RUCHOW WIEZĄ W DOL PLANSZY
    for(int i=0; i<7;i++)
    {

        int nowyX = x + mozliwe_ruchy[i];
        int nowyY = y;

        if(nowyX >= 0 && nowyX <= 7)
        {
            pair<int,int> pozycja(nowyX,nowyY);

            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == false) //JEZELI NAPOTKAMY SWOJA FIGURE TO PRZERYWAMY DZIALANIE PETLI I DALSZE SPRAWDZANIE
            {
                break;
            }
            if(poleJestPuste(pozycja) == true) //JEZELI POLE JEST PUSTE I WCZESNIEJ NIE NAPOTKAŁEM ZADNYCH FIGUR
            {                                                      // TO DODAJE POLE DO MOZLIWYCH DO WYKONANIA RUCHOW
                ruchy.push_back(pozycja);
                continue;
            }
            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == true) // JEZELI JEST TO FIGURA PRZECIWNIKA TO MOGE JA ZBIC, JEZELI NIE TO NIE MOGE PORUSZYC SIE NA TO POLE
            {
                ruchy.push_back(pozycja);
                break;
            }
        }
    }
//SZUKAM RUCHOW WIEZĄ W LEWĄ STRONE PLANSZY
    for(int i=0; i<7;i++)
    {

        int nowyX = x ;
        int nowyY = y - mozliwe_ruchy[i];

        if(nowyY >= 0 && nowyY <= 7)
        {
            pair<int,int> pozycja(nowyX,nowyY);

            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == false) //JEZELI NAPOTKAMY SWOJA FIGURE TO PRZERYWAMY DZIALANIE PETLI I DALSZE SPRAWDZANIE
            {
                break;
            }
            if(poleJestPuste(pozycja) == true) //JEZELI POLE JEST PUSTE I WCZESNIEJ NIE NAPOTKAŁEM ZADNYCH FIGUR
            {                                                      // TO DODAJE POLE DO MOZLIWYCH DO WYKONANIA RUCHOW
                ruchy.push_back(pozycja);
                continue;
            }
            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == true) // JEZELI JEST TO FIGURA PRZECIWNIKA TO MOGE JA ZBIC, JEZELI NIE TO NIE MOGE PORUSZYC SIE NA TO POLE
            {
                ruchy.push_back(pozycja);
                break;
            }
        }
    }
//SZUKAM RUCHOW WIEZĄ W LEWĄ STRONE PLANSZY
    for(int i=0; i<7;i++)
    {

        int nowyX = x ;
        int nowyY = y + mozliwe_ruchy[i];

        if(nowyY >= 0 && nowyY <= 7)
        {
            pair<int,int> pozycja(nowyX,nowyY);

            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == false) //JEZELI NAPOTKAMY SWOJA FIGURE TO PRZERYWAMY DZIALANIE PETLI I DALSZE SPRAWDZANIE
            {
                break;
            }
            if(poleJestPuste(pozycja) == true) //JEZELI POLE JEST PUSTE I WCZESNIEJ NIE NAPOTKAŁEM ZADNYCH FIGUR
            {                                                      // TO DODAJE POLE DO MOZLIWYCH DO WYKONANIA RUCHOW
                ruchy.push_back(pozycja);
                continue;
            }
            if(poleJestPuste(pozycja) == false && toFiguraPrzeciwnika(pozycja) == true) // JEZELI JEST TO FIGURA PRZECIWNIKA TO MOGE JA ZBIC, JEZELI NIE TO NIE MOGE PORUSZYC SIE NA TO POLE
            {
                ruchy.push_back(pozycja);
                break;
            }
        }
    }

    return ruchy;
}
//##################################
