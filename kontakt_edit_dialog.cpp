#include "kontakt_edit_dialog.h"
#include "ui_kontakt_edit_dialog.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>



KontaktEditDialog::KontaktEditDialog(QWidget *parent)
  : KontaktEditDialog(Kontakt(), parent)
{
}

KontaktEditDialog::KontaktEditDialog(Kontakt kontakt, QWidget *parent)
  : QDialog(parent)
  , ui(new Ui::KontaktEditDialog)
{
  ui->setupUi(this);

  ui->txtTitul->setText(kontakt.titul());
  ui->txtMeno->setText(kontakt.meno());
  ui->txtPriezvisko->setText(kontakt.priezvisko());
  ui->txtPrezyvka->setText(kontakt.prezyvka());
  ui->datumNarodenia->setDate(kontakt.datumNarodenia());
  ui->txtCisloMobil->setText(kontakt.cisloMobil());
  ui->txtCisloTelefon->setText(kontakt.cisloTelefon());
  ui->txtEmail->setText(kontakt.email());
  ui->txtAdresa->setText(kontakt.adresa());
  ui->txtFirma->setText(kontakt.nazovFirmy());

}

KontaktEditDialog::~KontaktEditDialog()
{


  delete ui;
}

Kontakt KontaktEditDialog::dajKontakt()
{
  Kontakt kontaktNaVratenie;

  kontaktNaVratenie.setTitul(ui->txtTitul->text());
  kontaktNaVratenie.setMeno(ui->txtMeno->text());
  kontaktNaVratenie.setPriezvisko(ui->txtPriezvisko->text());
  kontaktNaVratenie.setPrezyvka(ui->txtPrezyvka->text());
  kontaktNaVratenie.setDatumNarodenia(ui->datumNarodenia->date());
  kontaktNaVratenie.setCisloMobil(ui->txtCisloMobil->text());
  kontaktNaVratenie.setCisloTelefon(ui->txtCisloTelefon->text());
  kontaktNaVratenie.setEmail(ui->txtEmail->text());
  kontaktNaVratenie.setAdresa(ui->txtAdresa->text());
  kontaktNaVratenie.setNazovFirmy(ui->txtFirma->text());

  return kontaktNaVratenie;
}




void KontaktEditDialog::on_btnSave_clicked()
{
//  Kontakt novyKontakt;

//  novyKontakt.setMeno(ui->txtMeno->text());
//  novyKontakt.setPriezvisko(ui->txtPriezvisko->text());
//  novyKontakt.setTitul(ui->txtTitul->text());
//  novyKontakt.setPrezyvka(ui->txtPrezyvka->text());
//  novyKontakt.setCisloMobil(ui->txtCisloMobil->text());
//  novyKontakt.setCisloTelefon(ui->txtCisloTelefon->text());
//  novyKontakt.setEmail(ui->txtEmail->text());
//  novyKontakt.setAdresa(ui->txtAdresa->text());
//  novyKontakt.setNazovFirmy(ui->txtFirma->text());
//  novyKontakt.setDatumNarodenia(ui->datumNarodenia->date());

//  kontakty.append(novyKontakt);
}

void KontaktEditDialog::on_btnPrint_clicked()
{
  QString outText;
  //    int pocetKontaktov = kontakty.size();

//  for (Kontakt k : kontakty) {
//    outText += k.toString() + "\n";
//  }

  //    for (int i = 0; i < pocetKontaktov; i++) {
  //        outText += kontakty[i].meno() + " " + kontakty[i].priezvisko() + "\n";
  //    }


  //    int i = 0;
  //    while (i < pocetKontaktov){
  //        outText += kontakty[i].meno() + " " + kontakty[i].priezvisko() + "\n";

  //        i++;
  //    }

  QMessageBox::information(this, "Print", outText);
}
