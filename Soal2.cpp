#include <iostream>;
#include <stack>;
#include <string>;

using namespace std;

bool operatorCheck(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}

int priority(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}

string InfixToPostfix(string expression)
{
    stack<char>operators;

    string postfix;

    for (int i = 0;i< expression.length();i++)
    {
        if (expression[i] == ' ')
        {
            continue;
        }
        else if (expression[i] >= '0' && expression[i] <= '9')
        {
            string temp;
            temp += expression[i];
            int temp2 = i + 1;
            while (true)
            {

                if (expression[temp2] >= '0' && expression[temp2] <= '9')
                {
                    temp += expression[temp2];
                    temp2 += 1;
                }
                else
                {
                    break;
                }
            }
            postfix = postfix + temp + " ";

        }
        else if (operators.empty())
        {
            operators.push(expression[i]);
        }
        else if (operatorCheck(expression[i]))
        {
            if (priority(operators.top()) < priority(expression[i]))
            {
                operators.push(expression[i]);
            }
            else
            {
                while (!operators.empty() && priority(operators.top()) < priority(expression[i]))
                {

                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(expression[i]);
            }
        }
        else if (expression[i] == '(')
        {
            operators.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}
//Main program
int main()
{
    string expression;
    stack<int> calc;

    cout << "Welcome to my program!" << endl;
    cout << "This program will help you to calculate arithmetic expression." << endl;
    cout << "Please enter an arithmetic expression (Remember to enter space between numbers and operators):" << endl;
    getline(cin, expression);
    string postfix = InfixToPostfix(expression);
    cout << postfix << endl;

    for (int i = 0;i < postfix.length();i++)
    {
        if (postfix[i] == ' ')
        {
            continue;
        }
        else if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            string temp;
            int temp2 = i + 1;
            temp += postfix[i];
            while (true)
            {
                if (postfix[temp2] >= '0' && postfix[temp2] <= '9')
                {
                    temp += expression[temp2];
                    temp2 += 1;
                }
                else
                {
                    break;
                }
            }
            int n = atoi(temp.c_str());
            calc.push(n);
        }

        else if (postfix[i] == '+')
        {
            int temp1 = calc.top();
            calc.pop();
            int temp2 = calc.top();
            calc.pop();
            int result = temp2 + temp1;
            calc.push(result);
        }

        else if (postfix[i] == '-')
        {
            int temp1 = calc.top();
            calc.pop();
            int temp2 = calc.top();
            calc.pop();
            int result = temp2 - temp1;
            calc.push(result);
        }

        else if (postfix[i] == '*')
        {
            int temp1 = calc.top();
            calc.pop();
            int temp2 = calc.top();
            calc.pop();
            int result = temp2 * temp1;
            calc.push(result);
        }

        else if (postfix[i] == '/')
        {
            int temp1 = calc.top();
            calc.pop();
            int temp2 = calc.top();
            calc.pop();
            int result = temp2 / temp1;
            calc.push(result);
        }
    }
    cout << calc.top() << endl;
}