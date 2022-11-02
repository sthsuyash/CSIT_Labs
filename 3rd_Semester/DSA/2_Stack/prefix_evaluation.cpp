// C++ program to evaluate a prefix expression.
#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    // If the character is a digit then it must be an operand
    return isdigit(c);
}

double evaluatePrefix(string exp)
{
    stack<double> Stack;
    for (int j = exp.size() - 1; j >= 0; j--)
    {
        // Push operand to Stack to convert exp[j] to digit subtract '0' from exp[j].
        if (isOperand(exp[j]))
        {
            Stack.push(exp[j] - '0');
        }
        else
        {
            // Operator encountered
            // Pop two elements from Stack
            double o1 = Stack.top();
            Stack.pop();
            double o2 = Stack.top();
            Stack.pop();

            // Use switch case to operate on o1 and o2 and perform o1 O o2.
            switch (exp[j])
            {
            case '+':
                Stack.push(o1 + o2);
                break;
            case '-':
                Stack.push(o1 - o2);
                break;
            case '*':
                Stack.push(o1 * o2);
                break;
            case '/':
                Stack.push(o1 / o2);
                break;
            }
        }
    }
    return Stack.top();
}

int main()
{
    string exp;
    cout << "Enter the prefix expression: ";
    cin >> exp;
    cout << "Evaluated value: " << evaluatePrefix(exp) << endl;
    return 0;
}
