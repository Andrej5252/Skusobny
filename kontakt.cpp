#include "kontakt.h"

const char SAVING_SEPARATOR = ';';

Kontakt::Kontakt()
{
}

Kontakt::Kontakt(QString meno, QString priezvisko, QString titul, QString prezyvka,
                 QString cisloMobil, QString cisloTelefon, QString email, QString adresa,
                 QString nazovFirmy, QDate datumNarodenia)
{
    m_meno = meno;
    m_priezvisko = priezvisko;
    m_titul = titul;
    m_prezyvka = prezyvka;
    m_cisloMobil = cisloMobil;
    m_cisloTelefon = cisloTelefon;
    m_email = email;
    m_adresa = adresa;
    m_nazovFirmy = nazovFirmy;
    m_datumNarodenia = datumNarodenia;
}

QString Kontakt::toString() const
{
    QString str;

    if (!m_titul.isEmpty()){

        str += m_titul;
        if (!m_titul.contains('.')){
            str += ".";
        }
        str += " ";
    }

    str += m_meno + " " + m_priezvisko;

    return str;
}
QString Kontakt::toStringdetail() const
{
    QString str;

    if (!m_titul.isEmpty()){

        str += m_titul;
        if (!m_titul.contains('.')){
            str += ".";
        }
        str += " ";
    }

    str += m_meno + " " + m_priezvisko + ", " + m_prezyvka + ", " + m_cisloMobil + ", " + m_cisloTelefon
            + ", " + m_email + ", " + m_adresa + ", " + m_nazovFirmy;

    return str;
}

void Kontakt::ulozSa(QTextStream & stream) const
{
    stream << m_titul << SAVING_SEPARATOR
           << m_meno << SAVING_SEPARATOR
           << m_priezvisko << SAVING_SEPARATOR
           << m_prezyvka << SAVING_SEPARATOR
           << m_datumNarodenia.toString() << SAVING_SEPARATOR
           << m_cisloMobil << SAVING_SEPARATOR
           << m_cisloTelefon << SAVING_SEPARATOR
           << m_email << SAVING_SEPARATOR
           << m_adresa << SAVING_SEPARATOR
           << m_nazovFirmy << endl;
}

void Kontakt::nacitajSa(QString &riadokSuboru)
{
  QList<QString> nacitanePolozky = riadokSuboru.split(SAVING_SEPARATOR);

  m_titul = nacitanePolozky[0];
  m_meno = nacitanePolozky[1];
  m_priezvisko = nacitanePolozky[2];
  m_prezyvka = nacitanePolozky[3];
  m_datumNarodenia = QDate::fromString( nacitanePolozky[4] );
  m_cisloMobil = nacitanePolozky[5];
  m_cisloTelefon = nacitanePolozky[6];
  m_email = nacitanePolozky[7];
  m_adresa = nacitanePolozky[8];
  m_nazovFirmy = nacitanePolozky[9];
}


