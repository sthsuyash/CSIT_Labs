// Using inbuilt stack library to create stack
#include <iostream>
#include <stack>
using namespace std;

int priority(char exp)
{
    if (exp == '+' || exp == '-')
        return 1;

    if (exp == '*' || exp == '/')
        return 2;

    if (exp == '$')
        return 3;

    return 0;
}

string convert(string infix)
{
    int i = 0;
    string postfix = "";
    stack<int> s;

    while (infix[i] != '\0')
    {
        // if operand add to the postfix expression
        if (isalnum(infix[i]))
        {
            postfix += infix[i];
            i++;
        }
        // if opening bracket then push the stack
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
        }
        // if closing bracket encounted then keep popping from stack until
        // closing a pair opening bracket is not encountered
        else if (infix[i] == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else
        {
            while (!s.empty() && priority(infix[i]) <= priority(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
    string infix, postfix;

    cout << "Enter the infix expression: ";
    cin >> infix;
    postfix = convert(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
