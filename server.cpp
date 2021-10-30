
Server::Server()
{ 

}
void Server::setGrade(int newGrade)
{
    this.grade = newGrade;
	getProblemInstance();
}
bool Server::check(string ans) //判断答案是否正确
{
	return problem->checkAns();		
}
string Server::getProblem()
{
	return problem->getPro();  //调用问题的 getPro
}	
void Server::getProblemInstance()
{
    problem = Problem::getInstance(grade);
}
	
