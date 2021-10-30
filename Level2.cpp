#include "math.cpp"

Level2::Level2()
{
    char opt[4] = {'+', '-', '*', '//'};
    srand(time(0));
    int x = rand() % 9 + 2;
    while (x--)
    {
        a.push_back(rand()%(maxNum+1));
        if (!x)
            ope.push_back(opt[rand() % 4]);
    }
    
}
