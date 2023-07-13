#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Cmplx_number
{

    float re, im;

    float absolute_value(const Cmplx_number &);

public:
    Cmplx_number(float r = 0.0, float m = 0.0) : re(r), im(m) {}
    ~Cmplx_number() {}

    // streaming overloading
    friend ostream &operator<<(ostream &, const Cmplx_number &);
    friend istream &operator>>(istream &, Cmplx_number &);
    void operator=(const Cmplx_number &);
    void operator=(const float);

    // binary operations
    bool operator==(const Cmplx_number &);
    bool operator>(const Cmplx_number &);
    bool operator<(const Cmplx_number &);
    bool operator>=(const Cmplx_number &);
    bool operator<=(const Cmplx_number &);
    bool operator!=(const Cmplx_number &);

    // sorthand operations these are optional
    void operator+=(const Cmplx_number &);
    void operator-=(const Cmplx_number &);
    void operator*=(const Cmplx_number &);
    void operator/=(const Cmplx_number &);

    // mathematical operations
    friend Cmplx_number operator+(const Cmplx_number &, const Cmplx_number &);
    friend Cmplx_number operator+(const Cmplx_number &, float r);
    friend Cmplx_number operator*(const Cmplx_number &, const Cmplx_number &);
    friend Cmplx_number operator*(const Cmplx_number &, float r);
    friend Cmplx_number operator-(const Cmplx_number &, const Cmplx_number &);
    friend Cmplx_number operator-(const Cmplx_number &, float r);
    friend Cmplx_number operator/(const Cmplx_number &, const Cmplx_number &);
    friend Cmplx_number operator/(const Cmplx_number &, float r);
};

struct Stack
{
    string op_name;
    Cmplx_number stackObject;
    Stack *right;
} *top = NULL;
