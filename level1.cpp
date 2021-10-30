Level1:: Level1(){
	int cnt,flag=1;
	vector<char>c;
	cnt = rand()%9 + 2;
	int kuo;
	kuo = rand()%7;
	if(kuo+3 > cnt)kuo = -1;
	for(int i=1 ; i<= cnt ;i++){
		int num;
		num = rand() % 101;
		a.push_back(num);
	}
	for(int i=1;i<cnt;i++){
		int op;
		op = rand() % 2;
		if(op)ope.push_back('+');
		else ope.push_back('-');
	}
	if(kuo == 0 ||b[kuo-1] == '-')flag=1;
	for(int i=kuo;i<cnt-1;i++){
		if(i<kuo||i>=kuo+3||!flag)c[i]=ope[i];
		else if(flag){
			if(ope[i]=='-')c[i]='+';
			else c[i]='-';
		}
	}
} 
bool Level1::checkAns(string ans){
	int Ansinput = 0;
	for(int i=0;i<ans.length()){
		Ansinput *= 10;
		Ansinput += ans[i]-'0';
	}
	return Ansinput == ans;
}
string Level1::getPro()
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