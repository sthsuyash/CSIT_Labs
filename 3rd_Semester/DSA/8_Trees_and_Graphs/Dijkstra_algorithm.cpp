/**** algorithm ( Dijkstra's algorithm for shortest path problem ) ****/

#include <iostream>
#include <climits>
using namespace std;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum = INT_MAX, ind;

    for (int k = 0; k < 6; k++)
    {
        if (Tset[k] == false && distance[k] <= minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6], int src) // adjacency matrix
{
    int distance[6]; //  array to calculate the minimum distance for each node
    bool Tset[6];    // boolean array to mark visited and unvisited for each node

    for (int k = 0; k < 6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; // Source vertex distance is set 0

    for (int k = 0; k < 6; k++)
    {
        int m = miniDist(distance, Tset);
        Tset[m] = true;
        for (int k = 0; k < 6; k++)
        {
            // updating the distance of neighbouring vertex
            if (!Tset[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < 6; k++)
    {
        char str = 65 + k;
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}

int main()
{
    int graph[6][6] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    DijkstraAlgo(graph, 0);
    return 0;
}

// #include <iostream>
// #define INFINITY 9999
// #define MAX 10
// using namespace std;

// // function declaration // working code written after main function
// void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startnode);

// // driver function
// int main()
// {
//     int vertices, startNode, costAdjMat[MAX][MAX];

//     cout << "Enter number of vertices: ";
//     cin >> vertices;

//     // Enter the matrix made up by calculating the matrix form of the paths in circuit
//     cout << "\nEnter the cost adjacency matrix with entry 0 for nonadjacent n:\n";
//     for (int i = 1; i <= vertices; i++)
//     {
//         for (int j = 1; j <= vertices; j++)
//         {
//             cin >> costAdjMat[i][j];
//         }
//     }

//     // starting node value for the algorithm to run
//     cout << "\nEnter the starting node: ";
//     cin >> startNode;

//     // call the dijkstra algorithm to find the shortest path in the circuit
//     dijkstra(costAdjMat, vertices, startNode);

//     return 0;
// }

// // working function
// void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startNode)
// {
//     int cost[MAX][MAX], distance[MAX], pred[MAX], visited[MAX];
//     int count, minDistance, nextNode;

//     // pred[] stores the predecessor of each node
//     // count gives the number of nodes seen so far

//     // create the cost matrix
//     for (int i = 1; i <= vertices; i++)
//     {
//         for (int j = 1; j <= vertices; j++)
//         {
//             if (costAdjMat[i][j] == 0)
//             {
//                 cost[i][j] = INFINITY;
//             }
//             else
//             {
//                 cost[i][j] = costAdjMat[i][j];
//             }
//         }
//     }

//     // initialize pred[], distance[] and visited[]
//     for (int i = 1; i <= vertices; i++)
//     {
//         distance[i] = cost[startNode][i];
//         pred[i] = startNode;
//         visited[i] = 0;
//     }
//     distance[startNode] = 0;
//     visited[startNode] = 1;
//     count = 1;

//     while (count < vertices - 1)
//     {
//         minDistance = INFINITY;

//         // nextNode gives the node at a minimum Distance
//         for (int i = 1; i <= vertices; i++)
//         {
//             if (distance[i] < minDistance && !visited[i])
//             {
//                 minDistance = distance[i];
//                 nextNode = i;
//             }
//         }

//         // check if a better path exists through nextNode
//         visited[nextNode] = 1;
//         for (int i = 1; i <= vertices; i++)
//         {
//             if (!visited[i])
//             {
//                 if (minDistance + cost[nextNode][i] < distance[i])
//                 {
//                     distance[i] = minDistance + cost[nextNode][i];
//                     pred[i] = nextNode;
//                 }
//             }
//         }
//         count++;
//     }

//     // print the path and distance of each node
//     for (int i = 1; i <= vertices; i++)
//     {
//         if (i != startNode)
//         {
//             cout << "\nDistance of node " << i << "= " << distance[i];
//             cout << "\nPath = " << i;
//             int j = i;
//             do
//             {
//                 j = pred[j];
//                 cout << "<-" << j;
//             } while (j != startNode);
//         }
//     }
// }
