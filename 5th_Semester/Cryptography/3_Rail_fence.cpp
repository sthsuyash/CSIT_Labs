/*
 * C++ program to Implement Rail Fence Cipher
 */

#include <iostream>
#include <string.h>
#include "./returnName.h"
using namespace std;

string encryptMsg(string, int);
string decryptMsg(string, int);

int main()
{
    generateHeader("Rail Fence Cipher");

    int choice, key;
    string plain_text, cipher_text, decrypted_text;

    do
    {
        cout << endl << "Menu:\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the plain text: ";
            cin.ignore();
            getline(cin, plain_text);
            cout << "Enter the key: ";
            cin >> key;
            cipher_text = encryptMsg(plain_text, key);
            cout << "Encrypted Text: " << cipher_text << endl;
            break;

        case 2:
            cout << "Enter the cipher text: ";
            cin.ignore();
            getline(cin, cipher_text);
            cout << "Enter the key: ";
            cin >> key;
            decrypted_text = decryptMsg(cipher_text, key);
            cout << "Decrypted Text: " << decrypted_text << endl;
            break;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            break;
        }
    } while (choice != 3);

    cin.get();
    return 0;
}

// function to encrypt a message
string encryptMsg(string msg, int key)
{
    int msgLen = msg.length(), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];
    string return_string;

    for (i = 0; i < key; ++i)
        for (j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for (i = 0; i < msgLen; ++i)
    {
        railMatrix[row][col++] = msg[i];

        if (row == 0 || row == key - 1)
            k = k * (-1);

        row = row + k;
    }

    for (i = 0; i < key; ++i)
    {
        for (j = 0; j < msgLen; ++j)
        {
            if (railMatrix[i][j] != '\n')
            {
                return_string += railMatrix[i][j];
            }
        }
    }

    return return_string;
}

// function to decrypt a message
string decryptMsg(string enMsg, int key)
{
    int msgLen = enMsg.length(), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
    string return_string;

    for (i = 0; i < key; ++i)
        for (j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';

    for (i = 0; i < msgLen; ++i)
    {
        railMatrix[row][col++] = '*';

        if (row == 0 || row == key - 1)
            k = k * (-1);

        row = row + k;
    }

    for (i = 0; i < key; ++i)
        for (j = 0; j < msgLen; ++j)
            if (railMatrix[i][j] == '*')
                railMatrix[i][j] = enMsg[m++];

    row = col = 0;
    k = -1;

    for (i = 0; i < msgLen; ++i)
    {
        return_string += railMatrix[row][col++];

        if (row == 0 || row == key - 1)
        {
            k = k * (-1);
        }
        row = row + k;
    }

    return return_string;
}