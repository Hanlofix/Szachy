#include "goniec.h"


//##################################
vector <pair<int,int>> Goniec::pobierzMozliweRuchy(int x, int y)
{
    ruchy.clear();
    //W PRZYPADKU TEJ FIGURY MUSIMY ROZPATRZEC 4 RODZAJE RUCHÓW PO PRZEKATNEJ
    //LEWO-DOL, LEWO-GORA, PRAWO-DOL, PRAWO-GORA

    int mozliwe_ruchy[] ={1, 2, 3, 4, 5, 6, 7};// GONIEC MOZE PORUSZAC O DOWOLNA LICZBE POL PO PRZEKATNEJ :)... O ILE NIC NIE STOI NA PRZESZKODZIE

//SZUKAM MOZLIWYCH RUCHOW GONCEM W KIERUNKU PRAWO-DOL
    for(int i=0; i<7;i++)
    {

        int nowyX = x + mozliwe_ruchy[i];
        int nowyY = y + mozliwe_ruchy[i];

        if(nowyX>=0 && nowyX <= 7 && nowyY >= 0 && nowyY <= 7)
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
//SZUKAM MOZLIWYCH RUCHOW GONCEM W KIERUNKU LEWO-GORA
    for(int i=0; i<7;i++)
    {

        int nowyX = x - mozliwe_ruchy[i];
        int nowyY = y - mozliwe_ruchy[i];

        if(nowyX>=0 && nowyX <= 7 && nowyY >= 0 && nowyY <= 7)
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
//SZUKAM MOZLIWYCH RUCHOW GONCEM W KIERUNKU LEWO-DOL
    for(int i=0; i<7;i++)
    {

        int nowyX = x + mozliwe_ruchy[i];
        int nowyY = y - mozliwe_ruchy[i];

        if(nowyX>=0 && nowyX <= 7 && nowyY >= 0 && nowyY <= 7)
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
//SZUKAM MOZLIWYCH RUCHOW GONCEM W KIERUNKU PRAWO-GORA
    for(int i=0; i<7;i++)
    {

        int nowyX = x - mozliwe_ruchy[i];
        int nowyY = y + mozliwe_ruchy[i];

        if(nowyX>=0 && nowyX <= 7 && nowyY >= 0 && nowyY <= 7)
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
