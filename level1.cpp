Level1::Level1()
{
	srand(time(0));
	int geshu = (rand() % 3) + 2; //����N�ĸ��� (2-4)
	char symbol[4] = {'+', '-'};
	for (int i = 0; i < geshu - 1; i++)
	{ //���ŵ��������
		int openum = rand() % 2;
		ope.push_back(symbol[openum]);
	}

	for (int i = 0; i < geshu; i++)
	{
		int randnum = rand() % 101; //��Χ��[0,100]
		int b = randnum / 100;
		a.push_back(b);
	}
}

bool Level1::checkAns(string ans)
{
	CalcExpression* c=CalcExpression::getInstance();
	string s = this->getPro();
	double a = stod(ans);
	if (a == c->calc(s))
		return true;
	else
		return false;
}

string Level1::getPro()
{
	int cnta = a.size();   //���ָ���
	int cnto = ope.size(); //����������
	int x = 0;			   //��ǰ��������λ��
	int y = 0;			   //��ǰ��������λ��
	string Pro = "";
	while (x < cnta || y < cnto)
	{
		while (ope[y] == '(' && y < cnto)
		{
			Pro = Pro + "(";
			y++;
		}
		if (x < cnta)
		{
			stringstream temp;
			temp << a[x++];
			string tempp;
			temp >> tempp;
			Pro = Pro + tempp;
		}
		while (ope[y] == ')' && y < cnto)
		{
			Pro = Pro + ")";
			y++;
		}
		if (y < cnto)
		{
			Pro = Pro + ope[y++];
		}
	}
	return Pro;
}