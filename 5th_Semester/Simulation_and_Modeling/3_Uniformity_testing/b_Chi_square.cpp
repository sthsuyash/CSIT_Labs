/*
 * Program for Chi Square Testing for Uniformity
 */
// H0: Uniformly distributed
// H1: Not uniformly distributed

/* Question
Use the chi-square test with α = 0.05 to test whether the data shown below are uniformly distributed.
In first ranges there are 15 random number , in second there are 5 random number,
in 3rd there are 10 random number, in fourth there are 10 and in 5th there are 20 random number.
Critical value at 0.05, n-1 = 9.49
*/

#include <iostream>
#include <iomanip>
using namespace std;

class chisquare
{
private:
    int n, observed[20], i, N, Expected;
    float Calculation[20], calculated_val, critical_val;

public:
    chisquare() // constructor to initialize values
    {
        N = 0;
        calculated_val = 0.00;
    }

    void getdata() // getting observed frequency
    {
        cout << "How many numbers ?: ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> observed[i];
        }
    }

    void calculation() // calculation of N(total frequency), Calculation(((Oi-Ei)^2/Ei)),final(?)
    {
        for (i = 0; i < n; i++)
        {
            N += observed[i];
        }
        Expected = N / n;
        for (i = 0; i < n; i++)
        {
            Calculation[i] = (float)((observed[i] - Expected) * (observed[i] - Expected)) / Expected;
            calculated_val += Calculation[i];
        }
    }

    void display() // display in tabulated format
    {
        cout << endl;
        cout << setw(5) << "S.No";
        cout << setw(5) << "Oi";
        cout << setw(5) << "Ei";
        cout << setw(22) << "((Oi-Ei)*(Oi-Ei))/Ei" << endl;
        for (i = 0; i < n; i++)
        {
            cout << setw(5) << i + 1;
            cout << setw(5) << observed[i];
            cout << setw(5) << Expected;
            cout << setw(10) << setprecision(2) << Calculation[i] << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        cout << setw(10) << N;
        cout << setw(15) << calculated_val;
        cout << endl;
    }

    void conclusion() // compare tabulated and calculated value and conclude if Ho is accepted.
    {
        cout << endl;
        cout << "Enter the critical value: ";
        cin >> critical_val;
        if (calculated_val < critical_val)
        {
            cout << "The test is accepted." << endl;
            cout << "Hence, The numbers are uniformly distributed.";
        }
        else
        {
            cout << "The test is rejected." << endl;
            cout << "Hence, The numbers are not uniformly distributed.";
        }
    }
};

int main()
{
    chisquare c;
    c.getdata();
    c.calculation();
    c.display();
    c.conclusion();
    return (0);
}
