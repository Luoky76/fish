void Client::getGradeFromKeyboard()
{
    string NJ;
    cout << "����������꼶��" << endl;
    std::cin >> NJ;
    if (NJ == "һ�꼶" || NJ == "���꼶")
    {
        level = 1;
    }
    else if (NJ == "���꼶" || NJ == "���꼶")
    {
        level = 2;
    }
    else if (NJ == "���꼶" || NJ == "���꼶")
    {
        level = 3;
    }
    server.setGrade(level);
}
void Client::initProblem(){
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
    std::cout << "��������Ŀ����" << std::endl;
    std::cin >> proCnt;
    return proCnt;
}

void Client::printEndofPro()
{
    if (wrongCnt == 0)
    {
        std::cout << "������ȫ����ȷ��̫���ˣ�" << std::endl;
    }
    else
    {
        std::cout << "����������" << wrongCnt << "��Ŷ" << std::endl;
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
