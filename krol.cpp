#include "krol.h"

//##################################
// METODA ZWRACAJACA WSZYSTKIE MOZLIWE RUCHY KTORE W DANEJ CHWILI MOZEMY WYKONAC KROLEM
vector <pair<int, int>> Krol::pobierzMozliweRuchy(int x, int y)
{
    ruchy.clear();
    int mozliwe_ruchy[] = {-1, 0, 1};
    //NARAZIE UPRASZCZAMY PORUSZANIE SIE KROLA O NIESPRAWDZENIE TEGO CZY DANA FIGURA JEST BRONIONA I GROZI SZACH

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int nowyX = x + mozliwe_ruchy[i];
            int nowyY = y + mozliwe_ruchy[j];


            if((nowyX>=0 && nowyX <= 7 && nowyY >= 0 && nowyY <= 7) && ((mozliwe_ruchy[i]==0 && mozliwe_ruchy[j]==0) ==false) )
            {
                pair<int, int> pozycja(nowyX,nowyY);
                ruchy.push_back(pozycja);
            }
        }
    }
    return ruchy;
}
