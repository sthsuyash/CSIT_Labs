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
    string plain_text, cipher_text, decrypted_text;
    int key;

    cout << "Enter the plain text: ";
    getline(cin, plain_text);

    cout << "Enter the key: ";
    cin >> key;

    cipher_text = encryptMsg(plain_text, key);
    cout << "Encrypted Text: " << cipher_text << endl;

    decrypted_text = decryptMsg(cipher_text, key);
    cout << "Decrypted Text: " << decrypted_text << endl;

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