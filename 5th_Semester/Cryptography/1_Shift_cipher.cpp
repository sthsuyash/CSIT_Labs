#include <iostream>
#include <string>
#include "./returnName.h"
using namespace std;

int getKey();
string encrypt(string, int);
string decrypt(string, int);

int main()
{
    generateHeader("Shift Cipher Program");
    int choice;
    int key;
    string plaintext, ciphertext;
    do
    {
        cout << "Menu:\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1/2/3): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the plaintext: ";
            cin.ignore();
            getline(cin, plaintext);
            cout << "Enter the key (an integer between 0 to 25): ";
            key = getKey();
            ciphertext = encrypt(plaintext, key);
            cout << "Encrypted Text: " << ciphertext << endl
                 << endl;
            break;

        case 2:
            cout << "Enter the ciphertext: ";
            cin.ignore();
            getline(cin, ciphertext);
            cout << "Enter the key (an integer between 0 to 25): ";
            key = getKey();
            plaintext = decrypt(ciphertext, key);
            cout << "Decrypted Text: " << plaintext << endl
                 << endl;
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

// function to get the key from the user and validate it
int getKey()
{
    int key;
    cin >> key;
    if (key < 0 || key > 25)
    {
        cout << "Invalid key. Enter again: ";
        return getKey(); // Recursively call getKey until a valid key is entered.
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
    return encrypt(cipher, 26 - key); // Decrypting is the same as encrypting with the opposite key.
}
