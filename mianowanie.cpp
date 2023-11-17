#include "mianowanie.h"
#include "ui_mianowanie.h"
#include "gra.h"

using namespace std;
extern Gra *gra;

//##################################
// KONSTRUKTOR KLASY MIANOWANIE
Mianowanie::Mianowanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mianowanie)
{
    ui->setupUi(this);

    setWindowTitle("OKNO MIANOWANIA");

    //WYSZUKUJEMY WSKAZNIK NA panelZapytania
    QTextEdit* panel = Mianowanie::findChild<QTextEdit*>("PanelZapytania");
    panel->setText("WYBIERZ FIGURE DO MIANOWANIA:");

    //USTAWIAJAC ODPOWIEDNIE FLAGI BLOKUJEMY MOZLIWOSC WYJSCIA Z OKNA BEZ KLIKNIECIA KTOREJS Z FIGUR
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint);

    //POBIERAMY WSKAZNIKI DO PRZYCISKOW MIANOWANIA
    QPushButton* przyciskSkoczek = Mianowanie::findChild<QPushButton*>("przyciskSkoczek");
    QPushButton* przyciskGoniec = Mianowanie::findChild<QPushButton*>("przyciskGoniec");
    QPushButton* przyciskWieza = Mianowanie::findChild<QPushButton*>("przyciskWieza");
    QPushButton* przyciskHetman = Mianowanie::findChild<QPushButton*>("przyciskHetman");

    if(gra->pobierzObecnyRuch() == CZARNY)
    {
        przyciskSkoczek->setIcon(QIcon(QString::fromStdString(":/zdjecia/skoczek_czarny.png")));
        przyciskGoniec->setIcon(QIcon(QString::fromStdString(":/zdjecia/goniec_czarny.png")));
        przyciskWieza->setIcon(QIcon(QString::fromStdString(":/zdjecia/wieza_czarna.png")));
        przyciskHetman->setIcon(QIcon(QString::fromStdString(":/zdjecia/hetman_czarny.png")));
    }
    else if(gra->pobierzObecnyRuch() == BIALY)
    {
        przyciskSkoczek->setIcon(QIcon(QString::fromStdString(":/zdjecia/skoczek_bialy.png")));
        przyciskGoniec->setIcon(QIcon(QString::fromStdString(":/zdjecia/goniec_bialy.png")));
        przyciskWieza->setIcon(QIcon(QString::fromStdString(":/zdjecia/wieza_biala.png")));
        przyciskHetman->setIcon(QIcon(QString::fromStdString(":/zdjecia/hetman_bialy.png")));
    }

    connect(przyciskSkoczek,SIGNAL(clicked()),this,SLOT(mianujSkoczka())); //POLACZENIE PRZYCISKU "przyciskSkoczek" Z METODA ODPOWIEDZIALNA ZA MIANOWANIE SKOCZKA
    connect(przyciskGoniec,SIGNAL(clicked()),this,SLOT(mianujGonca())); //POLACZENIE PRZYCISKU "przyciskGoniec" Z METODA ODPOWIEDZIALNA ZA MIANOWANIE GONCA
    connect(przyciskWieza,SIGNAL(clicked()),this,SLOT(mianujWieze())); //POLACZENIE PRZYCISKU "przyciskWieza" Z METODA ODPOWIEDZIALNA ZA MIANOWANIE WIEZY
    connect(przyciskHetman,SIGNAL(clicked()),this,SLOT(mianujHetmana())); //POLACZENIE PRZYCISKU "przyciskHetman" Z METODA ODPOWIEDZIALNA ZA MIANOWANIE HETMANA

}
//##################################
//DESTRUKTOR KLASY MIANOWANIE
Mianowanie::~Mianowanie()
{
    delete ui;
}
//##################################
// METODA ODPOWIEDZIALNA ZA MIANOWANIE PIONA NA SKOCZKA
void Mianowanie::mianujSkoczka()
{
    if(gra->pobierzObecnyRuch() == CZARNY)
    {
         gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Skoczek(), CZARNY, ":/zdjecia/skoczek_czarny.png");
    }
    else if(gra->pobierzObecnyRuch() == BIALY)
    {
     gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Skoczek(), BIALY, ":/zdjecia/skoczek_bialy.png");
    }
    this->close();
}
//##################################
// METODA ODPOWIEDZIALNA ZA MIANOWANIE PIONA NA GONCA
void Mianowanie::mianujGonca()
{
    if(gra->pobierzObecnyRuch() == CZARNY)
    {
         gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Goniec(), CZARNY, ":/zdjecia/goniec_czarny.png");
    }
    else if(gra->pobierzObecnyRuch() == BIALY)
    {
     gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Goniec(), BIALY, ":/zdjecia/goniec_bialy.png");
    }
    this->close();
}
//##################################
// METODA ODPOWIEDZIALNA ZA MIANOWANIE PIONA NA WIEZE
void Mianowanie::mianujWieze()
{
    if(gra->pobierzObecnyRuch() == CZARNY)
    {
         gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Wieza(), CZARNY, ":/zdjecia/wieza_czarna.png");
    }
    else if(gra->pobierzObecnyRuch() == BIALY)
    {
     gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Wieza(), BIALY, ":/zdjecia/wieza_biala.png");
    }
    this->close();
}
//##################################
// METODA ODPOWIEDZIALNA ZA MIANOWANIE PIONA NA HETMANA
void Mianowanie::mianujHetmana()
{
    if(gra->pobierzObecnyRuch() == CZARNY)
    {
         gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Hetman(), CZARNY, ":/zdjecia/hetman_czarny.png");
    }
    else if(gra->pobierzObecnyRuch() == BIALY)
    {
     gra->pobierzPlansze()->pobierzPole(gra->pobierzPozycjaPozadanegoRuchu().first,gra->pobierzPozycjaPozadanegoRuchu().second)->ustawFigure(new Hetman(), BIALY, ":/zdjecia/hetman_bialy.png");
    }

    this->close();
}
//##################################
