/*
* Program: Vertex Cover Problem
*
* In the mathematical discipline of graph theory, a vertex cover (sometimes node cover) of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. 
* The problem of finding a minimum vertex cover is a classical optimization problem in computer science and is a typical example of an NP-hard optimization problem that has an approximation algorithm.
* The vertex cover problem is a classical optimization problem in computer science, and is one of Karp's 21 NP-complete problems.
* 
* Time Complexity: O(E)
* Space Complexity: O(E)
*
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_EDGES = 100;

void vertexCoverApproximation(int [][2], int);

int main()
{
    int numEdges;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    // Example graph represented by edges
    int edges[MAX_EDGES][2];
    cout << "Enter the edges of the graph (format: vertex1 vertex2):\n";
    for (int i = 0; i < numEdges; ++i)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Solve the Vertex Cover problem using the approximation algorithm
    vertexCoverApproximation(edges, numEdges);

    return 0;
}

void vertexCoverApproximation(int edges[MAX_EDGES][2], int numEdges)
{
    bool inVertexCover[MAX_EDGES] = {false};

    for (int i = 0; i < numEdges; ++i)
    {
        // Add one endpoint of each edge to the vertex cover
        inVertexCover[edges[i][0]] = true;
        inVertexCover[edges[i][1]] = true;
    }

    // Print the vertices in the vertex cover
    cout << "Approximate Vertex Cover: ";
    for (int i = 0; i < MAX_EDGES; ++i)
    {
        if (inVertexCover[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}