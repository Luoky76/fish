Level1:: Level1(){
	int cnt;
	cnt = rand()%9 + 2;
	kuo = rand()%7;
	for(int i=1;i<=cnt;i++){
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
 
} 

