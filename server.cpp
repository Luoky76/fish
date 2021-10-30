Server::Server()
{
}

void Server::setGrade(int newGrade)
{
	this->grade = newGrade;
}

void Server::getProblemInstance()
{
	problem = Problem::getInstance(grade);
}

bool Server::check(string ans) //�жϴ��Ƿ���ȷ
{
	return problem->checkAns(ans);
}

string Server::getProblemStr()
{
	return problem->getPro(); //��������� getPro
}

Server::~Server()
{
	delete problem;
}
