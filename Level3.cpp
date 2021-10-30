 Level3::Level3(){ 
   srand(time(0)); 
   int geshu=(rand()%3)+2;               //生成N的个数 (2-4)
   char symbol[4]={'+','-','*','/'};  
   for(int i=0;i<geshu-1;i++)   
   {                                    //符号的随机生成
   int openum=rand()%4;
   ope.push_back(symbol[openum]);
   }
   
   for(int i=0;i<geshu;i++)
   { 
   int randnum=rand()%1000001;   //范围在[0,10000] 
   int num=rand()%2;       //判断a的随机数是整数还是小数
   if(num==0)              //整数
   { 
    int b=randnum/100;
    a.push_back(b); 
   }
   else                    //小数
   {
    double randnum1=randnum/100.00;
    a.push_back(randnum1);
   }
   }
     int k=0;
   string bd;                               //算式生成
   for(int i=0;i<geshu;i++)
   {   string abc;                        
       stringstream ss;                     //数字转换字符串 
       ss << a[i];                           
       ss >>  abc;
        bd += abc;                          //字符串拼接   
         
       if(i==geshu-1)
       { continue;
       }
       else
       {                                 
	      
        bd += ope[k];                       //操作数的拼接 
       
        k++;
       }
   }
    

   cout<<bd<<endl;                          
                    

 }
