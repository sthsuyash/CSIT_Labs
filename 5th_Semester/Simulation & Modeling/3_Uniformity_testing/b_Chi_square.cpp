// Chi Square Testing for Uniformity
// H0: Uniformly distributed
// H1: Not uniformly distributed

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
        cout << "Enter " << n << " numbers:" << endl;
        for (i = 0; i < n; i++)
        {
            cout << "Enter " << i + 1 << " number: " << endl;
            cin >> observed[i];
        }
    }

    void calculation() // calculation of N(total frequency), Calculation(((Oi-Ei)^2/Ei)),final(?)
    {
        for (i = 0; i < n; i++)
        {
            N = N + observed[i];
        }
        Expected = N / n;
        for (i = 0; i < n; i++)
        {
            Calculation[i] = (float)((observed[i] - Expected) * (observed[i] - Expected)) / Expected;
            calculated_val = calculated_val + Calculation[i];
        }
    }

    void display() // display in tabulated format
    {
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
        cout << "Enter the critical value:" << endl;
        cin >> critical_val;
        if (calculated_val < critical_val)
        {
            cout << "The test is accepted" << endl;
            cout << "Hence, The numbers are uniformly distributed" << endl;
        }
        else
        {
            cout << "The test is rejected" << endl;
            cout << "Hence, The numbers are not uniformly distributed" << endl;
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
