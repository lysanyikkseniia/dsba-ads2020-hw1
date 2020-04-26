#include <vector>

class Number
{
public:
    Number()= default;

    void push_back(short i) {_inf.push_back(i);}
    int size() const {return _inf.size();}
    void deleteLeadingZeroes();

    short& operator[](int i) {return _inf[i];}
    Number operator+(Number b);
    Number operator-(Number b);

private:
    std::vector<short> _inf;
};

#ifndef HW1_MULTIPLICATION_H
#define HW1_MULTIPLICATION_H

#endif //HW1_MULTIPLICATION_H
