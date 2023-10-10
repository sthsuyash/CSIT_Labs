/*
* Program: Dijkstra's Algorithm
*
* Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks.

* The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes, but a more common variant
* fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a shortest-path tree.
* For a given source node in the graph, the algorithm finds the shortest path between that node and every other. It can also be used for finding the
* shortest paths from a single node to a single destination node by stopping the algorithm once the shortest path to the destination node has been determined.
*
* For example, if the nodes of the graph represent cities and edge path costs represent driving distances between pairs of cities connected by a direct road,
* Dijkstra's algorithm can be used to find the shortest route between one city and all other cities. As a result, the shortest path algorithm is widely used
* in network routing protocols, most notably IS-IS and Open Shortest Path First (OSPF). It is also employed as a subroutine in other algorithms such as Johnson's.
*
* Time Complexity: O(V^2)
* Space Complexity: O(V)
*/

#include <iostream>
#include <limits>
// #include "../../utils/generateHeader.h"
// #include "../../utils/name.h"
using namespace std;

#define INFINITY numeric_limits<int>::max()
#define MAX 10

void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startNode);

int main()
{
    // generateHeader("Dijkstra's Algorithm Program");

    int vertices, startNode, costAdjMat[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter the cost adjacency matrix with entry 0 for nonadjacent:\n";
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            cin >> costAdjMat[i][j];
        }
    }

    cout << "Enter the starting node: ";
    cin >> startNode;

    dijkstra(costAdjMat, vertices, startNode);

    // generateName("0");
    return 0;
}

void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startNode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX], visited[MAX];
    int count, minDistance, nextNode;

    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            if (costAdjMat[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }
            else
            {
                cost[i][j] = costAdjMat[i][j];
            }
        }
    }

    for (int i = 1; i <= vertices; i++)
    {
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }
    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while (count < vertices - 1)
    {
        minDistance = INFINITY;
        for (int i = 1; i <= vertices; i++)
        {
            if (distance[i] < minDistance && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }
        visited[nextNode] = 1;
        for (int i = 1; i <= vertices; i++)
        {
            if (!visited[i])
            {
                if (minDistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
            }
        }
        count++;
    }

    for (int i = 1; i <= vertices; i++)
    {
        if (i != startNode)
        {
            cout << "\nDistance of node " << i << " = " << distance[i] << endl;
            cout << "Path = " << i;
            int j = i;
            do
            {
                j = pred[j];
                cout << "<-" << j;
            } while (j != startNode);
            cout << endl;
        }
    }
}
