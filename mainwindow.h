#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <gra.h>
#include <algorithm>
#include "QPushButton"
#include "QMessageBox"
#include <fstream>


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/**
 * @file mainwindow.h
 * @author Tomasz Wardak
 * @brief The MainWindow class
 * @date 31-05-2022
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief Metoda odpowiedzialna za zmiane wykonawcy ruchu oraz zmiane strzalek na panelu gry
     * @return void
     */
    void ustawObecnyRuchNaPlanszy();


private:
    Ui::MainWindow *ui;
    //zmienna boolowska mowiaca o tym czy jakies pole jest klikniete
    bool jestKlikniete = false;
   //pokazuje wszystkie mozliwe pozycje jakie moze wykonac figura znajdujaca sie na danym polu
    vector< pair<int, int> > mozliwePozycje;

private slots:
    /**
     * @brief Metoda odpowiedzialna za wyszukiwanie konkretnego pola na panelu gry
     * @param x Przedostatni znak nazwy pola, rzutowany na typ potem na typ string
     * @param y Ostatni znak nazwy pola, rzutowany potem na typ string
     * @return Zwraca wskaznik na pole o konkretnych wspolrzednych
     */
    QPushButton *pobierzPrzycisk(int x, int y);
    /**
     * @brief Glowna metoda, gdzie po spelnieniu odpowiednich warunkow wywoywane sa metody odpowiedzialne za sprawdzaenie
     * wygranej, mozliwych do wykonania ruchow, zliczanie tur, czy wyswietlanie historii ruchow
     * @return voic
     */
    void kliknietoNaPole();
    /**
     * @brief Metoda pobierajca z nazwy pola dwa ostatnie znaki
     * @param nazwapola nazwa pola pobrana z pliku mainwindow.ui
     * @return zwraca dwa ostatnie znaki z nazwy pola i rzutuje je na typ integer
     */
    pair <int, int> pobierzPozycje(string nazwapola);
    /**
     * @brief Metoda przestajaca podswietlac wczesniej klikniety przycisk
     * @return void
     */
    void odznaczWcisnietyPrzycisk();
    /**
     * @brief Metoda sprawdzajaca, czy dane pole jest puste
     * @param wspolrzedne sprawdzanego pola
     * @return zwraca prawde, jezeli dane pole jest puste
     */

    bool poleJestPuste(pair<int,int> pozycjaKoncowa);
    /**
     * @brief Metoda sprawdzajaca, czy figura stojaca na danym polu nalezy do przeciwnika
     * @param pozycjaKoncowa wspolrzedne pola, na ktorym stoi figura
     * @return zwraca prawde, jezeli dana figura jest figura przeciwnika
     */
    bool toFiguraPrzeciwnika(pair<int,int> pozycjaKoncowa);
    /**
     * @brief Metoda podswietlajaca miejsca w ktore mozemy poruszyc sie dana figura
     * @param mozliwePozycje wektor zawierajacy pozycje, w ktore mozemy sie poruszyc dana figura
     */
    void podswietlMozliweRuchy(vector<pair<int, int>> mozliwePozycje);
    /**
     * @brief Metoda sprawdzajaca, czy mozemy sie ruszyc na pole na ktore chcemy
     * @return Zwraca prawde, gdy mozemy sie ruszyc na pole, na ktore chcemy
     */
    bool maRuch();
    /**
     * @brief Metoda odpowiedzialna za aktualizacje ikon na danych przyciskach
     * oraz za zmiane gracza ktory wykonuje ruch
     * @return void
     */
    void aktualizujGre();
    /**
     * @brief Metoda wyswietlajaca odpowiednie komunikaty na panelu gry w przypadku wygranej, ktorejs ze stron
     * @return void
     */
    void czyGraSkonczona();
    /**
     * @brief Metoda odpowiedzialna za wychodzenie z gry
     * @return void
     */
    void wyjdzZGry();
    /**
     * @brief Metoda odpowiedzialna za rozpoczynanie gry od nowa
     * @return void
     */
    void zacznijOdNowa();
    /**
     * @brief Metoda odpowiedzialna za poddawanie sie gracza, ktory obecnie wykonuje ruch
     * @return void
     */

    void poddajSie();
    /**
     * @brief Metoda odpowiedzialna za tworzenie zapytania o remis
     * @return void
     */
    void zremisuj();
    /**
     * @brief Metoda odpowiedzialna za dopisywanie ostatnio wykonanego ruchu do panelu historii ruchow w oknie apliakcji
     * @param pozycja wspolrzedne dopisywanej pozycji, w ktora sie ruszylismy figura
     * @return void
     */
    void wyswietlHistorieRuchowNaPanelu(pair<int,int> pozycja);
    /**
     * @brief Metoda odpowiedzialna za cofanie ruchow
     * @return void
     */
    void cofnijRuch();
    /**
     * @brief Metoda zapisujaca do zmiennej prywatnej wszystkie mozliwe pozycje, w ktore mozemy sie ruszyc dana figura
     * @param wektor zawierajacy wszystkie dostepne do ruchu pozycje
     * @return void
     */
    void ustawMozliwePozycje(vector<pair<int,int>> pozycje);

};
#endif // MAINWINDOW_H
