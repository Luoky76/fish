
Server::Server()
{ 

}
void Server::setGrade(int newGrade)
{
	this.grade = newGrade;
	getProblemInstance();
}
bool Server::check(string ans)
{
	return problem->checkAns();		
}//�жϴ��Ƿ���ȷ
string Server::getProblem()
{
	return problem->getPro();
}	//��������� getPro
void Server::getProblemInstance()
{
	problem = Problem::getInstance(grade);
}
	private:
	int grade;
	Problem* problem;
	void getProblemInstance();	//����getInstance ������grade�� ��ȡproblemʵ�� 
}
