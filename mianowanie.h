#ifndef MIANOWANIE_H
#define MIANOWANIE_H

#include <QDialog>

namespace Ui {
class Mianowanie;
}
/**
 * *@file mianowanie.h
 * @author Tomasz Wardak
 * @brief Klasa odpowiedzialna za mianowanie i obsluge okna mianowania
 * @date 31-05-2022
 */


class Mianowanie : public QDialog
{
    Q_OBJECT

public:
    explicit Mianowanie(QWidget *parent = nullptr);
    ~Mianowanie();

private:
    Ui::Mianowanie *ui;

private slots:
    /**
     * @brief Metoda odpowiedzialna za mianowanie Piona na Skoczka
     * @return void
     */
    void mianujSkoczka();
    /**
     * @brief Metoda odpowiedzialna za mianowanie Piona na Gonca
     * @return void
     */
    void mianujGonca();
    /**
     * @brief Metoda odpowiedzialna za mianowanie Piona na Wieze
     * @return void
     */
    void mianujWieze();
    /**
     * @brief Metoda odpowiedzialna za mianowanie Piona na Hetmana
     * @return void
     */
    void mianujHetmana();
};

#endif // MIANOWANIE_H
