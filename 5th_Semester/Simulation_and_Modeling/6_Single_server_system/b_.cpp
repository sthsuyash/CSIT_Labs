/*
* Q) At the ticket counter of football stadium, people come in queue and purchase tickets. Arrival rate of customers is 1/min.
*It takes at the average 20 seconds to purchase the ticket.

* WAP in C/C++ to calculate total time spent by a sports fan to be seated in his seat ,
* if it takes 1.5 minutes to reach the correct seat after purchasing the ticket.
* If a fan comes exactly before 2 minutes before the game starts, can sports fan expects to be seated for the kick off?

*Here given,
    average arrival rate (L) = 1 per minute
    average service time (m) = 3 per minute (1 per 20 second)
*/
#include <iostream>
using namespace std;

int main()
{
    float L, m, ws, rt; // L = average arrival rate, m = average service rate
                        // ws = waiting time in system, rt = remaining time of fan
    float p, et, tot_time;

    cout << "Enter the average arrival rate of customers per minute: ";
    cin >> L;
    cout << "Enter the average service rate per minute: ";
    cin >> m;
    cout << "Enter the remaining time of fan: ";
    cin >> rt;

    ws = 1 / (m - L);
    tot_time = ws + 1.5;

    tot_time <= rt ? cout << "Fan will reach to see the kick-off" : cout << "Fan will not reach to see the kick-off";
    return 0;
}