#include <vector>

const short TEN = 10;

class Number
{
public:
    Number(){}

    void push_back(short i) {_inf.push_back(i);}
    int size() const {return _inf.size();}
    void deleteLeadingZeroes();
    Number multTen(int i) const;
    std::pair<Number, Number> splitIntoHalves() const;

    short& operator[](int i) {return _inf[i];}
    short operator[](int i) const {return _inf[i];}
    Number operator+(Number b) const;
    Number operator-(Number b) const;
    bool operator==(const Number& b) const {return (_inf == b._inf);};

private:
    std::vector<short> _inf;
};

class Multiplicator
{
public:
    static Number numGenerator(int i);
    static void makeEqualSize(Number& a, Number& b);
};

class GS : public Multiplicator
{
public:
    static Number Multiplication(const Number& a, const Number& b);
};

class DC : public Multiplicator
{
public:
    static Number Multiplication(Number a, Number b);
};

class KR : public Multiplicator
{
public:
    static Number Multiplication(Number a, Number b);
};


#ifndef HW1_MULTIPLICATION_H
#define HW1_MULTIPLICATION_H

#endif //HW1_MULTIPLICATION_H
