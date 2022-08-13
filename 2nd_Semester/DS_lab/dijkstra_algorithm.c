/**** algorithm ( Dijkstra's algorithm for shortest path problem ) ****/

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

// function declaration // working code written after main function
void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startnode);

// driver function
int main(void)
{
    int vertices, startNode, costAdjMat[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Enter the matrix made up by calculating the matrix form of the paths in circuit
    printf("\nEnter the cost adjacency matrix with entry 0 for nonadjacent n:\n");
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            scanf("%d", &costAdjMat[i][j]);
        }
    }

    // starting node value for the algorithm to run
    printf("\nEnter the starting node: ");
    scanf("%d", &startNode);

    // call the dijkstra algorithm to find the shortest path in the circuit
    dijkstra(costAdjMat, vertices, startNode);

    return 0;
}

// working function
void dijkstra(int costAdjMat[MAX][MAX], int vertices, int startNode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX], visited[MAX];
    int count, minDistance, nextNode;

    // pred[] stores the predecessor of each node
    // count gives the number of nodes seen so far

    // create the cost matrix 
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

    // initialize pred[], distance[] and visited[]
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

        // nextNode gives the node at a minimum Distance
        for (int i = 1; i <= vertices; i++)
        {
            if (distance[i] < minDistance && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        // check if a better path exists through nextNode
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

    // print the path and distance of each node
    for (int i = 1; i <= vertices; i++)
    {
        if (i != startNode)
        {
            printf("\n Distance of node %d = %d", i, distance[i]);
            printf("\n Path = %d", i);
            int j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != startNode);
        }
    }
}