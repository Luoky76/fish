Level1:: Level1(){
	int cnt;
	cnt = rand()%4 + 2;
	for(int i=1 ; i<= cnt ;i++){
		int num;
		num = rand() % 101;
		a.push_back(num);
	}
	for(int i=1;i<cnt;i++){
		int ope;
		ope = rand() % 2;
		if(ope) b.push_back('+');
		else b.push_back('-');
	}
	for(int i=1;i<=cnt;i++){
		if(i == 1){
			ans = a[i];
			coutinue;
		}
		else{
			if(b[i-1] == '+') ans += a[i];
			else ans -= a[i];
		}
	}
} 
string Level1::getpro(){
	string output;
	int cnt = 0;
	int cntstr = 0;
	for(int i=0;i<a.size();i++){
		int Num[5];
		int cntNum = 0;
		while(a[i]>0){
			Num[cntNum++]=a[i]%10;
			a[i]%=10;
		}
		for(int j=4;j>=0;j--){
			if(Num[j] == 0)continue;
			output[cntstr++]='0'+Num[j];
		}
		if(b[j]!='/0')output[cntstr++]=b[i];
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
