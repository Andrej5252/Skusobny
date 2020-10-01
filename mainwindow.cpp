#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>

#include "kontakt_edit_dialog.h"

const QString SAVING_VERSION = "Version 1.0.0";
const QString SAVE_FILENAME = "kontakty.txt";

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  nacitajKontakty();

  obnovZobrazenie();
}

MainWindow::~MainWindow()
{
  ulozKontakty();

  delete ui;
}

void MainWindow::ulozKontakty()
{
  QFile file(SAVE_FILENAME);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    QTextStream out(&file);

    out << SAVING_VERSION << endl;

    for (Kontakt k : kontakty) {
      k.ulozSa(out);
    }
  }
}

void MainWindow::nacitajKontakty()
{
  QFile file(SAVE_FILENAME);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream in(&file);
    QString verzia = in.readLine();

    if (verzia == SAVING_VERSION)
    {
      while (!in.atEnd()) {
        QString line = in.readLine();
        Kontakt novyKontakt;

        novyKontakt.nacitajSa(line);

        kontakty.append(novyKontakt);
      }
    }
    else
    {
      QMessageBox::warning(this, "Zlý formát súboru", "Kontakty sa nepodarilo načítať.");
    }
  }
}

void MainWindow::obnovZobrazenie()
{
  ui->zoznamKontaktov->clear();

  for (Kontakt aktualny : kontakty){
    ui->zoznamKontaktov->addItem(aktualny.toString() + ", " + aktualny.cisloMobil() + ", " + aktualny.email());
  }
}

void MainWindow::on_actionPridaj_triggered()
{
  KontaktEditDialog editDialog(this);

  int vysledok = editDialog.exec();


  if (vysledok == QDialog::Accepted) {
    Kontakt pridavanyKontakt = editDialog.dajKontakt();
    kontakty.append(pridavanyKontakt);
    obnovZobrazenie();
  }
}

void MainWindow::on_actionVymazat_triggered()
{
  if (kontakty.isEmpty() == false){
    QList<QListWidgetItem *> oznacenePolozky = ui->zoznamKontaktov->selectedItems();
    if (oznacenePolozky.size() > 0) {
      int indexKontaktu = ui->zoznamKontaktov->currentRow();

      int ret = QMessageBox::information(this,
                                         "Naozaj chceš vymazať?",
                                         "Naozaj chceš vymazať kontakt: " + kontakty.at(indexKontaktu).toString(),
                                         QMessageBox::Yes | QMessageBox::No,
                                         QMessageBox::No);

      if (ret == QMessageBox::Yes){
        kontakty.removeAt(indexKontaktu);
        obnovZobrazenie();
      }
    } else {
      QMessageBox::warning(this,
                           "Nie je zvolený kontakt",
                           "Ak chceš vymazať, musíš najprv vybrať, čo chceš vymazať.");
    }
  }
}

void MainWindow::on_actionUpravit_triggered()
{
  if (kontakty.isEmpty() == false) {
    QList<QListWidgetItem *> oznacenePolozky = ui->zoznamKontaktov->selectedItems();
    if (oznacenePolozky.size() > 0) {
      int indexKontaktu = ui->zoznamKontaktov->currentRow();
      KontaktEditDialog editDialog(kontakty.at(indexKontaktu), this);

      int vysledok = editDialog.exec();

      if (vysledok == QDialog::Accepted) {
        Kontakt editovanyKontakt = editDialog.dajKontakt();
        kontakty.replace(indexKontaktu, editovanyKontakt);
        obnovZobrazenie();
      }
    } else {
      QMessageBox::warning(this,
                           "Nie je zvolený kontakt",
                           "Ak chceš upraviť, musíš najprv vybrať, čo chceš upraviť.");
    }
  }
}

void MainWindow::on_actionZobrazi_triggered()
{
    if (kontakty.isEmpty() == false) {
      QList<QListWidgetItem *> oznacenePolozky = ui->zoznamKontaktov->selectedItems();
      if (oznacenePolozky.size() > 0) {
          int indexKontaktu = ui->zoznamKontaktov->currentRow();
          QMessageBox::information(this,
                               "Informácie o kontakte",
                               "" + kontakty.at(indexKontaktu).toStringdetail());

      }
    }
}
