/*
 * Program: 0/1 Knapsack Problem
 *
 * The 0/1 knapsack problem is a combinatorial optimization problem where we have a set of items, each with a weight and a value,
 * and we need to determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 *
 */

#include <iostream>
#include <cstdlib>
// #include "../../utils/generateHeader.h"
// #include "../../utils/name.h"
#include <iomanip>

using namespace std;

struct Item
{
    int id;
    int weight;
    int value;
};

int compare(const void *, const void *);
void fractionalKnapsack(struct Item[], int, int);

int main()
{
    // generateHeader("0/1 Knapsack Problem Program");

    int n, capacity;

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    struct Item items[n];
    cout << "Enter the weight and value of each item: ";
    for (int i = 0; i < n; i++)
    {
        items[i].id = i + 1;
        cin >> items[i].weight >> items[i].value;
    }

    fractionalKnapsack(items, n, capacity);

    // generateName("0");
    return 0;
}

/*
 * This function compares two items based on their value per unit weight
 *
 * @param a - pointer to the first item
 * @param b - pointer to the second item
 *
 * @returns 1 if value per unit weight of the first item is greater than that of the second item, else -1
 */
int compare(const void *a, const void *b)
{
    double r1 = ((struct Item *)b)->value / (double)((struct Item *)b)->weight;
    double r2 = ((struct Item *)a)->value / (double)((struct Item *)a)->weight;
    return r1 > r2 ? 1 : -1;
}

/*
 * This function solves the 0/1 knapsack problem using greedy approach
 *
 * @param items[] - array of items
 * @param n - number of items
 * @param capacity - maximum capacity of the knapsack
 *
 * @returns void
 */
void fractionalKnapsack(struct Item items[], int n, int capacity)
{
    // Sort items in decreasing order of value per unit weight
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= capacity)
        {
            // If the entire item can be included, add it to the knapsack
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            // Otherwise, add a fraction of the item to the knapsack
            double fraction = (double)capacity / (double)items[i].weight;
            totalValue += items[i].value * fraction;
            capacity = 0;
            break;
        }
    }

    cout << "Maximum knapsack value: " << setprecision(2) << fixed << totalValue << endl;
}

// {{1, 10, 60}, {2, 20, 100}, {3, 30, 120}}