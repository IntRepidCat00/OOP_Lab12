#include "drib_pnr.h"

const int MAX_MULT = 46340;

void Drib_PNR::setNumerator(int newNumerator)
{
    Numerator = newNumerator;
}

void Drib_PNR::setDenominator(int newDenominator)
{
    if(newDenominator == 0)
    {
        throw Exception_PNR("Denominator cannot equal zero");
    }
    Denominator = newDenominator;
}

int Drib_PNR::getDenominator() const
{
    return Denominator;
}

int Drib_PNR::getNumerator() const
{
    return Numerator;
}

Drib_PNR Drib_PNR::operator+(const Drib_PNR& fr2)
{
    int n, d;
    long long ln, ld;
    if(this->Denominator != fr2.Denominator)
    {
        n = this->Numerator * fr2.getDenominator() + this->Denominator * fr2.getNumerator();
        d = this->Denominator * fr2.Denominator;
        ln = static_cast<long long>(this->Numerator * fr2.getDenominator()) + static_cast<long long>(this->Denominator * fr2.getNumerator());
        ld = static_cast<long long>(this->Denominator * fr2.Denominator);
    } else
    {
        n = this->Numerator + fr2.getNumerator();
        d = this->Denominator;
        ln = static_cast<long long>(this->Numerator + fr2.getNumerator());
        ld = static_cast<long long>(this->Denominator);
    }

    if(n != ln || d != ld)
    {
        throw Exception_PNR("Number overflow");
    }
    Drib_PNR fr3(n, d);
    return Drib_PNR(n, d);
}

Drib_PNR Drib_PNR::operator-(const Drib_PNR& fr2)
{
    int n, d;
    long long ln, ld;
    if(this->Denominator != fr2.Denominator)
    {
        n = this->Numerator * fr2.getDenominator() - this->Denominator * fr2.getNumerator();
        d = this->Denominator * fr2.Denominator;
        ln = static_cast<long long>(this->Numerator * fr2.getDenominator()) - static_cast<long long>(this->Denominator * fr2.getNumerator());
        ld = this->Denominator * fr2.Denominator;
    } else
    {
        n = this->Numerator - fr2.getNumerator();
        d = this->Denominator;
        ln = static_cast<long long>(this->Numerator - fr2.getNumerator());
        ld = static_cast<long long>(this->Denominator);
    }
    if(n != ln || d != ld)
    {
        throw Exception_PNR("Number overflow");
    }
    return Drib_PNR(n, d);
}

Drib_PNR Drib_PNR::operator*(const Drib_PNR& fr2)
{
    int n = this->Numerator * fr2.Numerator;
    int d = this->Denominator * fr2.Denominator;

    long long ln = static_cast<long long>(this->Numerator * fr2.Numerator);
    long long ld = static_cast<long long>(this->Denominator * fr2.Denominator);

    if(n != ln || d != ld)
    {
        throw Exception_PNR("Number overflow");
    }
    if(abs(this->Numerator) > MAX_MULT && fr2.Numerator > MAX_MULT)
    {
        throw Exception_PNR("Number overflow");
    }
    if(abs(this->Denominator) > MAX_MULT && abs(fr2.Denominator) > MAX_MULT)
    {
        throw Exception_PNR("Number overflow");
    }
    return Drib_PNR(n, d);
}

Drib_PNR Drib_PNR::operator/(const Drib_PNR& fr2)
{
    if(fr2.Numerator == 0)
    {
        throw Exception_PNR("Cannot divide on zero");
    }
    int n = this->Numerator * fr2.Denominator;
    int d = this->Denominator * fr2.Numerator;

    long long ln = static_cast<long long>(this->Numerator * fr2.Denominator);
    long long ld = static_cast<long long>(this->Denominator * fr2.Numerator);

    if(n != ln || d != ld)
    {
        throw Exception_PNR("Number overflow");
    }
    if(abs(this->Numerator) > MAX_MULT && abs(fr2.Denominator) > MAX_MULT)
    {
        throw Exception_PNR("Number overflow");
    }
    if(abs(this->Denominator) > MAX_MULT && abs(fr2.Numerator) > MAX_MULT)
    {
        throw Exception_PNR("Number overflow");
    }

    return Drib_PNR(n, d);
}

Drib_PNR Drib_PNR::inverse()
{
    if(Numerator == 0)
        throw Exception_PNR("Cannot inverse Fraction where numerator equals zero");
    return Drib_PNR(Denominator, Numerator);
}

QString Drib_PNR::print() const
{
    return QString::number(Numerator) + '/' + QString::number(Denominator);
}


