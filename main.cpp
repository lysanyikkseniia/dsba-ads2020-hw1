#include <iostream>
#include "multiplication.h"
void test1()
{
    for (int i = 1; i < 100; i += 10)
    {
        for (int j = 1; j < 5; j++)
        {
            Number a = Multiplicator::numGenerator(i);
            Number b = Multiplicator::numGenerator(i);
            Number c1 = Multiplicator::gradeSch(a, b);
            Number c2 = Multiplicator::divCon(a, b);

            if (!(c1 == c2))
            {
                std::cout << i << " ERROR" << std::endl;
            }
        }
    }
}

int main() {
    srand(time(nullptr));
    test1();
    int i = 0;
    return 0;
}
