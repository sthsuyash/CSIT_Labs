/*
 * Program: N-Queen Problem
 *
 * N-Queen Problem is a famous puzzle in which n-queens are to be placed on a nxn chess board such that no two queens are in the same row, column or diagonal.
 * The solution to this problem is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes then we backtrack and return false.
 *
 * Time Complexity: O(n!)
 * Space Complexity: O(n^2)
 *
 */

#define N 4
#include <iostream>
#include <cstdbool>

using namespace std;

void printSolution(int board[N][N]);
bool isSafe(int board[N][N], int, int);
bool solveNQUtil(int board[N][N], int);

int main()
{
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (solveNQUtil(board, 0) == false)
    {
        cout << "Solution does not exist";
        return 0;
    }

    printSolution(board);
    
    return true;
    return 0;
}

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// The function that solves the problem using backtracking
bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        // if it is safe to place the queen at position i,col -> place it
        if (isSafe(board, i, col))
        {

            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            // backtrack if the above condition is false
            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}