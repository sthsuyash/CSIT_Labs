#include<iostream>
#include "../../../utils/generateHeader.h"
#include "../../../utils/name.h"

using namespace std;

int main(){
    generateHeader("Fibonacci Sequence Program");

    int n, a = 0, b = 1, f;
    cout << "Enter the number of terms in the Fibonacci sequence: ";
    cin >> n;

    cout << "Fibonacci Sequence: ";
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            f = i;
        } else {
            f = a + b;
            a = b;
            b = f;
        }
        cout << f << " ";
    }

    generateName("1(b)");
    return 0;
}