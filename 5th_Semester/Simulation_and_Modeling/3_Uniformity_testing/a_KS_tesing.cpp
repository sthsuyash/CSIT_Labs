/*
 * Cpp program for K-S Testing for Uniformity
 */
// H0: Uniformly distributed
// H1: Not uniformly distributed

/*
Suppose that the five random numbers 0.44, 0.81, 0.14, 0.05, 0.93 were generated,
and it is desire to perform a test for uniformity using the K-S test with a
level of significance α of 0.05. Critical value = 0.565.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class KS
{
private:
    float numbers[20];
    float D, tabulatedD;
    float Dplusmax, Dminusmax;
    float Dplus[20], Dminus[20];
    float ratio[20], ratiominus[20];
    int n;

public:
    void getdata() // to get the random numbers
    {
        cout << "How many numbers ?: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter number " << i + 1 << ": ";
            cin >> numbers[i];
        }
    }

    void BubbleSort() // arrange the number in increasing order
    {
        float temp;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (numbers[j] > numbers[j + 1])
                {
                    temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }

        cout << "The numbers in ascending order is:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setprecision(2) << numbers[i] << " ";
        }
    }

    void calculate() // find D+, D-
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            ratio[i] = (float)j / n;
            ratiominus[i] = (float)i / n;
            Dplus[i] = ratio[i] - numbers[i];
            Dminus[i] = numbers[i] - ratiominus[i];
        }
    }

    void display() // display the tabulated format and find D
    {
        cout << endl
             << endl;
        cout << setw(10) << "i"; // here setw() function indicates the output field's width in character

        for (int i = 1; i <= n; i++)
            cout << setw(10) << i;
        cout << endl;

        cout << setw(10) << "R(i)";
        for (int i = 0; i < n; i++)
            cout << setw(10) << numbers[i];
        cout << endl;

        cout << setw(10) << "i/n";
        for (int i = 0; i < n; i++)
            cout << setw(10) << setprecision(2) << ratio[i];
        cout << endl;

        cout << setw(10) << "D+";
        for (int i = 0; i < n; i++)
            cout << setw(10) << setprecision(2) << Dplus[i];
        cout << endl;

        cout << setw(10) << "D-";
        for (int i = 0; i < n; i++)
            cout << setw(10) << setprecision(2) << Dminus[i];
        cout << endl;

        Dplusmax = Dplus[0];
        Dminusmax = Dminus[0];
        for (int i = 1; i < n; i++)
        {

            Dplusmax = (Dplus[i] > Dplusmax) ? Dplus[i] : Dplusmax;
            Dminusmax = (Dminus[i] > Dminusmax) ? Dminus[i] : Dminusmax;
        }
        cout << "D+ max: " << Dplusmax << endl;
        cout << "D- max: " << Dminusmax << endl;
        cout << "D = max(" << Dplusmax << ", " << Dminusmax << ") =";
        D = (Dplusmax > Dminusmax) ? Dplusmax : Dminusmax;
        cout << D << endl;
    }

    void conclusion() // asking tabulated D and comparing it with D(calculated)
    {
        cout << "Enter the tabulated value:";
        cin >> tabulatedD;

        if (D < tabulatedD)
        {
            cout << "The test is accepted." << endl;
            cout << "Hence, numbers are uniformly distributed." << endl;
        }
        else
        {
            cout << "The test is rejected." << endl;
            cout << "Hence, numbers are not uniformly distributed." << endl;
        }
    }
};

int main() // main function
{
    KS ks1;        // object of KS class
    ks1.getdata(); // function calls
    ks1.BubbleSort();
    ks1.calculate();
    ks1.display();
    ks1.conclusion();
    return 0;
}
