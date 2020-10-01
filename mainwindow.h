#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "kontakt.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  Ui::MainWindow *ui;
  QList<Kontakt> kontakty;

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
    void ulozKontakty();
    void nacitajKontakty();
    void obnovZobrazenie();

private slots:
  void on_actionPridaj_triggered();

  void on_actionVymazat_triggered();

  void on_actionUpravit_triggered();


  void on_actionZobrazi_triggered();
};

#endif // MAINWINDOW_H
