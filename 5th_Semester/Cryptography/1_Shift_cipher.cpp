/*
 * Cpp Program for Shift Cipher
 */

#include <iostream>
#include <string>
#include "./returnName.h"
using namespace std;

int getKey();

string encrypt(string, int);

string decrypt(string, int);

int main()
{
    int key;
    string plaintext, ciphertext;

    generateHeader("Program for Shift Cipher");

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key (an integer between 0 to 25): ";
    key = getKey();

    ciphertext = encrypt(plaintext, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    plaintext = decrypt(ciphertext, key);
    cout << "Decrypted Text: " << plaintext << endl;

    cin.get();
    return 0;
}

// function to get the key from user and validate it
int getKey()
{
    int key;
    cin >> key;
    if (key < 0 || key > 25)
    {
        cout << "Invalid key. Enter again: ";
        getKey();
    }
    return key;
}

// function to encrypt the plaintext using shift cipher
string encrypt(string text, int key)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            char encrypted = ((text[i] - base + key) % 26) + base;
            result += encrypted;
        }
        else
        {
            result += text[i];
        }
    }
    return result;
}

// function to decrypt the ciphertext using shift cipher
string decrypt(string cipher, int key)
{
    return encrypt(cipher, 26 - key);
}