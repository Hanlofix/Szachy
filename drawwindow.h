#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QDialog>
#include "QMessageBox"
#include <gra.h>
\
namespace Ui {
class DrawWindow;
}

/**
 * @file drawwindow.h
 * @author Tomasz Wardak
 * @brief Klasa odpowiedzialna za obsluge okna Remisu
 * @date 31-05-2022
 */

class DrawWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DrawWindow(QWidget *parent = nullptr);
    ~DrawWindow();

private:
    Ui::DrawWindow *ui;

private slots:
    /**
     * @brief Metoda odpowiedzialna za oglaszanie remisu i przerywanie gry
     * @return void
     */
    void przyjmijRemis();
    /**
     * @brief Metoda odpowiedzialna za odrzucanie remisu i kontynuacje gry bez zmian
     * @return void
     */
    void odrzucRemis();
};

#endif // DRAWWINDOW_H
