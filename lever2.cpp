Level2::Level2(){ 
   srand(time(0)); 
   int geshu=(rand()%3)+2;               //����N�ĸ��� (2-4)
   char symbol[4]={'+','-','*','/'};  
   for(int i=0;i<geshu-1;i++)   
   {                                    //���ŵ��������
   int openum=rand()%4;
   ope.push_back(symbol[openum]);
   }
   
   for(int i=0;i<geshu;i++)
   { 
    int randnum=rand()%1000001;   //��Χ��[0,10000] 
	int b=randnum/100;
    a.push_back(b); 
   }
     int k=0;
   string bd;                               //��ʽ����
   for(int i=0;i<geshu;i++)
   {   string abc;                        
       stringstream ss;                     //����ת���ַ��� 
       ss << a[i];                           
       ss >>  abc;
        bd += abc;                          //�ַ���ƴ��   
        bd += " "; 
       if(i==geshu-1)
       { continue;
       }
       else
       {                                 
	      
        bd += ope[k];                       //��������ƴ�� 
        bd += " ";
        k++;
       }
   }
    bd += "= ?";

   cout<<bd<<endl;                          

 }
 
 bool Level2::checkAns(string ans)
 {
 	CalcExpression c;
	string s = this->getPro();
	double a = stod(ans);
	if(a == c.calc(s)) return true;
	else return false; 
 } 
