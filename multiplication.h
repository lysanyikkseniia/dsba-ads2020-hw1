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

    short& operator[](int i) {return reinterpret_cast<short &>(_inf[i]);}
    short operator[](int i) const {return _inf[i];}
    Number operator+(Number b) const;
    Number operator-(Number b) const;
    bool operator==(Number b) const {return (_inf == b._inf);};

//private:
    std::vector<int> _inf;
};

class Multiplicator
{
public:
    static Number numGenerator(int i);
    static void makeEqualSize(Number& a, Number& b);
    static Number gradeSch(const Number& a, const Number& b);
    static Number divCon(Number a, Number b);
};

#ifndef HW1_MULTIPLICATION_H
#define HW1_MULTIPLICATION_H

#endif //HW1_MULTIPLICATION_H
