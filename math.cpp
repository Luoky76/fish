#include <bits/stdc++.h>

class CalcExpression
{
	public:
	static double calc(string expression);
	static int calc(string expression);
}

class Problem
{
	public:
	static int lev1 = 1;	//对应Level1
	static int lev2 = 2;	//对应Level2
	static int lev3 = 3;	//对应Level3

	static Problem* getInstance(int level);	//随根据年级随机生成题目实例
	int getAns();
	bool checkAns(string ans);	//每个题目自行判断答案是否正确
	void setLim(int low,int high);	//设置生成的数的上下界
	string getPro();	//获取用string表示的题目

	protected:
	int maxNum;
	int minNum;
}

class Level1 public:Problem
{
	public:
	Level1();	//构造函数内直接随机生成题目 注意设置上下界

	private:
	vector <int> a;	//运算数
	vector <char> ope;	//运算符 只含加减法
	int ans;
}

class Level2 public:Problem
{
	public:
	Level2();	//构造函数内直接随机生成题目  注意设置上下界

	private:
	vector <int> a;	//运算数
	vector <char> ope;	//运算符 含加减乘除
	int ans;
}

class Level3 public:Problem
{
	public:
	Level3();	//构造函数内直接随机生成题目  注意设置上下界

	private:
	vector <double> a;	//运算数 含小数
	vector <bool> isInteger;	//是否为整数
	vector <char> ope;	//运算符 含加减乘除
	double ans;
}

class Server
{
	public:
	Server();
	void setGrade(int newGrade);
	bool check(string ans);	//判断答案是否正确
	string getProblem();	//调用问题的 getPro

	private:
	int grade;
	Problem* problem;
	void getProblemInstance();	//调用getInstance （传入grade） 获取problem实例
}

class Client	//专门与键盘打交道
{
	public:
	Client();
	void getGradeFromKeyboard();	//从键盘读入年级 （完成中文翻译） 后传给Server
	void printProblem();	//在屏幕上打印题目
	string getAnsFormKeyboard();	//从键盘读取答案
	int getProCntFormKeyboard();	//获取题目数量
	void printEndofPro();	//打印题目结束的提示（全部正确/有多少错误）
	void start();

	private:
	int proCnt;	//题目总数
	int correctFormKeyboarCnt;	//错误题目数
	Server server;
}

int main()
{
    Client client;//实例化client
    client->start();
}
