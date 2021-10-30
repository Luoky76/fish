#include "math.cpp"
void Client::getGradeFromKeyboard()
{
    string NJ;
    int level;
    std::cin >> NJ;

    if (NJ == "一年级" || NJ == "二年级")
    {
        level = 1;
    }
    else if (NJ == "三年级" || NJ == "四年级")
    {
        level = 2;
    }
    else if (NJ == "五年级" || NJ == "六年级")
    {
        level = 3;
    }
    server.setGrade(level);
}

void Client::printProblem()
{
    std::cout << server.getProblem();
}

string Client::getAnsFormKeyboard()
{
    string ans;
    std::cin >> ans;
    return ans;
}

int Client::getProCntFromKeyboard()
{
    std::cin >> proCnt;
}

void Client::printEndofPro()
{
    if (correctFormKeyboarCnt == 0)
    {
        std::cout << "全部正确";
    }
    else
    {
        std::cout << "有" << correctFormKeyboarCnt << "题错误" << endl;
    }
}

Client::Client()
{
    int proCnt = 0;
    int correctFormKeyboarCnt = 0;
}

void Client::start()
{
    int i;
    getGradeFromKeyboard();
    getProCntFromKeyboard();

    for (i = 0; i < proCnt; i++)
    {
        printProblem();
        if (!server.check(getAnsFormKeyboard()))
        {
            correctFormKeyboarCnt++;
        }
    }
    printEndofPro();
}
