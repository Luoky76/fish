Level3::Level3()
{
	srand(time(0));
	int geshu = (rand() % 3) + 2; //生成N的个数 (2-4)
	char symbol[4] = {'+', '-', '*', '/'};
	for (int i = 0; i < geshu - 1; i++)
	{
		//符号的随机生成
		int openum = rand() % 4;
		ope.push_back(symbol[openum]);
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
		return true;
	else
		return false;
}
string Level3::getPro()
{
	int cnta = a.size();   //数字个数
	int cnto = ope.size(); //操作符个数
	int x = 0;			   //当前数字数组位置
	int y = 0;			   //当前符号数组位置
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
