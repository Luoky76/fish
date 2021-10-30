#ifndef __MATH__CPP
#define __MATH__CPP

#include <bits/stdc++.h>
using namespace std;

struct stack_data
{
	char Operator;
	double Number;
};

class CalcExpression
{
public:
	static CalcExpression *getInstance(); //ʹ�ô˺�������ȡ�����Ψһʵ��
	double calc(string expression);
	int calcOnlyInt(string expression);

private:
	static CalcExpression *instance; //���汾���Ψһʵ������ʵ���в�����ʱӦ��Ϊnullptr
	CalcExpression();				 //���캯��˽�л����������ⲿ����ʵ��������
	bool isOperator(char ch);												  // ��������ж�
	bool isNumber(char ch);													  //�����ж�
	int priority(char a);													  //���ȼ��ж�
	void getTwoNums(stack<double> &num_stack, double &first, double &second); //��ȡ����ջ��˫��
	double postfixCalculate(vector<stack_data> &postfix);					  //�����׺����ʽ
	vector<stack_data> getSeparate(string &infix);							  //���ָ�
	string printSeparate(vector<stack_data> &temp);							  //����ʽ���
	vector<stack_data> getPostfixExp(vector<stack_data> &infix);			  //��׺����ʽת��
};

class Problem
{
public:
	const static int lev1 = 1; //��ӦLevel1
	const static int lev2 = 2; //��ӦLevel2
	const static int lev3 = 3; //��ӦLevel3

	static Problem *getInstance(int level); //������꼶���������Ŀʵ��
	virtual bool checkAns(string ans) = 0;	//ÿ����Ŀ�����жϴ��Ƿ���ȷ
	void setLim(int low, int high);			//�������ɵ��������½�
	virtual string getPro() = 0;			//��ȡ��string��ʾ����Ŀ

protected:
	int maxNum;
	int minNum;
};

class Level1 : public Problem
{
public:
	Level1(); //���캯����ֱ�����������Ŀ ע���������½�
	bool checkAns(string ans);
	string getPro();

private:
	vector<int> a;	  //������
	vector<char> ope; //����� ֻ���Ӽ���
	int ans;
};

class Level2 : public Problem
{
public:
	Level2(); //���캯����ֱ�����������Ŀ  ע���������½�
	bool checkAns(string ans);
	string getPro();

private:
	vector<int> a;	  //������
	vector<char> ope; //����� ���Ӽ��˳�
	int ans;
};

class Level3 : public Problem
{
public:
	Level3(); //���캯����ֱ�����������Ŀ  ע���������½�
	bool checkAns(string ans);
	string getPro();

private:
	vector<double> a;		//������ ��С��
	vector<bool> isInteger; //�Ƿ�Ϊ����
	vector<char> ope;		//����� ���Ӽ��˳�
	double ans;
};

class Server
{
public:
	Server();
	~Server();
	void setGrade(int newGrade);
	bool check(string ans); //�жϴ��Ƿ���ȷ
	string getProblem();	//��������� getPro

private:
	int grade;
	Problem *problem;
	void getProblemInstance(); //����getInstance ������grade�� ��ȡproblemʵ��
};

class Client //ר������̴򽻵�
{
public:
	Client();
	void getGradeFromKeyboard(); //�Ӽ��̶����꼶 ��������ķ��룩 �󴫸�Server
	void printProblem();		 //����Ļ�ϴ�ӡ��Ŀ
	string getAnsFromKeyboard(); //�Ӽ��̶�ȡ��
	int getProCntFromKeyboard(); //��ȡ��Ŀ����
	void printEndofPro();		 //��ӡ��Ŀ��������ʾ��ȫ����ȷ/�ж��ٴ���
	void start();

private:
	int proCnt;	  //��Ŀ����
	int wrongCnt; //������Ŀ��
	Server server;
};
#endif
