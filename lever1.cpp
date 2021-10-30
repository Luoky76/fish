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
