#include "pion.h"
#include <gra.h>
extern Gra * gra;

//##################################
// METODA ZWRACAJACA WSZYSTKIE MOZLIWE RUCHY KTORE W DANEJ CHWILI MOZEMY WYKONAC PIONEM
vector <pair<int,int>> Pion::pobierzMozliweRuchy(int x, int y)
{
    ruchy.clear(); //czyscimy zmienna ruchy, ktora zawiera mozliwe do wykonania przez figure ruchy

    //CZARNY PION MOZE WYKONAC RUCH O 1 DO PRZODU JEZELI ZNAJDUJE SIE NA POLACH OD X=<1,6>
    //W PRZYPADKU TYCH RUCHOW PION DODATKOWO MOZE PORUSZYC SIE O Y={-1(BICIE W LEWO),0(RUCH DO PRZODU),1(BICIE W PRAWO)
    //CZARNY PION MOZE WYKONAC RUCH O 2 DO PRZODU JEZELI ZNAJDUJE SIE NA POLU O X= 1
    int mozliwe_y[]= {-1,0,1};

    //IMPLEMENTACJA RUCHU DLA CZARNEGO PIONA
    if(gra->pobierzObecnyRuch() == CZARNY)
    {
        vector<pair<int,int>> pozycja;

        if(x == 1)//CZARNY PION MOZE WYKONAC RUCH O 2 DO PRZODU JEZELI ZNAJDUJE SIE NA POLU O X= 1 I NA 2 KOLEJNYCH POLACH NIC NIE STOI
        { pair<int,int> pozycja1(2,y);
          pair<int,int> pozycja(3,y);

          if(poleJestPuste(pozycja1) == true && poleJestPuste(pozycja) == true )
          {
              ruchy.push_back(pozycja);
          }
        }

        for(int k = 0; k<3;k++) //CZARNY PION MOZE WYKONAC RUCH O 1 DO PRZODU
        {

            int nowyX = x + 1;
            int nowyY = y + mozliwe_y[k];

            pair<int,int> pozycja(nowyX,nowyY);

            if(nowyX >= 2 && nowyX <= 7 && nowyY >= 0 && nowyY <= 7)
            {

                if(poleJestPuste(pozycja) == true && nowyY == y) //JEZELI POLE PRZED PIONEM JEST PUSTE IDZIE O 1 DO PRZODU
                {
                    ruchy.push_back(pozycja);
                }
                else if (toFiguraPrzeciwnika(pozycja) == true && nowyY != y) //JEZELI POLE PO PRZEKATNEJ ( W LEWO BADZ W PRAWO) JEST ZAJETE
                {                                                            //PION MOZE ZBIC FIGURE PRZECIWNIKA I STANAC NA TYM POLU
                    ruchy.push_back(pozycja);
                }

            }
        }


    }
    //IMPLEMENTACJA RUCHU DLA BIALEGO PIONA
    else if (gra->pobierzObecnyRuch() == BIALY)
    {
        vector<pair<int,int>> pozycja;

        if(x == 6)//BIALY PION MOZE WYKONAC RUCH O 2 DO PRZODU JEZELI ZNAJDUJE SIE NA POLU O X= 6 I NA 2 KOLEJNYCH POLACH NIC NIE STOI
        { pair<int,int> pozycja1(5,y);
          pair<int,int> pozycja(4,y);

          if(poleJestPuste(pozycja1) == true && poleJestPuste(pozycja) == true )
          {
              ruchy.push_back(pozycja);
          }
        }

        for(int k = 0; k<3;k++) //BIALY PION MOZE WYKONAC RUCH O 1 DO PRZODU
        {

            int nowyX = x - 1;
            int nowyY = y + mozliwe_y[k];

            pair<int,int> pozycja(nowyX,nowyY);

            if(nowyX >= 0 && nowyX <= 5 && nowyY >= 0 && nowyY <= 7)
            {

                if(poleJestPuste(pozycja) == true && nowyY == y) //JEZELI POLE PRZED PIONEM JEST PUSTE IDZIE O 1 DO PRZODU
                {
                    ruchy.push_back(pozycja);
                }
                else if (toFiguraPrzeciwnika(pozycja) == true && nowyY != y) //JEZELI POLE PO PRZEKATNEJ ( W LEWO BADZ W PRAWO) JEST ZAJETE
                {                                                            //PION MOZE ZBIC FIGURE PRZECIWNIKA I STANAC NA TYM POLU
                    ruchy.push_back(pozycja);
                }

            }
        }

    }
    return ruchy;

}
//##################################
