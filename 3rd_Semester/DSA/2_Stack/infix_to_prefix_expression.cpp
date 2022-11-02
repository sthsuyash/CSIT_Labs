#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '$')
    {
        return true;
    }
    return false;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

string convert(stack<char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++)
    {
        if (isalnum(infix[i]))
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                prefix += s.top();
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                {
                    while ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top())))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix, prefix;

    cout << "Enter the infix Expression: ";
    cin >> infix;
    stack<char> stack;
    prefix = convert(stack, infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
