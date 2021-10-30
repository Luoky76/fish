Server::Server()
{
}
void Server::setGrade(int newGrade)
{
	this->grade = newGrade;
}
bool Server::check(string ans) //�жϴ��Ƿ���ȷ
{
	return problem->checkAns(ans);
}
string Server::getProblem()
{
	return problem->getPro(); //��������� getPro
}
void Server::getProblemInstance()
{
	problem = Problem::getInstance(grade);
}

Server::~Server()
{
	delete problem;
}
