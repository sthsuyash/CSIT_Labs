/*
 * Program to implement Vigenere Cipher
 * use capital letters only
 */

#include <bits/stdc++.h>
#include "./returnName.h"
using namespace std;

string generateKey(string, string);
string cipherText(string, string);
string originalText(string, string);

int main()
{
    generateHeader("Program to implement Vigenere Cipher");

    while (true)
    {
        cout << endl
             << "Menu:" << endl;
        cout << "1. Encrypt Text" << endl;
        cout << "2. Decrypt Text" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string str, keyword;

            cout << "Enter the plain text: ";
            cin.ignore();
            getline(cin, str);

            cout << "Enter the keyword (string): ";
            cin >> keyword;

            string key = generateKey(str, keyword);
            string cipher_text = cipherText(str, key);

            cout << "Encrypted Text: " << cipher_text << endl;
        }
        else if (choice == 2)
        {
            string cipher_text, keyword;

            cout << "Enter the cipher text: ";
            cin.ignore();
            getline(cin, cipher_text);

            cout << "Enter the keyword (string): ";
            cin >> keyword;

            string key = generateKey(cipher_text, keyword);
            string orig_text = originalText(cipher_text, key);

            cout << "Decrypted Text: " << orig_text << endl;
        }
        else if (choice == 3)
            break;
        else
            cout << "Invalid choice. Please enter a valid option." << endl;
    }
    cin.get();
    return 0;
}

// This function generates the key in a cyclic manner until it's length isn't equal to the length of original text
string generateKey(string str, string key)
{
    int x = str.size();

    for (int i = 0;; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

// This function returns the encrypted text generated with the help of the key
string cipherText(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        char x = (str[i] + key[i]) % 26;

        // convert into alphabets(ASCII)
        x += 'A';

        cipher_text.push_back(x);
    }
    return cipher_text;
}

// This function decrypts the encrypted text and returns the original text
string originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        char x = (cipher_text[i] - key[i] + 26) % 26;

        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}
