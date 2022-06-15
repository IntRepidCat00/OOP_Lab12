#ifndef DRIB_PNR_H
#define DRIB_PNR_H

#include <QTextEdit>
#include "exception_pnr.h"
#include <climits>
#include <cmath>

class Drib_PNR
{
public:
    Drib_PNR() = default;
    Drib_PNR(int num, int denom)
        : Numerator{num}, Denominator{denom}
    {
        if(denom == 0)
        {
            throw Exception_PNR("Denominator cannot equal zero");
        }
    }

    Drib_PNR operator+(const Drib_PNR& fr2);
    Drib_PNR operator-(const Drib_PNR& fr2);
    Drib_PNR operator*(const Drib_PNR& fr2);
    Drib_PNR operator/(const Drib_PNR& fr2);
    Drib_PNR inverse();
    void setNumerator(int newNumerator);
    void setDenominator(int newDenominator);
    int getDenominator() const;
    int getNumerator() const;
    QString print() const;

private:
    int Numerator{0};
    int Denominator{1};
};

#endif // DRIB_PNR_H
