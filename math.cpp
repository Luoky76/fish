#include <bits/stdc++.h>
using namespace std;

class CalcExpression
{
public:
	static CalcExpression *getInstance(); //使锟矫此猴拷锟斤拷锟斤拷锟斤拷取锟斤拷锟斤拷锟轿ㄒ皇碉拷锟�
	double calc(string expression);
	int calcOnlyInt(string expression);

private:
	CalcExpression *instance; //锟斤拷锟芥本锟斤拷锟轿ㄒ皇碉拷锟斤拷锟斤拷锟绞碉拷锟斤拷胁锟斤拷锟斤拷锟绞庇︼拷锟轿猲ullptr
	CalcExpression();		  //锟斤拷锟届函锟斤拷私锟叫伙拷锟斤拷锟斤拷锟斤拷锟斤拷锟解部锟斤拷锟斤拷实锟斤拷锟斤拷锟斤拷锟斤拷

	struct stack_data // 锟斤拷锟斤拷栈锟斤拷锟捷结构锟斤拷
	{
		char Operator;
		double Number;
	};
	bool isOperator(char ch);												  // 锟斤拷锟斤拷锟斤拷锟斤拷卸锟�
	bool isNumber(char ch);													  //锟斤拷锟斤拷锟叫讹拷
	int priority(char a);													  //锟斤拷锟饺硷拷锟叫讹拷
	void getTwoNums(stack<double> &num_stack, double &first, double &second); //锟斤拷取锟斤拷锟斤拷栈锟斤拷双锟斤拷
	double postfixCalculate(vector<stack_data> &postfix);					  //锟斤拷锟斤拷锟阶猴拷锟斤拷锟绞�
	vector<stack_data> getSeparate(string &infix);							  //锟斤拷锟街革拷
	string printSeparate(vector<stack_data> &temp);							  //锟斤拷锟斤拷式锟斤拷锟�
	vector<stack_data> getPostfixExp(vector<stack_data> &infix);			  //锟斤拷缀锟斤拷锟斤拷式转锟斤拷
};

class Problem
{
public:
	const static int lev1 = 1; //锟斤拷应Level1
	const static int lev2 = 2; //锟斤拷应Level2
	const static int lev3 = 3; //锟斤拷应Level3

	static Problem *getInstance(int level); //锟斤拷锟斤拷锟斤拷昙讹拷锟斤拷锟斤拷锟斤拷锟斤拷目实锟斤拷
	int getAns();
	bool checkAns(string ans);		//每锟斤拷锟斤拷目锟斤拷锟斤拷锟叫断达拷锟角凤拷锟斤拷确
	void setLim(int low, int high); //锟斤拷锟斤拷锟斤拷锟缴碉拷锟斤拷锟斤拷锟斤拷锟铰斤拷
	string getPro();				//锟斤拷取锟斤拷string锟斤拷示锟斤拷锟斤拷目

protected:
	int maxNum;
	int minNum;
};

class Level1 : public Problem
{
public:
	Level1(); //锟斤拷锟届函锟斤拷锟斤拷直锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟侥� 注锟斤拷锟斤拷锟斤拷锟斤拷锟铰斤拷

private:
	vector<int> a;	  //锟斤拷锟斤拷锟斤拷
	vector<char> ope; //锟斤拷锟斤拷锟� 只锟斤拷锟接硷拷锟斤拷
	int ans;
};

class Level2 : public Problem
{
public:
	Level2(); //锟斤拷锟届函锟斤拷锟斤拷直锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟侥�  注锟斤拷锟斤拷锟斤拷锟斤拷锟铰斤拷

private:
	vector<int> a;	  //锟斤拷锟斤拷锟斤拷
	vector<char> ope; //锟斤拷锟斤拷锟� 锟斤拷锟接硷拷锟剿筹拷
	int ans;
};

class Level3 : public Problem
{
public:
	Level3(); //锟斤拷锟届函锟斤拷锟斤拷直锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟侥�  注锟斤拷锟斤拷锟斤拷锟斤拷锟铰斤拷

private:
	vector<double> a;		//锟斤拷锟斤拷锟斤拷 锟斤拷小锟斤拷
	vector<bool> isInteger; //锟角凤拷为锟斤拷锟斤拷
	vector<char> ope;		//锟斤拷锟斤拷锟� 锟斤拷锟接硷拷锟剿筹拷
	double ans;
};

class Server
{
public:
	Server();
	~Server();
	void setGrade(int newGrade);
	bool check(string ans); //锟叫断达拷锟角凤拷锟斤拷确
	string getProblem();	//锟斤拷锟斤拷锟斤拷锟斤拷锟� getPro

private:
	int grade;
	Problem *problem;
	void getProblemInstance(); //锟斤拷锟斤拷getInstance 锟斤拷锟斤拷锟斤拷grade锟斤拷 锟斤拷取problem实锟斤拷
};

class Client //专锟斤拷锟斤拷锟斤拷檀蚪坏锟�
{
public:
	Client();
	void getGradeFromKeyboard(); //锟接硷拷锟教讹拷锟斤拷锟疥级 锟斤拷锟斤拷锟斤拷锟斤拷姆锟斤拷耄� 锟襟传革拷Server
	void printProblem();		 //锟斤拷锟斤拷幕锟较达拷印锟斤拷目
	string getAnsFormKeyboard(); //锟接硷拷锟教讹拷取锟斤拷
	int getProCntFromKeyboard(); //锟斤拷取锟斤拷目锟斤拷锟斤拷
	void printEndofPro();		 //锟斤拷印锟斤拷目锟斤拷锟斤拷锟斤拷锟斤拷示锟斤拷全锟斤拷锟斤拷确/锟叫讹拷锟劫达拷锟斤拷
	void start();

private:
	int proCnt;				   //锟斤拷目锟斤拷锟斤拷
	int correctFormKeyboarCnt; //锟斤拷锟斤拷锟斤拷目锟斤拷
	Server server;
};

int main()
{
    Client client;//实例化client
    client.start();
    return 0;
}
