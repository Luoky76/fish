#include "math.cpp"

Level3::Level3()
{
    char opt[4] = {'+', '-', '*', '//'};
    srand(time(0));
    setLim(0,10000);

    int x = rand()%9+2;
    while (x--)
    {
        a.push_back((rand()%(maxNum*100+1)) / (100.0));
        if (!x)
            ope.push_back(opt[rand() % 4]);
    }
}
