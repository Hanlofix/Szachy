#include "drawwindow.h"
#include "ui_drawwindow.h"
#include "gra.h"
#include <QDebug>
#include <QProcess>

using namespace std;
extern Gra *gra;


//##################################
//KONSTRUKTOR KLASY DrawWindow
DrawWindow::DrawWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawWindow)
{
    ui->setupUi(this);

    //USTAWIAMY TYTUL OKNA
    setWindowTitle("ZAPYTANIE O REMIS");
    //WYSZUKANIE PANELU ZAPYTANIA W NASZYM FORMULARZU drawwindow.ui I ZWROCENIE WSKAZNIKA NA NIEGO
    QTextEdit *panelZapytania = DrawWindow::findChild<QTextEdit *>("PanelZapytania");
    //USTAWIENIE ZAPYTANIA O REMIS W PANELU ZAPYTANIA
    panelZapytania->setText("CZY PRZECIWNIK ZGADZA SIĘ NA REMIS?");

    QPushButton *przyciskTak = DrawWindow::findChild<QPushButton *>("przyciskTak");
    QPushButton *przyciskNie = DrawWindow::findChild<QPushButton *>("przyciskNie");
    connect(przyciskTak,SIGNAL(clicked()),this,SLOT(przyjmijRemis())); // POLACZENIE PRZYCISKU "przyciskTak" Z METODA ODPOWIEDZIALNA ZA OGLOSZENIE REMISU I ZATRZYMANIE PLANSZY
    connect(przyciskNie,SIGNAL(clicked()),this,SLOT(odrzucRemis()));   // POLACZENIE PRZYCISKU "przyciskNie" Z METODA ODPOWIEDZIALNA ZA POWROT DO PLANSZY

}
//##################################
//DESTRUKTOR KLASY DrawWindow
DrawWindow::~DrawWindow()
{
    delete ui;
}
//##################################
//METODA ODPOWIEDZIALNA ZA OGLASZANIE REMISU I PRZERYWANIE GRY
void DrawWindow::przyjmijRemis()
{   // ZA POMOCA WSKAZNIKA NA OBIEKT DLA KTOREGO ZOSTALA WYWOWLANA METODA PRZYJMIJ REMIS ZAMYKAM OKNO REMISU
    this->close();
    QString wiadomosc;
    wiadomosc = "PARTIA ZAKONCZONA REMISEM!!!";
    qDebug()<< wiadomosc;
    QMessageBox::about(this,"Koniec gry!!!", wiadomosc);
    gra->zatrzymajPlansze();


}
//##################################
//METODA ODPOWIEDZIALNA ZA ODRZUCANIE REMISU I KONTYNUJACJE GRY BEZ ZMIAN
void DrawWindow::odrzucRemis()
{
    this->close();
}
