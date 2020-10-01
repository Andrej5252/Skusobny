#ifndef KONTAKT_H
#define KONTAKT_H

#include <QDate>
#include <QString>
#include <QTextStream>



class Kontakt
{
private:
    QString m_meno;
    QString m_priezvisko;
    QString m_titul;
    QString m_prezyvka;

    QString m_cisloMobil;
    QString m_cisloTelefon;
    QString m_email;
    QString m_adresa;
    QString m_nazovFirmy;

    QDate m_datumNarodenia;

public:
    Kontakt();
    Kontakt(QString meno, QString priezvisko, QString titul, QString prezyvka,
            QString cisloMobil, QString cisloTelefon, QString email, QString adresa, QString nazovFirmy,
            QDate datumNarodenia);


    QString meno() const                                { return m_meno; }
    void setMeno(const QString &meno)                   { m_meno = meno; }

    QString priezvisko() const                          { return m_priezvisko; }
    void setPriezvisko(const QString &priezvisko)       { m_priezvisko = priezvisko; }

    QString titul() const                               { return m_titul; }
    void setTitul(const QString &titul)                 { m_titul = titul; }

    QString prezyvka() const                            { return m_prezyvka; }
    void setPrezyvka(const QString &prezyvka)           { m_prezyvka = prezyvka; }

    QString cisloMobil() const                          { return m_cisloMobil; }
    void setCisloMobil(const QString &cisloMobil)       { m_cisloMobil = cisloMobil; }

    QString cisloTelefon() const                        { return m_cisloTelefon; }
    void setCisloTelefon(const QString &cisloTelefon)   { m_cisloTelefon = cisloTelefon; }

    QString email() const                               { return m_email; }
    void setEmail(const QString &email)                 { m_email = email; }

    QString adresa() const                              { return m_adresa; }
    void setAdresa(const QString &adresa)               { m_adresa = adresa; }

    QString nazovFirmy() const                          { return m_nazovFirmy; }
    void setNazovFirmy(const QString &nazovFirmy)       { m_nazovFirmy = nazovFirmy; }

    QDate datumNarodenia() const                        { return m_datumNarodenia; }
    void setDatumNarodenia(const QDate &datumNarodenia) { m_datumNarodenia = datumNarodenia; }

    QString toString() const;
    QString toStringdetail() const;
    void ulozSa(QTextStream & stream) const;
    void nacitajSa(QString & riadokSuboru);

};

#endif // KONTAKT_H
