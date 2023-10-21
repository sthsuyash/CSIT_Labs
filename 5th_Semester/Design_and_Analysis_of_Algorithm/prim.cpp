/*
 * Program: Prim's Algorithm
 *
 * Prim's Algorithm is a Greedy Algorithm approach to find the Minimum Spanning Tree of a graph.
 * It finds a subset of the edges that forms a tree that includes every vertex, where the total
 * weight of all the edges in the tree is minimized. If the graph is not connected, then it finds
 * a minimum spanning forest (a minimum spanning tree for each connected component).
 *
 * Time Complexity: O(V^2)
 * Space Complexity: O(V)
 */

#include <iostream>
using namespace std;

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0};
int mincost = 0;
int cost[10][10];

int main()
{
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;
    cout << endl;
    while (ne < n)
    {
        int min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            cout << endl;
            cout << "Edge " << ne << ": (" << a << " " << b << ") cost: " << min;
            ne++;
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout << endl;
    cout << "Minimum cost = " << mincost << endl;

    return 0;
}
