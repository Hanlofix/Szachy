#include "skoczek.h"

//##################################
// METODA ZWRACAJACA WSZYSTKIE MOZLIWE RUCHY KTORE W DANEJ CHWILI MOZEMY WYKONAC SKOCZKIEM
vector <pair<int, int>> Skoczek::pobierzMozliweRuchy(int x, int y)
{
    ruchy.clear();
    //DOWOLNY SKOCZEK MOZE WYKONYWAC RUCHY O NASTEPUJACYCH WEKTORACH PRZESUNIECIA:
    //(2,-1),(2,1),(-2,-1),(-2,1),(1,-2),(1,2),(-1,-2),(-1,2)
    // TO ZNACZY TRZEBA NARZUCIC WARUNEK ZE WARTOSC BEZWZGLEGNA Z PIERWSZEJ WSPOLRZEDNEJ PRZESUNIECIA
    //MUSI BYC ROZNA OD WARTOSCI BEZWZGLEDNEJ Z DRUGIEJ WSPOLRZEDNEJ PRZESUNIECIA
    //INACZEJ MUSIMY DAWAC 8 WARUNKOW CO MIJA SIE Z CELEM

    int mozliwe_ruchy[] = {-2, -1, 1, 2};

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(abs(mozliwe_ruchy[i]) != abs(mozliwe_ruchy[j]))
            {
                int nowyX = x + mozliwe_ruchy[i];
                int nowyY = y + mozliwe_ruchy[j];

                if(nowyX >= 0 && nowyX <=7 && nowyY >= 0 && nowyY <=7)
                {
                    pair <int,int> pozycja (nowyX, nowyY);
                    ruchy.push_back(pozycja);
                }
            }
        }
    }

    return ruchy;
}
//##################################
