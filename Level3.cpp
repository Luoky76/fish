#include "math.cpp"

Level3::Level3()
{
    char opt[4] = {'+', '-', '*', '//'};
    srand(time(0));
    setLim(0, 10000);

    int x = rand() % 9 + 2;
    while (x--)
    {
        bool flag = rand() % 2;
        isInteger.push_back(flag);
        if (flag)
        {
            a.push_back((rand() % (maxNum + 1)));
        }
        else
        {
            a.push_back((rand() % (maxNum * 100 + 1)) / (100.0));
        }
        if (!x)
            ope.push_back(opt[rand() % 4]);
    }
}
string Level3::getPro(){ 
   int k=0;
   string bd;                               //算式生成
   for(int i=0;i<geshu;i++)
   {   string abc;                        
       stringstream ss;                     //数字转换字符串 
       ss << a[i];                           
       ss >>  abc;
        bd += abc;                          //字符串拼接   
        bd += " "; 
       if(i==geshu-1)
       { continue;
       }
       else
       {                                 
	      
        bd += ope[k];                       //操作数的拼接 
        bd += " ";
        k++;
       }
  }
  return bd;                       
 }