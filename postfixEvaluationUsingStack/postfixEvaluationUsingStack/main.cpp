//  Postfix Evaluation Using Stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool IsOperator(char c)
{
    if (c == '*' || c == '-' || c == '+' || c == '/')
        return true;
    
    return false;
}

bool IsNumber(char c)
{
    if(c-'0' >= 0 && c-'0' <= 9)
        return true;
    
    return false;
}

int Calculate(int op1, int op2, char opr)
{
    if(opr == '*')
        return op1*op2;
    if(opr == '/')
        return op1/op2;
    if(opr == '+')
        return op1+op2;
    if(opr == '-')
        return op1-op2;
    return 0;
}

int PostfixEvaluation(string expression)
{
    stack<int> s;
    for(int i=0; i<expression.length(); ++i)
    {
        auto ex = expression[i];
        if(ex == ' ')
            continue;
        else if(IsOperator(ex))
        {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            s.push(Calculate(op1, op2, ex));
        }
        else
        {
            int num = 0;
            while(i<expression.length() && IsNumber(expression[i]))
            {
                num = num*10 + (expression[i]-'0');
                i++;
            }
            s.push(num);
            i--;
        }
    }
    return s.top();
}

int main(int argc, const char * argv[]) {
    
    cout << PostfixEvaluation("10 3 * 5 4 * + 9 -") << "\n";
    return 0;
}
