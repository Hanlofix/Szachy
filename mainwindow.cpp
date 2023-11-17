#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawwindow.h"
#include "ui_drawwindow.h"
#include "mianowanie.h"
#include "ui_mianowanie.h"
#include <QDebug>
#include <QProcess>
#include "gra.h"
#include "drawwindow.h"


//TEN PLIK ZAWIERA WSKAZNIK NA GRE
//JEST TO DEKLARACJA BEZ DEFINICJI ZE GDZIE ISTNIEJE ZMIENNA GRA I DAJEMY O TYM ZNAC KOMPILATOROWI
extern Gra *gra;

using namespace std;
//##################################
//KONSTRUKTOR KLASY MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //USTAWIAMY TYTUL OKNA STARTOWEGO APLIKACJI
    setWindowTitle("Szachy-Wersja Koncowa");

    //TWORZENIE NOWEGO OBIEKTU KLASY GRA
    gra = new Gra();

    // USTAWIENIE TEGO KTO MA WYKONAC RUCH BIALY/CZARNY ORAZ ZMIANA KIERUNKU STRZALKI NA PANELU GRY
    ustawObecnyRuchNaPlanszy();

    //WYPISYWANIE PRZEZ LICZNIK LICZBY ODBYTYCH TUR
    MainWindow::findChild<QLCDNumber *>("NumerTury")->display(gra->pobierzNumerTury());

    // USTAWIENIE KOMUNIKATU POCZATKOWEGO W OKNIE HISTORII RUCHOW
    MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->setText("                    Brak Historii Ruchow");



    // POBIERAMY PRZYCISKI Z PLANSZY I USTAWIAMY IKONY
    // TAM GDZIE NIE MA IKON MAMY OBIEKTY KLASY PUSTE POLE
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {   //WYSZUKANIE PRZYCISKU W NASZYM FORMULARZU mainwindow.ui I ZWROCENIE WSKAZNIKA NA NIEGO
            QPushButton *przycisk = pobierzPrzycisk(i, j);
            //USTAWIENIE IKON NA PRZYCISKACH POCZATKOWO USTAWIAMY NIC A NASTEPNIE NA POLACH GDZIE ZNAJDUJA SIE FIGURY UMIESZCZAMY ODPOWIEDNIE IKONY
            przycisk->setIcon(QIcon(""));
            przycisk->setIcon(QIcon(QString::fromStdString(gra->pobierzPlansze()->pobierzPole(i, j)->pobierzFigura()->pobierzNazweIkony())));

            //POLACZENIE KAZDEGO PRZYCISKU Z POLEM JEMU PRZYPISANYM, JEZELI KTOS KLIKNIE NA DANE POLE TO NASTAPI WYWOLANIE MEOTDY kliknietonaPole()
            connect(przycisk, SIGNAL(released()),this,SLOT(kliknietoNaPole()));
        }
    }
    QPushButton *nowaGra = MainWindow::findChild<QPushButton *>("NowaGra");
    QPushButton *wyjscie = MainWindow::findChild<QPushButton *>("Wyjscie");
    QPushButton *poddanie = MainWindow::findChild<QPushButton *>("Poddanie");
    QPushButton *remis = MainWindow::findChild<QPushButton *>("Remis");
    QPushButton *cofanie = MainWindow::findChild<QPushButton *>("Cofanie");
    connect(nowaGra,SIGNAL(clicked()),this,SLOT(zacznijOdNowa())); //POLACZENIE PRZYCISKU "NowaGra" Z METODA ODPOWIEDZIALNA ZA RESTARTOWANIE ROZGRYWKI
    connect(wyjscie,SIGNAL(clicked()),this,SLOT(wyjdzZGry()));   // POLACZENIE PRZYCISKU "Wyjscie" Z METODA ODPOWIEDZIALNA ZA KONCZENIE ROZGRYWKI
    connect(poddanie,SIGNAL(clicked()),this,SLOT(poddajSie())); // POLACZENIE PRZYCISKU "Poddanie" Z METODA ODPOWIEDZIALNA ZA PODDANIE SIE KTOREGOS Z GRACZY
    connect(remis,SIGNAL(clicked()),this,SLOT(zremisuj()));   // POLACZENIE PRZYCISKU "remis" Z METODA ODPOWIEDZIALNA ZA ZAPYTANIE O REMIS
    connect(cofanie,SIGNAL(clicked()),this,SLOT(cofnijRuch()));// POLACZENIE PRZYCISKU "cofanie" Z METODA ODPOWIEDZIALNA ZA COFANIE ROZGRYWKI O 1 TURE


}
//##################################
//DESTRUKTOR KLASY MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}
//##################################
// USTAWIENIE TEGO KTO MA WYKONAC TERAZ RUCH BIALY/CZARNY ORAZ ZMIANA KIERUNKU STRZALKI NA PANELU GRY
void MainWindow:: ustawObecnyRuchNaPlanszy()
{
    QToolButton *ruch = MainWindow::findChild<QToolButton *>("ruch");
    gra->ustawObecnyRuch();
   if(gra->pobierzObecnyRuch() == CZARNY)
   {
       ruch->setIcon(QIcon(QString::fromStdString(":/zdjecia/strzalka_lewo.png")));
   }
   else
   {
       ruch->setIcon(QIcon(QString::fromStdString(":/zdjecia/strzalka_prawo.png")));
   }


}
//##################################
//WYSZUKANIE PRZYCISKU W NASZYM FORMULARZU mainwindow.ui I ZWROCENIE WSKAZNIKA NA NIEGO
QPushButton * MainWindow::pobierzPrzycisk(int x, int y)
{
    QString nazwaPola = "Pole_" + QString::number(x) + QString::number(y);
    QPushButton *przycisk = MainWindow::findChild<QPushButton *>(nazwaPola);
    return przycisk;
}
//##################################
//METODA WYWOLYWANA W MOMENCIE KLIKNIECIA NA JAKIES POLE NA PLANSZY
//JEST TO GLOWNA FUNKCJA W KTOREJ DOCHODZI DO SPRAWSZENIA WYGRANEJ, MOZLIWYCH DO WYKONANIA RUCHU, ZLICZANIE TUR , CZY WYSWIETLANIE HISTORII RUCHOW
void MainWindow:: kliknietoNaPole()
{
    //DO ZMIENNEJ pole PRZYPISUJEMY WSKAZNIK NA KLIKNIETE POLE
    QPushButton *pole = (QPushButton *) sender();
    //WYSWIETLENIE KOMUNIKATU KTORE POLE KLIKNIETO W OKNIE KOMUNIKATOW APLIKACJI (INFORMACJA WIDZOCZNA TYLKO W TRYBIE DEBUGOWANIA)
    qDebug() <<"Kliknieto przycisk:"<<pole->objectName();
    // POBRANIE POZYCJI KLIKNIETO POLA (X,Y) PO JEGO NAZWIE (OSTATNIE DWA ZNAKI OZNACZAJA ODPOWIEDNI WIERSZ I KOLUMNE PLANSZY)
    pair<int,int> pozycja = pobierzPozycje(pole->objectName().toStdString());
    //POBRANIE OBIEKTU KLASY POLE NA KTOREGO PRZYCISK KLIKNAL GRACZ
    Pole * p = gra->pobierzPlansze()->pobierzPole(pozycja.first,pozycja.second);
    //WYSZUKANIE PRZYCISKU KLASY QLCDNUMBER O NAZWIE "NumerTury" I PRZYPISANIE GO DO ZMIENNEJ licznik TEJ SAMEJ KLASY
    QLCDNumber *licznik = MainWindow::findChild<QLCDNumber *>("NumerTury");

    //SPRAWDZENIE CZY KOLOR GRACZA, KTÓRY OBECNIE WYKONUJE RUCH JEST TAKI SAM JAK KOLOR FIGURY NA POLU NA KTORE NACISNELISMY
    // (CZARNY, BIALY LUB JEZELI NIE MA TAM FIGURY KOLOR "NIEWIDZIALNY")
    // LUB TEZ CZY JAKIES POLE ZOSTALO JUZ WCZESNIEJ KLIKNIETE
    if(gra->pobierzObecnyRuch() == p->pobierzFigura()->pobierzKolor() ||jestKlikniete == 1)
    {
        // I PRZYPADEK KIEDY KLIKAMY FIGURE KTORA CHCEMY SIE RUSZYC
        if(jestKlikniete == 0)
        {
            //USTAWIAMY POZYCJA POCZATKOWA JEST TO POZYCJA POLA NA KTORYM ZNAJDUJE SIE KLIKNIETA FIGURA
            gra->ustawPozycjaPoczatkowa(pozycja);

            //USTAWAIMY FIGURE KTORA OSTATNIO SIE RUSZALISMY I ZAPISUJEMY JA DO ZMIENNEJ PRYWATNEJ KLASY GRA
            gra->ustawOstatnioPoruszonaFigura(gra->pobierzPlansze()->pobierzPole(pozycja.first,pozycja.second)->pobierzFigura());
            //do usuniecia gra->ostatnioPoruszonaFigura = gra->pobierzPlansze()->pobierzPole(pozycja.first,pozycja.second)->pobierzFigura();
            // WYSWIETLENIE W KOMUNIKATORZE APLIKACJI NAZWY FIGURY KTORA SIE PORUSZŁEM
            qDebug()<<QString::fromStdString(gra->pobierzOstatnioPoruszonaFigura()->pobierzNazweIkony());

            // USTAWIAMY ZMIENNA PRZECHOWUJACA WSZYSTKIE MOZLIWE POZYCJE JAKIE MOZNA WYKONAC FIGURA ZNAJDUJACA SIE NA DANYM POLU
            ustawMozliwePozycje(p->pobierzMozliweRuchy(pozycja.first, pozycja.second));

            //PRZESTAJE PODSWIETLAC WCZESNIEJ KLIKNIETY PRZYCISK
            odznaczWcisnietyPrzycisk();
            //PODSWIETLAMY(ZMIENIAMY KOLOR-NA ZOLTY) PRZYCISK NA KTORY KLIKNELISMY
            pole->setStyleSheet("QPushButton { background-color : #FFDEAD; }");
            //PODSWIETLAMY MIEJSCA W KTORE MOZEMY PORUSZYC SIE DANA FIGURA
            podswietlMozliweRuchy(mozliwePozycje);
            jestKlikniete = true;
        }
        //II PRZYPADEK KIEDY KLIKNELISMY NA FIGURE KTORA CHCEMY SIE RUSZYC, A TERAZ WYBIERAMY POLE DO DOCELOWEGO RUCHU
        else if (jestKlikniete == 1)
        {
            //USTAWIAMY pozycjePozadanegoRuchu CZYLI POZYCJE W KTORA CHCEMY SIE RUSZYC WCZESNIEJ WYBRANA FIGURA
            gra->ustawPozycjaPozadanegoRuchu(pozycja);

            //SPRAWDZAMY CZY POLE NA KTORE CHCEMY SIE RUSZYC JEST PUSTE I CZY WOGOLE MOZEMY SIE TAM RUSZYC
            if(poleJestPuste(gra->pobierzPozycjaPozadanegoRuchu()) && maRuch())
            {
                //DO ZMIENNEJ PRYWATNEJ KLASY GRA ZAPISUJEMY SOBIE  FIGURE KTORA ZBILISMY NP. WIEZA, HETMAN ITD
                gra->ustawOstatnioZbitaFigure(gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->pobierzFigura());

                //PRZESUWAMY FIGURE, SPRAWDZAMY KONIEC GRY I AKTUALIZUJEMY PLANSZE
                gra->pobierzPlansze()->przesunFigure(gra->pobierzPozycjaPoczatkowa(), gra->pobierzPozycjaPozadanegoRuchu());

                //TUTAJ POWINNO BYC SPRAWDZENIE MIANOWANIA
                if(dynamic_cast<Pion*>(gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first, gra->pobierzPozycjaPozadanegoRuchu().second)->pobierzFigura()) &&
                        (gra->pobierzPozycjaPozadanegoRuchu().first == 0 || gra->pobierzPozycjaPozadanegoRuchu().first == 7 ))
                {
                    qDebug()<<"PION POWINIEN ZOSTAC MIANOWANY NA FIGURE CIEZKA!!!";
                    Mianowanie c;
                    c.setModal(true);
                    c.exec();
                }

                gra->ustawInformacjeKoniecGry();



                //PO WYKONANIU PIERWSZEGO RUCHU KASUJEMY TEKST W QTextEdit O BRAKU RUCHOW
                if(gra->pobierzNumerPosuniecia() == 0)
                {
                    MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->clear();
                }

                // PO WYKONANIU RUCHU INKREMENTUJEMY NUMER POSUNIECIA I ZMIENIONA WARTOSC WYSWIETLAMY NA LICZNIKU
                gra->ustawNumerPosuniecia(1);
                gra->ustawNumerTury();
                qDebug() <<"Numer Tury"<<gra->pobierzNumerTury();
                licznik->display(gra->pobierzNumerTury());

                //DODAJEMY WYKONANY RUCH DO HISTORII RUCHOW I WYSWIETLAMY KOMUNIKAT O JEGO WSPOLRZEDNYCH W KOMUNIKATORZE APLIKACJI
                gra->dodajPozycjePoczatkowaDoHistorii(gra->pobierzPozycjaPoczatkowa());
                gra->dodajRuchDoHistorii(gra->pobierzPozycjaPozadanegoRuchu());
                qDebug() <<"POCZATKOWE POLE FIGURY KTORA SIE RUSZYLISMY:"<<gra->pobierzHistoriePozycjiPoczatkowych().back();
                qDebug() <<"RUCH ZAPISYWANY DO HISTORII:"<<gra->pobierzHistorieRuchow().back();

                //WYSWIETLAMY NA PANELU HISTORII RUCHOW OSTATNIO WYKONANY RUCH
                wyswietlHistorieRuchowNaPanelu(gra->pobierzHistorieRuchow().back());
                aktualizujGre();

                //PO KAZDYM WYKONANYM RUCHU W PRZYPADKU ROZLACZENIA NA NOWO AKTYWUJEMY POLACZENIE DOTYCZACE COFANIA RUCHOW W RAZIE ZERWANIA POLACZENIA W PRZYPADKU KLIKNIECIA COFNIECIA RUCHU
                connect(MainWindow::findChild<QPushButton *>("Cofanie"),SIGNAL(clicked()),this,SLOT(cofnijRuch()));



            }
            //SPRAWDZAMY CZY POLE NA KTORE CHCEMY SIE RUSZYC JEST ZAJETE PRZEZ PRZECIWNIKA I CZY WOGOLE MOZEMY SIE TAM RUSZYC
            else if(toFiguraPrzeciwnika(gra->pobierzPozycjaPozadanegoRuchu()) && maRuch())
            {
                //DO ZMIENNEJ PRYWATNEJ KLASY GRA ZAPISUJEMY SOBIE  FIGURE KTORA ZBILISMY NP. WIEZA, HETMAN ITD
                gra->ustawOstatnioZbitaFigure(gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->pobierzFigura());

                //PRZESUWAMY FIGURE, SPRAWDZAMY KONIEC GRY I AKTUALIZUJEMY PLANSZE
                gra->pobierzPlansze()->przesunFigure(gra->pobierzPozycjaPoczatkowa(), gra->pobierzPozycjaPozadanegoRuchu());

                //TUTAJ POWINNO BYC SPRAWDZENIE MIANOWANIA
                if(dynamic_cast<Pion*>(gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first, gra->pobierzPozycjaPozadanegoRuchu().second)->pobierzFigura()) &&
                        (gra->pobierzPozycjaPozadanegoRuchu().first == 0 || gra->pobierzPozycjaPozadanegoRuchu().first == 7 ))
                {
                    qDebug()<<"PION POWINIEN ZOSTAC MIANOWANY NA FIGURE CIEZKA!!!";
                    Mianowanie c;
                    c.setModal(true);
                    c.exec();
                }

                gra->ustawInformacjeKoniecGry();



                //PO WYKONANIU PIERWSZEGO RUCHU KASUJEMY TEKST W QTextEdit O BRAKU RUCHOW
                if(gra->pobierzNumerPosuniecia() == 0)
                {
                    MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->clear();
                }

                // PO WYKONANIU RUCHU INKREMENTUJEMY NUMER POSUNIECIA I ZMIENIONA WARTOSC WYSWIETLAMY NA LICZNIKU
                gra->ustawNumerPosuniecia(1);
                gra->ustawNumerTury();
                qDebug() <<"Numer Tury"<<gra->pobierzNumerTury();
                licznik->display(gra->pobierzNumerTury());

                //DODAJEMY WYKONANY RUCH DO HISTORII RUCHOW I WYSWIETLAMY KOMUNIKAT O JEGO WSPOLRZEDNYCH W KOMUNIKATORZE APLIKACJI
                gra->dodajPozycjePoczatkowaDoHistorii(gra->pobierzPozycjaPoczatkowa());
                gra->dodajRuchDoHistorii(gra->pobierzPozycjaPozadanegoRuchu());
                qDebug() <<"POCZATKOWE POLE FIGURY KTORA SIE RUSZYLISMY:"<<gra->pobierzHistoriePozycjiPoczatkowych().back();
                qDebug() <<"RUCH ZAPISYWANY DO HISTORII:"<<gra->pobierzHistorieRuchow().back();

                //WYSWIETLAMY NA PANELU HISTORII RUCHOW OSTATNIO WYKONANY RUCH
                wyswietlHistorieRuchowNaPanelu(gra->pobierzHistorieRuchow().back());
                aktualizujGre();

                //PO KAZDYM WYKONANYM RUCHU W PRZYPADKU ROZLACZENIA NA NOWO AKTYWUJEMY POLACZENIE DOTYCZACE COFANIA RUCHOW W RAZIE ZERWANIA POLACZENIA W PRZYPADKU KLIKNIECIA COFNIECIA RUCHU
                connect(MainWindow::findChild<QPushButton *>("Cofanie"),SIGNAL(clicked()),this,SLOT(cofnijRuch()));
            }
            jestKlikniete = false;
            odznaczWcisnietyPrzycisk();

        }


    }

}
//##################################
// Z NAZWY POLA POBIERAMY OSTATNIE DWA ZNAKI KTORE BEDA INTERPRETOWANE JAKO WSPOLRZEDNE X I Y DANEGO POLA W PROGRAMIE
pair <int, int> MainWindow::pobierzPozycje(string nazwapola)
{
    int x = stoi(nazwapola.substr((nazwapola.length() - 2),1));
    int y = stoi(nazwapola.substr((nazwapola.length() - 1),1));
    return pair <int, int> (x,y);
}
//##################################
//PRZESTAJEMY PODSWIETLAC WCZESNIEJ KLIKNIETY PRZYCISK
void MainWindow::odznaczWcisnietyPrzycisk() {
    for(int i = 0; i < 8; i ++){
        for (int j = 0; j < 8; j ++) {
            QPushButton *przycisk = pobierzPrzycisk(i,j);
            if((i+j) % 2 == 0 )
                przycisk->setStyleSheet("QPushButton {background-color: #FFFFFF;}");
            else
                przycisk->setStyleSheet("QPushButton {background-color: #006699;}");
        }
    }
}
//##################################
//METODA PODSWIETLAJACA MIEJSCA W KTORE MOZEMY PORUSZYC SIE DANA FIGURA
void MainWindow::podswietlMozliweRuchy(vector<pair<int, int>> mozliwePozycje)
{
    for (auto & i : mozliwePozycje) {
        if(poleJestPuste(i))
            pobierzPrzycisk(i.first, i.second)->setStyleSheet("QPushButton {background-color: #FAEBD7;}");//PODSWIETLAMY NA ZOLTO
        if(toFiguraPrzeciwnika(i))
            pobierzPrzycisk(i.first, i.second)->setStyleSheet("QPushButton {background-color: #800000;}");//PODSWIETLAMY NA CZERWONO
    }

}
//##################################
//METODA ZWRACAJACA PRAWDE W PRZYPADKU NAPOTKANIA NA KLIKNIETYM POLU FIGURY PRZECIWNIKA
bool MainWindow::toFiguraPrzeciwnika(pair<int,int> pozycjaKoncowa) {
    Kolor c = gra->pobierzPlansze()->pobierzPole(pozycjaKoncowa.first, pozycjaKoncowa.second)->pobierzFigura()->pobierzKolor();
    if(c != gra->pobierzObecnyRuch() && c != NIEWIDZIALNY)
        return true;
    return false;
}
//##################################
//METODA ZWRACAJACA PRAWDE W PRZYPADKU KIEDY POLE O DANYCH WSPOLRZEDNYCH(pair<int,int> pozycjaKoncowa) JEST PUSTE
bool MainWindow::poleJestPuste(pair<int,int> pozycjaKoncowa) {
    if (dynamic_cast<PustePole*>(gra->pobierzPlansze()->pobierzPole(pozycjaKoncowa.first, pozycjaKoncowa.second)->pobierzFigura()))
        return true;
    return false;
}
//##################################
//METODA ZWRACAJACA PRAWDE GDY MOZEMY RUSZYC SIE NA POLE , NA KTORE CHCEMY
bool MainWindow::maRuch()
{//iterujemy po mozliwych pozycjach, szukajac  pozycji na ktora chcemy sie ruszyc (pozycjaPozadanegoRuchu)
 // jezeli pozycja na ktora chcemy sie ruszyc jest rózna od pozycji startowej wtedy zwracamy true
    if(std::find(mozliwePozycje.begin(), mozliwePozycje.end(), gra->pobierzPozycjaPozadanegoRuchu()) != mozliwePozycje.end())
       return true;
    return false;
}
//##################################
//AKTUALIZACJA IKON NA DANYCH PRZYCISKACH, ZMIANA GRACZA KTORY WYKONUJE RUCH ORAZ SPRAWDZANIE CZY GRA ZOSTALA SKONCZONA
void MainWindow::aktualizujGre()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            QPushButton *przycisk = pobierzPrzycisk(i, j);
            przycisk->setIcon(QIcon(""));
            przycisk->setIcon(QIcon(QString::fromStdString(gra->pobierzPlansze()->pobierzPole(i, j)->pobierzFigura()->pobierzNazweIkony())));
        }
    }
    czyGraSkonczona();
    ustawObecnyRuchNaPlanszy();
}
//##################################
// W PRZYPADKU WYGRANEJ KTOREJS ZE STRON WYSWIETLA KOMUNIKAT O WYGRANEJ
void MainWindow::czyGraSkonczona()
{
    if(gra->pobierzInformacjeKoniecGry() == true)
    {
        QString wiadomosc;

        if(gra->pobierzObecnyRuch() == BIALY)
        {
            wiadomosc = "PARTIE WYGRALY BIERKI BIALE!!!";
            QString napis = QString::fromStdString("PARTIA WYGRANA PRZEZ BIERKI BIALE PRZEZ ZAMATOWANIE BIALEGO KROLA!!!");
            MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append(napis);
        }
        else if(gra->pobierzObecnyRuch() == CZARNY)
        {
            wiadomosc = "PARTIE WYGRALY BIERKI CZARNE!!!";
            QString napis = QString::fromStdString("PARTIA WYGRANA PRZEZ BIERKI CZARNE PRZEZ ZAMATOWANIE CZARNEGO KROLA!!!");
            MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append(napis);
        }
        qDebug()<< wiadomosc;
        QMessageBox::about(this,"Koniec gry!!!", wiadomosc);
        //ZATRZYMANIE PLANSZY I BRAK MOZLIWOSCI RUCHOW
        gra->zatrzymajPlansze();
        if(gra->pobierzZatrzymanieGry() == true)
        {
            disconnect(MainWindow::findChild<QPushButton *>("Poddanie"),SIGNAL(clicked()),this,SLOT(poddajSie()));
            disconnect(MainWindow::findChild<QPushButton *>("Remis"),SIGNAL(clicked()),this,SLOT(zremisuj()));
            disconnect(MainWindow::findChild<QPushButton *>("Cofanie"),SIGNAL(clicked()),this,SLOT(cofnijRuch()));
            //TROCHE NA ŁATWIZNE POLECIALEM ALE NWM CZEMU WCZESNIEJ NIE GRALO DLATEGO ZROBILEM TAK
            MainWindow::findChild<QPushButton *>("Cofanie")->setDisabled(true);
        }


    }
}
//##################################
//METODA ODPOWIEDZIALNA ZA WYCHODZENIE Z GRY
void MainWindow::wyjdzZGry()
{
    QApplication::quit();
}
//##################################
//METODA ODPOWIEDZIALNA ZA ROZPOCZYNANIE GRY OD NOWA
void MainWindow::zacznijOdNowa()
{
    //https://forum.qt.io/topic/104271/how-to-restart-an-application-by-pressing-a-button/3
    //znalezione na forum Qt, dopytac co to oznacza
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());

}
//##################################
//METODA ODPOWIEDZIALNA ZA PODDAWANIE SIE GRACZA, KTORY OBECNIE POWINIEN SIE PORUSZYC
void MainWindow::poddajSie()
{

    QString wiadomosc;

    if(gra->pobierzObecnyRuch() == CZARNY)
    {
         wiadomosc = "CZARNE SIE PODDALY, PARTIE WYGRALY BIERKI BIALE!!!";
         QString napis = QString::fromStdString("CZARNE SIE PODDALY, PARTIA WYGRANA PRZEZ BIERKI BIALE!!!");
         MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append(napis);
    }
    else if(gra->pobierzObecnyRuch() == BIALY)
    {
        wiadomosc = "BIALE SIE PODDALY, PARTIE WYGRALY BIERKI CZARNE!!!";
        QString napis = QString::fromStdString("BIALE SIE PODDALY, PARTIA WYGRANA PRZEZ BIERKI CZARNE!!!");
        MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append(napis);
    }
    qDebug()<< wiadomosc;
    QMessageBox::about(this,"Koniec gry!!!", wiadomosc);
    gra->zatrzymajPlansze();

    //JEZELI GRACZ SIE PODDA ROZLACZAM POLACZANIE POMIEDZY PRZYCISKAMI ABY NIE MOZNA BYLO WYWOLAC PONOWNIE METOD POZWALAJACYCH SIE PODDAC BADZ ZAPROPONOWAC REMIS
    disconnect(MainWindow::findChild<QPushButton *>("Poddanie"),SIGNAL(clicked()),this,SLOT(poddajSie()));
    disconnect(MainWindow::findChild<QPushButton *>("Remis"),SIGNAL(clicked()),this,SLOT(zremisuj()));
    disconnect(MainWindow::findChild<QPushButton *>("Cofanie"),SIGNAL(clicked()),this,SLOT(cofnijRuch()));


}
//##################################
//METODA ODPOWIEDZIALNA ZA TWORZENIE ZAPYTANIA O REMIS
void MainWindow::zremisuj()
{
 //TWORZYMY NOWY OBIEKT KLASY DrawWindow
 DrawWindow b ;
 //USTAWIAMY TO OKNO JAKO GLOWNE TZN BEZ JEGO ZAMKNIECIA NIE MOZEMY ROBIC NIC NA PLANSZY
 //https://www.youtube.com/watch?v=jgMhzRXemC8
 b.setModal(true);
 b.exec();

 if(gra->pobierzZatrzymanieGry() == true)
 {
     QString napis = QString::fromStdString("PARTIA ZAKONCZONA REMISEM!!!");
     MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append(napis);

     disconnect(MainWindow::findChild<QPushButton *>("Poddanie"),SIGNAL(clicked()),this,SLOT(poddajSie()));
     disconnect(MainWindow::findChild<QPushButton *>("Remis"),SIGNAL(clicked()),this,SLOT(zremisuj()));
     disconnect(MainWindow::findChild<QPushButton *>("Cofanie"),SIGNAL(clicked()),this,SLOT(cofnijRuch()));
 }

}
//##################################
//METODA ODPOWIEDZIALNA ZA DOPISYWANIE WYKONANEGO OSTATNIO RUCHU DO PANELU HISTORII RUCHOW W OKNIE APLIKACJI
void MainWindow::wyswietlHistorieRuchowNaPanelu(pair<int,int> pozycja)
{

    int tmp = 8;
    int x = tmp-pozycja.first;
    char y = static_cast <char>(pozycja.second +65);
    string s = "";
    s = s + y;



    if(gra->pobierzNumerPosuniecia() % 2 == 1)
    {   // DODAJEMY DO PANELU HISTORII RUCHOW OSTATNIO WYKONANY RUCH
        QString napis = QString::fromStdString(to_string(gra->pobierzNumerPosuniecia())+".Posuniecie:"+"("+s+to_string(x)+") -> BIERKI BIALE");
        MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append(napis);
    }
    else if(gra->pobierzNumerPosuniecia() % 2 == 0)
    {   // DODAJEMY DO PANELU HISTORII RUCHOW OSTATNIO WYKONANY RUCH
        QString napis = QString::fromStdString(to_string(gra->pobierzNumerPosuniecia())+".Posuniecie:"+"("+s+to_string(x)+") -> BIERKI CZARNE");
        MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append(napis);
    }

}
//##################################
//METODA ODPOWIEDZIALNA ZA COFANIE RUCHOW
void MainWindow::cofnijRuch()
{

    if(gra->pobierzNumerPosuniecia()==0) //JEZELI LICZNIK POSUNIEC JEST ROWNY ZERO TZN ZE NIE WYKONALISMY ZADNEGO RUCHU DLATEGO TEZ NIE MOZEMY DOKONAC COFNIECIA
    {
        qDebug()<<"NIE MOZEMY COFNAC RUCHOW, PONIEWAZ ZADEN NIE ZOSTAL WYKONANY";
    }
    else if(gra->pobierzNumerPosuniecia()>0)//JEZELI LICZNIK POSUNIEC JEST WIEKSZY OD ZERA WTEDY MOZEMY DOKONAC COFNIECIA
    {
        qDebug()<<"TU JUZ MOZEMY COFNAC RUCH";

        // ROZLACZAMY POLACZENIE PONIEWAZ ZALOZENIEM GRY JEST MOZLIWOSC COFANIA O JEDEN RUCH WSTECZ TYLKO
        disconnect(MainWindow::findChild<QPushButton *>("Cofanie"),SIGNAL(clicked()),this,SLOT(cofnijRuch()));

        gra->ustawNumerPosuniecia(-1); //ZMNIEJSZENIE LICZBY WYKONANYCH POSUNIEC O JEDEN I USTAWIENIE ODPOWIEDNIEJ TURY
        gra->ustawNumerTury();

        MainWindow::findChild<QLCDNumber *>("NumerTury")->display(gra->pobierzNumerTury()); //AKTUALIZACJA LICZNIKA TUR W OKNIE APLIKACJI

        //TU COS NIE GRA JAKBYM DZIALAL NA KOPII A NIE NA ORYGINALE

        //gra->pobierzHistorieRuchow().pop_back();
        //qDebug()<<gra->pobierzHistorieRuchow().size();
        //gra->pobierzHistoriePozycjiPoczatkowych().pop_back();
        //qDebug()<<gra->pobierzHistorieRuchow().size();

        //DODANIE KOMUNIKATU DO HISTORII RUCHOW O TYM ZE OSTATNI ZOSTAL COFNIETY
        MainWindow::findChild<QTextEdit *>("PanelHistoriiRuchow")->append("COFNIECIE RUCHU->Powyzszy ruch został cofniety!!!");

        //LWIA CZESC COFANIA RUCHOW
        // PRZESUWAMY FIGURE KTORA OSTATNIO WYKONALISMY RUCH Z JEJ POZYCJI KONCOWEJ NA POZYCJE Z KTOREJ SIE RUSZALA POCZATKOWO
        qDebug()<<gra->pobierzHistorieRuchow().back();
        qDebug()<<gra->pobierzHistoriePozycjiPoczatkowych().back();

        //COFANIE RUCHU
        //1) FIGURE KTORA SIE RUSZYLISMY USTAWIAMY NA POLU Z KTOREGO STARTOWALA
        gra->pobierzPlansze()->przesunFigure(gra->pobierzHistorieRuchow().back(), gra->pobierzHistoriePozycjiPoczatkowych().back());

        // 2)POBIERAMY SOBIE POLE NA KTORE ZOSTAL WYKONANY RUCH W OSTATNIM POSUNIECIU
        Pole *poleKoncowe = gra->pobierzPlansze()->pobierzPole(gra->pobierzHistorieRuchow().back().first,gra->pobierzHistorieRuchow().back().second);
        //3)POBIERAMY FIGURE JAKA BYLA ZBITA PODCZAS OSTATNIEGO RUCHU
        Figura * figura = gra->pobierzOstatnioZbitaFigure();

        //4)NASTEPNIE NA TYM POLU USTAWIAMY ZBITĄ FIGURE, KTORA JEST PRYWATNYM ATRYBUTEM KLASY GRA
        // RZUTOWANIE W SPOSOB DYNAMICZNY,NIE WIEM CZY JEST TO POTRZEBNE W PRZYPADKU GDY ZNAMY RODZAJ FIGURY KTORA ZBILISMY
        if(figura->pobierzKolor() == CZARNY)
       {
           if(dynamic_cast<Wieza*>(figura))
           {poleKoncowe->ustawFigure(new Wieza(), CZARNY, ":/zdjecia/wieza_czarna.png");}
           if(dynamic_cast<Skoczek*>(figura))
           {poleKoncowe->ustawFigure(new Skoczek(), CZARNY, ":/zdjecia/skoczek_czarny.png");}
           if(dynamic_cast<Goniec*>(figura))
           {poleKoncowe->ustawFigure(new Goniec(), CZARNY, ":/zdjecia/goniec_czarny.png");}
           if(dynamic_cast<Hetman*>(figura))
           {poleKoncowe->ustawFigure(new Hetman(), CZARNY, ":/zdjecia/hetman_czarny.png");}
           if(dynamic_cast<Krol*>(figura))
           {poleKoncowe->ustawFigure(new Krol(), CZARNY, ":/zdjecia/krolowa_czarna.png");}
           if(dynamic_cast<Pion*>(figura))
           {poleKoncowe->ustawFigure(new Pion(), CZARNY, ":/zdjecia/pion_czarny.png");}
       }
       else if(figura->pobierzKolor() == BIALY)
       {
           if(dynamic_cast<Wieza*>(figura))
           {poleKoncowe->ustawFigure(new Wieza(), BIALY, ":/zdjecia/wieza_biala.png");}
           if(dynamic_cast<Skoczek*>(figura))
           {poleKoncowe->ustawFigure(new Skoczek(), BIALY, ":/zdjecia/skoczek_bialy.png");}
           if(dynamic_cast<Goniec*>(figura))
           {poleKoncowe->ustawFigure(new Goniec(), BIALY, ":/zdjecia/goniec_bialy.png");}
           if(dynamic_cast<Hetman*>(figura))
           {poleKoncowe->ustawFigure(new Hetman(), BIALY, ":/zdjecia/hetman_bialy.png");}
           if(dynamic_cast<Krol*>(figura))
           {poleKoncowe->ustawFigure(new Krol(), BIALY, ":/zdjecia/krolowa_biala.png");}
           if(dynamic_cast<Pion*>(figura))
           {poleKoncowe->ustawFigure(new Pion(), BIALY, ":/zdjecia/pion_bialy.png");}
        }
        else if(figura->pobierzKolor() == NIEWIDZIALNY)//ZBEDNE ALE ROBIE TO DLA BEZPIECZENSTWA
        {
            if(dynamic_cast<PustePole*>(figura))
            {poleKoncowe->ustawFigure(new PustePole(), NIEWIDZIALNY, "");}
        }


        if(dynamic_cast<Pion*>(gra->pobierzOstatnioPoruszonaFigura() ) && (gra->pobierzPozycjaPozadanegoRuchu().first == 0 || gra->pobierzPozycjaPozadanegoRuchu().first == 7 ))
        {
            Pole *polePoczatkowe = gra->pobierzPlansze()->pobierzPole(gra->pobierzHistoriePozycjiPoczatkowych().back().first,gra->pobierzHistoriePozycjiPoczatkowych().back().second);

            if(gra->pobierzOstatnioPoruszonaFigura()->pobierzKolor() == CZARNY)
            {
                polePoczatkowe->ustawFigure(new Pion(), CZARNY, ":/zdjecia/pion_czarny.png");
            }
            else if(gra->pobierzOstatnioPoruszonaFigura()->pobierzKolor() == BIALY)
            {
                polePoczatkowe->ustawFigure(new Pion(), BIALY, ":/zdjecia/pion_bialy.png");
            }
        }

        aktualizujGre();
    }
}
//##################################
//METODA USTAWIAJACA ZMIENNA PRYWATNA KLASY MAINWINDOW mozliwePozycje
void MainWindow:: ustawMozliwePozycje(vector<pair<int,int>> pozycje)
{
    this->mozliwePozycje = pozycje;
}

