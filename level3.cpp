Level3::Level3()
{
	srand(time(0));
	int geshu = (rand() % 3) + 2; //生成N的个数 (2-4)
	char symbol[4] = {'+', '-', '*', '/'};

	int khflag = 0;
	for (int i = 0; i < geshu - 1;)
	{
		if (rand() % 5)
		{
			if (ope.size() > 0 && ope[ope.size() - 1] == ')')
			{
				int openum = rand() % 4;
				ope.push_back(symbol[openum]);
				i++;
			}
			ope.push_back('(');
			khflag++;
		}
		if (i < geshu - 1)
		{
			int openum = rand() % 4;
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
		int randnum = rand() % 1000001; //范围在[0,10000]
		int num = rand() % 2;			//判断a的随机数是整数还是小数
		if (num == 0)					//整数
		{
			int b = randnum / 100;
			a.push_back(b);
		}
		else //小数
		{
			double randnum1 = randnum / 100.00;
			a.push_back(randnum1);
		}
	}
}

bool Level3::checkAns(string ans)
{
	CalcExpression *c = CalcExpression::getInstance();
	string s = this->getPro();
	double a = stod(ans);
	if (a == c->calc(s))
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Level3::getPro()
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
		while (x == a.size() && khflag != 0 && ope[y] == ')' && y < cnto)
		{
			Pro = Pro + ")";
			khflag--;
			y++;
		}
	}
	return Pro;
}
