#include <iostream>
#include <cmath>
#include <cstring>
// #include "./returnName.h"
using namespace std;

void getKeyMatrix(const char *, int[][4], int);
void printKeyMatrix(int[][4], int);
int modInverse(int, int);
int determinant(int[][4]);
void adjugate(int[][4], int[][4]);
void encrypt(const char *, int[][4], int, char *);
void decrypt(const char *, int[][4], int, char *);

int main()
{
    // generateHeader("Program to demonstrate Hill Cipher");
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Encrypt Text" << endl;
        cout << "2. Decrypt Text" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            char message[100], key[16];

            cout << "Enter the message (uppercase letters): ";
            cin >> message;

            cout << "Enter the key matrix (e.g., for a 2x2 matrix, enter 4 uppercase letters): ";
            cin >> key;

            int n = sqrt(strlen(key));
            if (n * n != strlen(key))
            {
                cout << "Invalid key matrix size. Please enter a square key matrix." << endl;
                continue;
            }

            int keyMatrix[4][4];
            getKeyMatrix(key, keyMatrix, n);

            cout << "Key Matrix:" << endl;
            printKeyMatrix(keyMatrix, n);

            char ciphertext[100];
            encrypt(message, keyMatrix, n, ciphertext);

            cout << "Encrypted ciphertext: " << ciphertext << endl;
        }
        else if (choice == 2)
        {
            char ciphertext[100], key[16];

            cout << "Enter the ciphertext (uppercase letters): ";
            cin >> ciphertext;

            cout << "Enter the key matrix (e.g., for a 2x2 matrix, enter 4 uppercase letters): ";
            cin >> key;

            int n = sqrt(strlen(key));
            if (n * n != strlen(key))
            {
                cout << "Invalid key matrix size. Please enter a square key matrix." << endl;
                continue;
            }

            int keyMatrix[4][4];
            getKeyMatrix(key, keyMatrix, n);

            cout << "Key Matrix:" << endl;
            printKeyMatrix(keyMatrix, n);

            char plaintext[100];
            decrypt(ciphertext, keyMatrix, n, plaintext);
            cout << "Decrypted plaintext: " << plaintext << endl;
        }
        else if (choice == 3)
            break;
        else
            cout << "Invalid choice. Please enter a valid option." << endl;
    }

    cin.get();
    return 0;
}

// Function to get the key matrix from the key string
void getKeyMatrix(const char *key, int keyMatrix[][4], int n)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            keyMatrix[i][j] = (key[k++] - 'A') % 26;
        }
    }
}

// Function to print the key matrix
void printKeyMatrix(int keyMatrix[][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
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
int determinant(int matrix[][4])
{
    int det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    return det;
}

// Function to find the adjugate of a matrix
void adjugate(int matrix[][4], int adjMatrix[][4])
{
    adjMatrix[0][0] = matrix[1][1];
    adjMatrix[0][1] = -matrix[0][1];
    adjMatrix[1][0] = -matrix[1][0];
    adjMatrix[1][1] = matrix[0][0];
}

// Function to encrypt the message
void encrypt(const char *message, int keyMatrix[][4], int n, char *ciphertext)
{
    int m = 26; // Modulo 26 for English alphabets
    int len = strlen(message);
    int k = 0;

    for (int i = 0; i < len; i += n)
    {
        int messageVector[4] = {0};
        int cipherVector[4] = {0};

        // Generate vector for the message
        for (int j = 0; j < n; j++)
        {
            if (i + j < len)
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
            if (i + j < len)
            {
                ciphertext[k++] = static_cast<char>(cipherVector[j] + 'A');
            }
        }
    }
    ciphertext[k] = '\0';
}

// Function to decrypt the message
void decrypt(const char *ciphertext, int keyMatrix[][4], int n, char *plaintext)
{
    int m = 26; // Modulo 26 for English alphabets
    int len = strlen(ciphertext);
    int adjMatrix[4][4], detInverse;

    adjugate(keyMatrix, adjMatrix);

    int det = determinant(keyMatrix);

    detInverse = modInverse(det, m);

    if (detInverse == -1)
    {
        cout << "Modular inverse of the determinant does not exist. Decryption is not possible." << endl;
        return;
    }

    int keyInverse[4][4] = {0};

    // Calculate the key inverse
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            keyInverse[i][j] = (adjMatrix[i][j] * detInverse) % m;
            keyInverse[i][j] = (keyInverse[i][j] + m) % m; // Ensure non-negative values
        }
    }

    int k = 0;
    for (int i = 0; i < len; i += n)
    {
        int cipherVector[4] = {0};
        int messageVector[4] = {0};

        // Generate vector for the ciphertext
        for (int j = 0; j < n; j++)
        {
            if (i + j < len)
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
            if (i + j < len)
            {
                plaintext[k++] = static_cast<char>(messageVector[j] + 'A');
            }
        }
    }
    plaintext[k] = '\0';
}
