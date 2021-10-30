#include <bits/stdc++.h>

class Problem
{
	public:
	static int lev1 = 1;	//��ӦLevel1 
	static int lev2 = 2;	//��ӦLevel2 
	static int lev3 = 3;	//��ӦLevel3 
	
	static Problem* getInstance(int level);	//������꼶���������Ŀʵ�� 
	int getAns(); 
	bool checkAns(string ans);	//ÿ����Ŀ�����жϴ��Ƿ���ȷ 
	void setLim(int low,int high);	//�������ɵ��������½� 
	string getPro();	//��ȡ��string��ʾ����Ŀ 
	
	protected:
	int maxNum;
	int minNum;
}

class Level1 public:Problem
{
	public:
	Level1();	//���캯����ֱ�����������Ŀ ע���������½� 
	
	private:
	vector <int> a;	//������ 
	vector <char> ope;	//����� ֻ���Ӽ��� 
	int ans;
}

class Level2 public:Problem
{
	public:
	Level2();	//���캯����ֱ�����������Ŀ  ע���������½� 
	
	private:
	vector <int> a;	//������ 
	vector <char> ope;	//����� ���Ӽ��˳� 
	int ans;
}

class Level3 public:Problem
{
	public:
	Level3();	//���캯����ֱ�����������Ŀ  ע���������½� 
	
	private:
	vector <double> a;	//������ ��С�� 
	vector <bool> isInteger;	//�Ƿ�Ϊ���� 
	vector <char> ope;	//����� ���Ӽ��˳� 
	double ans;
}

class Server
{
	public:
	Server();
	void setGrade(int newGrade);
	bool check(string ans);	//�жϴ��Ƿ���ȷ
	string getProblem();	//��������� getPro
	
	private:
	int grade;
	Problem* problem;
	void getProblemInstance();	//����getInstance ������grade�� ��ȡproblemʵ�� 
}

class Client	//ר������̴򽻵� 
{
	public:
	void getGradeFromKeyboard();	//�Ӽ��̶����꼶 ��������ķ��룩 �󴫸�Server 
	void printProblem();	//����Ļ�ϴ�ӡ��Ŀ 
	string getAnsFormKeyboard();	//�Ӽ��̶�ȡ�� 
	int getProCntFormKeyboard();	//��ȡ��Ŀ���� 
	void printEndofPro();	//��ӡ��Ŀ��������ʾ��ȫ����ȷ/�ж��ٴ��� 
	
	private:
	int proCnt;	//��Ŀ���� 
	int correctFormKeyboarCnt;	//������Ŀ�� 
}

int main()
{
}