/*
*Q) Customers arrive in a bank according to a Poisson's process with mean inter arrival time of 10 minutes.
* Customers spend an average of 5 minutes on the single available counter, and leave.

* WAP in C/C++ to find:
    1. Probability that a customer will not have to wait at the counter.
    2. Expected number of customers in the bank.
    3. Time can a customer expect to spend in the bank.

    Here given,
    average arrival rate (L) = 6 per hour (1 in every 10 minutes)
    average service rate (m) = 12 per hour (1 in every 5 minutes)

*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float L, m, e; // L = average arrival rate, m = average service rate , e = expected number of customer
    float p, et;   // p = probability of not wait in counter (system free time), et = expected time spend in bank
    cout << "Enter the average arrival rate of customers per hours: ";
    cin >> L;
    cout << "Enter the average service rate per hour: ";
    cin >> m;

    p = 1 - L / m;
    e = L / (m - L);
    et = 1 / (m - L);
    et = et * 60;

    cout << "\nThe probability that a customer wont't have to wait at counter: " << p << endl;
    cout << "Expected number of customer in the bank: " << setprecision(2) << e << endl;
    cout << "Expected time to be spent in bank: " << setprecision(2) << et << " minutes";

    return 0;
}