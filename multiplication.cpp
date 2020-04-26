#include "multiplication.h"

void Number::deleteLeadingZeroes()
{
    while ((size() > 1) && ((*this)[size() - 1] == 0))
        _inf.resize(size() - 1);
}

Number Number::multTen(int i) const
{
    Number c;
    for (int j = 0; j < i; ++j)
        c.push_back(0);
    for (int j = 0; j < size(); ++j)
        c.push_back((*this)[j]);
    return c;
}

std::pair<Number, Number> Number::splitIntoHalves() const
{
    Number right;
    int n = size() / 2;
    right._inf = {_inf.begin(), _inf.begin() + n};
    Number left;
    left._inf = {_inf.begin() + n, _inf.end()};
    std::pair<Number, Number> result = std::make_pair(right,left);
    return result;
}

Number Number::operator+(Number b) const
{
    Number a = *this;
    short buf = 0;
    short i = 0;
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
        if (a[i] >= TEN)
        {
            buf = 1;
            a[i] %= TEN;
        }
        else
            buf = 0;
        ++i;
    }
    return a;
}

Number Number::operator-(Number b) const
{
    Number a = *this;
    short buf = 0;
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
            a[i] += TEN;
        ++i;
    }
    a.deleteLeadingZeroes();
    return a;
}

Number Multiplicator::numGenerator(int i)
{
    Number a;
    short b = 0;
    for (int j = 0; j < i; ++j)
    {
        b = (rand() % TEN);
        while ((j == i - 1) && (!b))
        {
            b = rand() % TEN;
        }
        a.push_back(b);
    }
    return a;
}

void Multiplicator::makeEqualSize(Number& a, Number& b)
{
    int dif = a.size() - b.size();
    if (!dif)
        return;
    if (dif > 0)
    {
        for (int i = 0; i < dif; i++)
            b.push_back(0);
        return;
    }
    for (int i = 0; i < abs(dif); i++)
        a.push_back(0);
}

Number GS::Multiplication(const Number& a, const Number& b)
{
    Number c;
    for (int j = 0; j < a.size()+ b.size(); ++j)
        c.push_back(0);
    for (int i = 0; i < a.size(); ++i)
    {
        short buf = 0;
        for (int j = 0; j < b.size(); ++j)
        {
            c[i + j] += a[i] * b[j] + buf;
            buf = (c[i + j] / TEN);
            c[i + j] %= TEN;
        }
        c[i + b.size()] += buf;
    }
    c.deleteLeadingZeroes();
    return c;
}

Number DC::Multiplication(Number a, Number b)
{
    if (a.size() == 1 || b.size() == 1)
        return GS::Multiplication(a,b);
    makeEqualSize(a, b);

    Number al = a.splitIntoHalves().first;
    Number ar = a.splitIntoHalves().second;
    Number bl = b.splitIntoHalves().first;
    Number br = b.splitIntoHalves().second;

    Number x1 = Multiplication(ar, br);
    x1 = x1.multTen((a.size() / 2) * 2);
    Number x2 = Multiplication(al, br) + Multiplication(ar, bl);
    x2 = x2.multTen(a.size() / 2);
    Number x3 = Multiplication(al, bl);

    Number x = x1 + x2 + x3;
    x.deleteLeadingZeroes();

    return x;
}

Number KR::Multiplication(Number a, Number b)
{
    if (a.size() == 1 || b.size() == 1)
        return GS::Multiplication(a,b);
    makeEqualSize(a, b);
    Number al = a.splitIntoHalves().first;
    Number ar = a.splitIntoHalves().second;
    Number bl = b.splitIntoHalves().first;
    Number br = b.splitIntoHalves().second;

    Number x1 = Multiplication(ar, br);

    Number x2 = Multiplication(al + ar, bl + br);

    Number x3 = Multiplication(al, bl);

    x2 = x2 - x1 - x3;

    x1 = x1.multTen(a.size() / 2 * 2);
    x2 = x2.multTen(a.size() / 2);

    Number x = x1 + x2 + x3;
    x.deleteLeadingZeroes();

    return x;
}