/*
 * Program: Fractional Knapsack Problem
 *
 * Fractional Knapsack Problem is a variation of Knapsack Problem where we can break an item.
 * We are given a set of items, each with a weight and a value and we need to determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 *
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compare(struct Item, struct Item);
double fractionalKnapsack(int, struct Item[], int);

int main()
{
    int W, n;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of knapsack: ";
    cin >> W;

    struct Item arr[n];
    cout << "Enter the value and weight of each item: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i].value >> arr[i].weight;

    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);

    return 0;
}

bool compare(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

/*
 * This function calculates the maximum value that can be obtained from the given items
 *
 * @param W - capacity of knapsack
 * @param arr - array of items
 * @param n - number of items
 *
 * @returns maximum value that can be obtained from the given items
 */
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}