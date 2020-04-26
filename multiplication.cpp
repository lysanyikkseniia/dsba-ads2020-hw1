#include "multiplication.h"

void Number::deleteLeadingZeroes()
{
    while ((size() > 1) && ((*this)[size() - 1] == 0))
        _inf.resize(size() - 1);
}

Number Number::operator+(Number b)
{
    Number a = *this;
    short buf = 0;
    int i = 0;
    int n = size();
    if (b.size() > n)
        n = b.size();
    while ((i < n) || (buf))
    {
        if (i == a.size())
            a.push_back (0);
        if (i < b.size())
        {
            a[i] += buf + b[i];
        }
        else
        {
            a[i] += buf;
        }
        if (a[i] >= 10)
        {
            buf = 1;
            a[i] %= 10;
        }
        else
            buf = 0;
        ++i;
    }
    return a;
}

Number Number::operator-(Number b)
{
    Number a = *this;
    int buf = 0;
    int i = 0;
    while ((i < b.size()) || (buf))
    {
        if (i < b.size())
            a[i] -= buf + b[i];
        else
            a[i] -= buf;
        if (a[i] < 0)
            buf = 1;
        else
            buf = 0;
        if (buf)
            a[i] += 10;
        ++i;
    }
    a.deleteLeadingZeroes();
    return a;
}