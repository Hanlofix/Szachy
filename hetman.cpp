#include "hetman.h"


//##################################
// METODA ZWRACAJACA WSZYSTKIE MOZLIWE RUCHY KTORE W DANEJ CHWILI MOZEMY WYKONAC HETMANEM
vector <pair<int, int>> Hetman::pobierzMozliweRuchy(int x, int y)
{

    //W PRZYPADKU TEJ FIGURY MUSIMY ROZPATRZEC 8 RODZAJ0W RUCHÓW
    //4 PO PRZEKATNYCH:LEWO-DOL, LEWO-GORA, PRAWO-DOL, PRAWO-GORA
    //4 PO LINII PROSTEJ: GORA, DOL, LEWO, PRAWO

    int mozliwe_ruchy[] ={1, 2, 3, 4, 5, 6, 7};// HETMAN MOZE PORUSZAC SIE O DOWOLONA LICZNE POL W DOWOLNYM KIERUNKU :)... O ILE NIC NIE STOI NA PRZESZKODZIE

//SZUKAM RUCHOW HETMANEM W GORE PLANSZY
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
//SZUKAM RUCHOW HETMANEM W DOL PLANSZY
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
//SZUKAM RUCHOW HETMANEM W LEWĄ STRONE PLANSZY
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
//SZUKAM RUCHOW HETMANEM W LEWĄ STRONE PLANSZY
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
//SZUKAM MOZLIWYCH RUCHOW HETMANEM W KIERUNKU PRAWO-DOL
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
//SZUKAM MOZLIWYCH RUCHOW HETMANEM W KIERUNKU LEWO-GORA
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
//SZUKAM MOZLIWYCH RUCHOW HETMANEM W KIERUNKU LEWO-DOL
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
//SZUKAM MOZLIWYCH RUCHOW HETMANEM W KIERUNKU PRAWO-GORA
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
