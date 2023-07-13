#include "stack_operations.cpp"

// private supporting member functions
float Cmplx_number::absolute_value(const Cmplx_number &c)
{
    return (sqrt(c.re * c.re + c.im * c.im));
}

void Cmplx_number::operator=(const Cmplx_number &c)
{
    this->re = c.re;
    this->im = c.im;
}

void Cmplx_number::operator=(const float y)
{
    this->re=y;
}

// streaming operators
ostream &operator<<(ostream &out, const Cmplx_number &c)
{
    out << c.re;
    if (c.im >= 0)
    {
        out << " + ";
        out << c.im<<"j";
    }
    else
    {
        out << " - ";
        out << -c.im<<"j";
    }
    return out;
}

istream &operator>>(istream &in, Cmplx_number &c)
{
    cout << "Enter real part -->      ";
    in >> c.re;
    cout << "Enter imaginary part -->     ";
    in >> c.im;
    return in;
}

// binary operators
bool Cmplx_number::operator==(const Cmplx_number &c)
{
    if (absolute_value(*this) == absolute_value(c))
        return true;
    else
        return false;
}

bool Cmplx_number::operator<(const Cmplx_number &c)
{
    if (absolute_value(*this) < absolute_value(c))
        return true;
    else
        return false;
}

bool Cmplx_number::operator>(const Cmplx_number &c)
{
    if (absolute_value(*this) > absolute_value(c))
        return true;
    else
        return false;
}

bool Cmplx_number::operator!=(const Cmplx_number &c)
{
    if (absolute_value(*this) != absolute_value(c))
        return true;
    else
        return false;
}

bool Cmplx_number::operator>=(const Cmplx_number &c)
{
    if (absolute_value(*this) >= absolute_value(c))
        return true;
    else
        return false;
}

bool Cmplx_number::operator<=(const Cmplx_number &c)
{
    if (absolute_value(*this) <= absolute_value(c))
        return true;
    else
        return false;
}

// sorthand operators
void Cmplx_number::operator+=(const Cmplx_number &c)
{
    *this = *this + c;
}

void Cmplx_number::operator-=(const Cmplx_number &c)
{
    *this = *this - c;
}

void Cmplx_number::operator*=(const Cmplx_number &c)
{
    *this = *this * c;
}

void Cmplx_number::operator/=(const Cmplx_number &c)
{
    *this = *this / c;
}

// mathematical operators
Cmplx_number operator+(const Cmplx_number &x, const Cmplx_number &y)
{
    Cmplx_number temp;
    temp.re = x.re + y.re;
    temp.im = x.im + y.im;
    return temp;
}

Cmplx_number operator-(const Cmplx_number &x, const Cmplx_number &y)
{
    Cmplx_number temp;
    temp.re = x.re - y.re;
    temp.im = x.im - y.im;
    return temp;
}

Cmplx_number operator*(const Cmplx_number &x, const Cmplx_number &y)
{
    Cmplx_number temp;
    temp.re = x.re * y.re - x.im * y.im;
    temp.im = x.re * y.im + x.im * y.re;
    return temp;
}

Cmplx_number operator/(const Cmplx_number &x, const Cmplx_number &y)
{
    if ((y.re * y.re + y.im * y.im) == 0)
        throw "error:    Division by zero \'/0\'";

    Cmplx_number temp;
    temp.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
    temp.im = (x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im);
    return temp;
}

Cmplx_number operator+(const Cmplx_number &x, float y)
{
    Cmplx_number temp;
    temp.re = x.re + y;
    temp.im = x.im;
    return temp;
}

Cmplx_number operator-(const Cmplx_number &x, float y)
{
    Cmplx_number temp;
    temp.re = x.re - y;
    temp.im = x.im;
    return temp;
}

Cmplx_number operator*(const Cmplx_number &x, float y)
{
    Cmplx_number temp;
    temp.re = x.re * y;
    temp.im = x.im * y;
    return temp;
}

Cmplx_number operator/(const Cmplx_number &x, float y)
{
    if (y == 0)
        throw "error:    Division by zero \'/0\'";

    Cmplx_number temp;
    temp.re = x.re / y;
    temp.im = x.im / y;
    return temp;
}