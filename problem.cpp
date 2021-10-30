Problem* Problem::getInstance(int level)
{
	if(level == 1){
		Problem Pro = new Level1;
	}
	else if(level == 2){
		Problem Pro = new Level2;
	}
	else if(level == 3){
		Problem Pro = new Level3;
	}
	return Pro;
}	 

string Problem::getPro()
{
	int cnta = a.size();   //数字个数
	int cnto = ope.size(); //操作符个数
	int x = 0;             //当前数字数组位置
	int y = 0;             //当前符号数组位置
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