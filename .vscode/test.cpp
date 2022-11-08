#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> Op;
stack<string> n;

string postFix;
int result = 0;

int calc(string x)
{
    int i = 0;
    for(int k = 0; k < x.length();k++)
    {   
        if(x[k] == '(')
        {
        while(x[i] != ')')
        {
            for(int j = 1; j < x.length(); j++){
                if(x[j] >= 0 && x[j] <= 9)
                {
                    postFix = x[j];
                    if(x[j+1]>= 0 && x[j+1] <= 9)
                    {
                        postFix += x[j+1];
                        n.push(postFix);
                    }else 
                        n.push(postFix);
                }else
                {
                    Op.push(x[i]);
                    if(Op.top() == ')'){
                        Op.pop();
                    }
                }
            }

            i++;
        }
            int temp = 0;
            if(Op.top() == '+')
            {
                temp = stoi(n.top());
                n.pop();
                result = temp + stoi(n.top());
                n.pop();

                Op.pop();

            } else if(Op.top() == '-')
            {
                temp = stoi(n.top());
                n.pop();
                result = temp - stoi(n.top());
                n.pop();

                Op.pop();

            } else if(Op.top() == '*')
            {
                temp = stoi(n.top());
                n.pop();
                result = temp * stoi(n.top());
                n.pop();

                Op.pop();

            }else if(Op.top() == '/')
            {
                temp = stoi(n.top());
                n.pop();
                result = temp / stoi(n.top());
                n.pop();

                Op.pop();
            }
        }
        
    }
    
    return result;
}

int main()
{
    string x = "(2+3)*3-(10/5)";
    cout << calc(x);
    
    return 0;
}