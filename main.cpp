#include <iostream>
#include "multiplication.h"
#include <cmath>
#include <fstream>

void importRes()
{
    std::ofstream result;
    result.open("/Users/macbook/se/projects/HW1/result.csv");
    int k = 1;
    for (int i = 1; i <= 5000; i+=k)
    {
        std::cout << i << ", ";
        result << i << ", ";
        double time = 0;
        for(int j = 0; j < 3; ++j)
        {
            Number a = Multiplicator::numGenerator(i);
            Number b = Multiplicator::numGenerator(i);
            std::chrono::time_point<std::chrono::steady_clock> begin = std::chrono::steady_clock::now();
            Number c = GS::Multiplication(a, b);
            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            double duration = std::chrono::duration<double>(end - begin).count();
            time += duration;
        }
        time /= 3;
        std::cout << time << ", ";
        result << time << ", ";
        time = 0;
        for(int j = 0; j < 3; ++j)
        {
            Number a = Multiplicator::numGenerator(i);
            Number b = Multiplicator::numGenerator(i);
            std::chrono::time_point<std::chrono::steady_clock> begin = std::chrono::steady_clock::now();
            Number c = DC::Multiplication(a, b);
            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            double duration = std::chrono::duration<double>(end - begin).count();
            time += duration;
        }
        time /= 3;
        std::cout << time << ", ";
        result << time << ", ";
        time = 0;
        for(int j = 0; j < 3; ++j)
        {
            Number a = Multiplicator::numGenerator(i);
            Number b = Multiplicator::numGenerator(i);
            std::chrono::time_point<std::chrono::steady_clock> begin = std::chrono::steady_clock::now();
            Number c = KR::Multiplication(a, b);
            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            double duration = std::chrono::duration<double>(end - begin).count();
            time += duration;
        }
        time /= 3;
        std::cout << time << '\n';
        result << time << '\n';
        if (i == 100)
            k = 10;
        if (i == 1000)
            k = 250;
    }
    result.close();
}

int main() {
    srand(time(nullptr));
    importRes();
    return 0;
}
