#include "math.cpp"

Level3::Level3()
{
    char opt[4] = {'+', '-', '*', '//'};
    srand(time(0));
    int x = rand();
    while (x--)
    {
        a.push_back((rand()%1000001) / (100.0));
        if (!x)
            ope.push_back(opt[rand() % 4]);
    }
}
