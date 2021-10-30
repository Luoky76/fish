 bool Level2::checkAns(string ans)
 {
 	CalcExpression c;
	string s = this->getPro();
	double a = stod(ans);
	if(a == c.calc(s)) return true;
	else return false; 
 } 
