void Client::getGradeFromKeyboard()
{
    string NJ;
    cout << "请输入你的年级？" << endl;
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

void Client::initProblem()
{
    server.getProblemInstance();
}

void Client::printProblem()
{
    std::cout << server.getProblemStr() << "=?" << std::endl;
}

string Client::getAnsFromKeyboard()
{
    string ans;
    std::cin >> ans;
    return ans;
}

int Client::getProCntFromKeyboard()
{
    std::cout << "请输入题目数？" << std::endl;
    std::cin >> proCnt;
    return proCnt;
}

void Client::printEndofPro()
{
    if (wrongCnt == 0)
    {
        std::cout << "结束！全部正确，太棒了！" << std::endl;
    }
    else
    {
        std::cout << "结束！错了" << wrongCnt << "题哦" << std::endl;
    }
}

Client::Client()
{
    proCnt = 0;
    wrongCnt = 0;
}

void Client::run()
{
    int i;
    getGradeFromKeyboard();
    getProCntFromKeyboard();

    for (i = 0; i < proCnt; i++)
    {
        initProblem();
        printProblem();
        if (!server.check(getAnsFromKeyboard()))
        {
            wrongCnt++;
        }
    }
    printEndofPro();
    system("pause");
}
