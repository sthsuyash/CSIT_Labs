/*
* Program to implement Hill Cipher
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "./returnName.h"
using namespace std;

void getKeyMatrix(const string &, vector<vector<int>> &, int);
int modInverse(int, int);
int determinant(const vector<vector<int>> &);
void adjugate(const vector<vector<int>> &, vector<vector<int>> &);
string encrypt(const string &, const vector<vector<int>> &, int);
string decrypt(const string &, const vector<vector<int>> &, int);

int main()
{
    generateHeader("Program to implement Hill Cipher");
    string message, key;

    cout << "Enter the message (uppercase letters): ";
    cin >> message;

    cout << "Enter the key matrix (e.g., for a 2x2 matrix, enter 4 uppercase letters): ";
    cin >> key;

    int n = sqrt(key.length());

    if (n * n != key.length())
    {
        cout << "Invalid key matrix size. Please enter a square key matrix." << endl;
        return 1;
    }

    vector<vector<int>> keyMatrix;
    getKeyMatrix(key, keyMatrix, n);

    string ciphertext = encrypt(message, keyMatrix, n);

    cout << "Encrypted ciphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, keyMatrix, n);

    cout << "Decrypted plaintext: " << decryptedText << endl;

    cin.get();
    return 0;
}

/*
===============
Output example:
===============
Enter the message (uppercase letters): JULY
Enter the key matrix (e.g., for a 2x2 matrix, enter 4 uppercase letters): LHDI
Encrypted ciphertext: FFDR
Decrypted plaintext: JULY
*/

// Function to get the key matrix from the key string
void getKeyMatrix(const string &key, vector<vector<int>> &keyMatrix, int n)
{
    keyMatrix.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            keyMatrix[i][j] = (key[i * n + j] - 'A') % 26;
        }
    }
}

// Function to calculate the modular inverse of a number 'a' modulo 'm'
int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
        {
            return x;
        }
    }
    return -1; // Modular inverse does not exist
}

// Function to compute the determinant of a square matrix
int determinant(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 1)
    {
        return matrix[0][0];
    }
    if (n == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> submatrix(n - 1, vector<int>(n - 1, 0));
        for (int j = 1; j < n; j++)
        {
            int k = 0;
            for (int l = 0; l < n; l++)
            {
                if (l != i)
                {
                    submatrix[j - 1][k] = matrix[j][l];
                    k++;
                }
            }
        }
        det += matrix[0][i] * determinant(submatrix) * ((i % 2 == 0) ? 1 : -1);
    }
    return det;
}

// Function to find the adjugate of a matrix
void adjugate(const vector<vector<int>> &matrix, vector<vector<int>> &adjMatrix)
{
    int n = matrix.size();
    adjMatrix.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<vector<int>> submatrix(n - 1, vector<int>(n - 1, 0));
            int k1 = 0, k2 = 0;
            for (int k = 0; k < n; k++)
            {
                if (k != i)
                {
                    k2 = 0;
                    for (int l = 0; l < n; l++)
                    {
                        if (l != j)
                        {
                            submatrix[k1][k2] = matrix[k][l];
                            k2++;
                        }
                    }
                    k1++;
                }
            }
            adjMatrix[j][i] = determinant(submatrix) * (((i + j) % 2 == 0) ? 1 : -1);
        }
    }
}

// Function to encrypt the message
string encrypt(const string &message, const vector<vector<int>> &keyMatrix, int n)
{
    string ciphertext = "";
    int m = 26; // Modulo 26 for English alphabets

    for (size_t i = 0; i < message.length(); i += n)
    {
        vector<int> messageVector(n, 0);
        vector<int> cipherVector(n, 0);

        // Generate vector for the message
        for (int j = 0; j < n; j++)
        {
            if (i + j < message.length())
            {
                messageVector[j] = (message[i + j] - 'A') % m;
            }
        }

        // Perform Hill Cipher encryption
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cipherVector[j] += keyMatrix[j][k] * messageVector[k];
            }
            cipherVector[j] %= m;
        }

        // Generate the encrypted text
        for (int j = 0; j < n; j++)
        {
            if (i + j < message.length())
            {
                ciphertext += static_cast<char>(cipherVector[j] + 'A');
            }
        }
    }

    return ciphertext;
}

// Function to decrypt the message
string decrypt(const string &ciphertext, const vector<vector<int>> &keyMatrix, int n)
{
    string plaintext = "";
    int m = 26; // Modulo 26 for English alphabets

    vector<vector<int>> adjMatrix;
    adjugate(keyMatrix, adjMatrix);

    int det = determinant(keyMatrix);
    int detInverse = modInverse(det, m);

    if (detInverse == -1)
    {
        cout << "Modular inverse of the determinant does not exist. Decryption is not possible." << endl;
        return plaintext;
    }

    vector<vector<int>> keyInverse(n, vector<int>(n, 0));

    // Calculate the key inverse
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            keyInverse[i][j] = (adjMatrix[i][j] * detInverse) % m;
            keyInverse[i][j] = (keyInverse[i][j] + m) % m; // Ensure non-negative values
        }
    }

    for (size_t i = 0; i < ciphertext.length(); i += n)
    {
        vector<int> cipherVector(n, 0);
        vector<int> messageVector(n, 0);

        // Generate vector for the ciphertext
        for (int j = 0; j < n; j++)
        {
            if (i + j < ciphertext.length())
            {
                cipherVector[j] = (ciphertext[i + j] - 'A') % m;
            }
        }

        // Perform Hill Cipher decryption
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                messageVector[j] += keyInverse[j][k] * cipherVector[k];
            }
            messageVector[j] %= m;
        }

        // Generate the decrypted text
        for (int j = 0; j < n; j++)
        {
            if (i + j < ciphertext.length())
            {
                plaintext += static_cast<char>(messageVector[j] + 'A');
            }
        }
    }

    return plaintext;
}
