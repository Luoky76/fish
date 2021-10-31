Level1::Level1()
{
	srand(time(0));
	int geshu = (rand() % 3) + 2; //����N�ĸ��� (2-4)
	char symbol[4] = {'+', '-'};
	int khflag = 0;
	for (int i = 0; i < geshu - 1;)
	{
		if (rand() % 5)
		{
			if (ope.size() > 0 && ope[ope.size() - 1] == ')')
			{
				int openum = rand() % 2;
				ope.push_back(symbol[openum]);
				i++;
			}
			ope.push_back('(');
			khflag++;
		}
		if (i < geshu - 1)
		{
			int openum = rand() % 2;
			ope.push_back(symbol[openum]);
			i++;
		}
		if (khflag && rand() % 5)
		{
			ope.push_back(')');
			khflag--;
		}

		while (khflag && i >= geshu - 1)
		{
			ope.push_back(')');
			khflag--;
		}
	}


	for (int i = 0; i < geshu; i++)
	{
		a.push_back(rand() % 101);
	}
}

bool Level1::checkAns(string ans)
{
	CalcExpression *c = CalcExpression::getInstance();
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
	int khflag = 0;
	while (x < cnta || y < cnto)
	{
		if (x < cnta)
		{
			while (ope[y] == '(' && y < cnto)
			{
				Pro = Pro + "(";
				khflag++;
				y++;
			}
			stringstream temp;
			temp << a[x++];
			string tempp;
			temp >> tempp;
			Pro = Pro + tempp;
			while (ope[y] == ')' && y < cnto)
			{
				Pro = Pro + ")";
				khflag--;
				y++;
			}
		}
		if (y < cnto)
		{
			Pro = Pro + ope[y++];
		}
		while (x == a.size() && ope[y] == ')' && y < cnto && khflag != 0)
		{
			Pro = Pro + ")";
			khflag--;
			y++;
		}
	}
	return Pro;
}
