Level3::Level3()
{ 
	srand(time(0)); 
	int geshu=(rand()%3)+2;               //����N�ĸ��� (2-4)
	char symbol[4]={'+','-','*','/'};  
	for(int i=0;i<geshu-1;i++)   
	{
		//���ŵ��������
		int openum=rand()%4;
		ope.push_back(symbol[openum]);
	}
   
	for(int i=0;i<geshu;i++)
	{ 
		int randnum=rand()%1000001;   //��Χ��[0,10000] 
		int num=rand()%2;       //�ж�a�����������������С��
		if(num==0)              //����
		{ 
			int b=randnum/100;
			a.push_back(b); 
		}
		else                    //С��
		{
			double randnum1=randnum/100.00;
 			a.push_back(randnum1);
		}
	}                 
 }
 bool Level3::checkAns(string ans)
 {
 	CalcExpression c;
	string s = this->getPro();
	double a = stod(ans);
	if(a == c.calc(s)) return true;
	else return false; 
 }
