
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
}//判断答案是否正确
string Server::getProblem()
{
	return problem->getPro();
}	//调用问题的 getPro
void Server::getProblemInstance()
{
	problem = Problem::getInstance(grade);
}
	private:
	int grade;
	Problem* problem;
	void getProblemInstance();	//调用getInstance （传入grade） 获取problem实例 
}
