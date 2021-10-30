CalcExpression* CalcExpression::instance = nullptr;

bool CalcExpression::isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

bool CalcExpression::isNumber(char ch)
{
    string number = "0123456789.";
    return number.find(ch) != -1;
}

int CalcExpression::priority(char a)
{
    int temp = 0;
    if (a == '*' || a == '/')
        temp = 1;
    else if (a == '+' || a == '-')
        temp = 0;
    return temp;
}

void CalcExpression::getTwoNums(stack<double> &num_stack, double &first, double &second)
{
    second = num_stack.top();
    num_stack.pop();

    first = num_stack.top();
    num_stack.pop();
}

double CalcExpression::postfixCalculate(vector<stack_data> &postfix)
{
    double first, second;
    stack<double> num_stack;
    for (auto p : postfix)
    {
        switch (p.Operator)
        {
        case '*':
            getTwoNums(num_stack, first, second);
            num_stack.push(first * second);
            break;
        case '/':
            getTwoNums(num_stack, first, second);
            num_stack.push(first / second);
            break;
        case '+':
            getTwoNums(num_stack, first, second);
            num_stack.push(first + second);
            break;
        case '-':
            getTwoNums(num_stack, first, second);
            num_stack.push(first - second);
            break;
        default:
            num_stack.push(p.Number);
            break;
        }
    }
    double result = num_stack.top();
    num_stack.pop();
    return result;
}

vector<stack_data> CalcExpression::getSeparate(string &infix)
{
    vector<stack_data> postfix;
    string str_num;
    for (auto p : infix)
    {
        if (isOperator(p))
        {
            if (!str_num.empty())
                postfix.emplace_back(stack_data{' ', stod(str_num)});
            str_num = "";
            postfix.emplace_back(stack_data{p, 0});
        }

        else if (isNumber(p))
        {
            str_num += p;
        }
        else if (p == '(' or p == ')')
        {
            if (!str_num.empty())
                postfix.emplace_back(stack_data{' ', stod(str_num)});
            str_num = "";
            postfix.emplace_back(stack_data{p, 0});
        }
    }
    if (!str_num.empty())
        postfix.emplace_back(stack_data{' ', stod(str_num)});
    str_num = "";

    vector<stack_data> new_postfix;
    char pre_char = '(';
    for (auto p : postfix)
    {
        if (p.Operator != ' ')
        {
            if (pre_char == '(' and (p.Operator == '-' or p.Operator == '+'))
                new_postfix.emplace_back(stack_data{' ', 0});
            pre_char = p.Operator;
        }
        else
            pre_char = ' ';
        new_postfix.emplace_back(p);
    }
    return new_postfix;
}

string CalcExpression::printSeparate(vector<stack_data> &temp)
{
    string out;
    for (auto t : temp)
    {
        if (t.Operator != ' ')
            out += t.Operator;
        else
            out += to_string(t.Number);
        out += ' ';
    }
    return out;
}

vector<stack_data> CalcExpression::getPostfixExp(vector<stack_data> &infix)
{
    stack<char> operator_stack;
    vector<stack_data> postfix;
    for (auto p : infix)
    {
        if (isOperator(p.Operator))
        {
            while (
                !operator_stack.empty() and
                isOperator(operator_stack.top()) and
                priority(operator_stack.top()) >= priority(p.Operator))
            {
                postfix.emplace_back(stack_data{operator_stack.top(), 0});
                operator_stack.pop();
            }
            operator_stack.push(p.Operator);
        }
        else if (p.Operator == '(')
        {
            operator_stack.push(p.Operator);
        }
        else if (p.Operator == ')')
        {
            while (operator_stack.top() != '(')
            {
                postfix.push_back(stack_data{operator_stack.top()});
                operator_stack.pop();
            }
            operator_stack.pop();
        }
        else
        {
            postfix.push_back(p);
        }
    }
    while (!operator_stack.empty())
    {
        postfix.push_back(stack_data{operator_stack.top(), 0});
        operator_stack.pop();
    }
    return postfix;
}

double CalcExpression::calc(string expression)
{
    vector<stack_data> postfix = getSeparate(expression);
    vector<stack_data> postfixExp = getPostfixExp(postfix);
    double result = postfixCalculate(postfixExp);
    return result;
}

int CalcExpression ::calcOnlyInt(string expression)
{
    vector<stack_data> postfix = getSeparate(expression);
    vector<stack_data> postfixExp = getPostfixExp(postfix);
    double result = postfixCalculate(postfixExp);
    return (int)result;
}
CalcExpression* CalcExpression ::getInstance()
{
    return instance;
}
