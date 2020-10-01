#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "kontakt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class KontaktEditDialog; }
QT_END_NAMESPACE

class KontaktEditDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::KontaktEditDialog *ui;


public:
    KontaktEditDialog(QWidget *parent = nullptr);
    KontaktEditDialog(Kontakt kontakt, QWidget *parent = nullptr);
    ~KontaktEditDialog();

    Kontakt dajKontakt();


private slots:
    void on_btnSave_clicked();
    void on_btnPrint_clicked();
};
#endif // DIALOG_H
