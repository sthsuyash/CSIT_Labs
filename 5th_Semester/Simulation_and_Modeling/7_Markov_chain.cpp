/*
* The probabilities of weather conditions (modeled as either rainy or sunny),
* given the weather on the preceding day, can be represented by a transition matrix:
        rainy  sunny
  rainy  0.4    0.6
  sunny  0.2    0.8

* What will be probability if today is sunny then rainy tomorrow?
* The weather on day 0 (today) is known to be sunny. This is represented by a
* vector in which the "sunny" entry is 100%, and the "rainy" entry is 0%:
   (rainy  sunny) = (0 1)

* Write a C/C++ program to find the weather of the next day by using Markov Chain Method.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void inputMatrix(float[][2], int, int);
void multiplyMatrices(float[][2], int[][2], float[][2], int, int, int);
void printMatrix(const float[][2], int, int, const char *);

int main()
{
    int vect[1][2] = {{0, 1}};
    float transMat[2][2], result[1][2];
    inputMatrix(transMat, 2, 2);
    printMatrix(transMat, 2, 2, "Transition");
    multiplyMatrices(result, vect, transMat, 1, 2, 2);
    cout << "\nWeather of the next day using Markov chain:\n";
    printMatrix(result, 1, 2, "Result");
    cout << "\nProbability of raining tomorrow = " << result[0][0] << endl;
    cout << "Probability of sunny tomorrow = " << result[0][1] << endl;
    return 0;
}

void inputMatrix(float matrix[][2], int rows, int cols)
{
    cout << "Enter Transition matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter the value of [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(float result[][2], int mat1[][2], float mat2[][2], int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

void printMatrix(const float matrix[][2], int rows, int cols, const char *name)
{
    cout << "\n"
         << name << " Matrix: \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << fixed << setprecision(2) << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}