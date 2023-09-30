#include <iostream>
#include <string>
using namespace std;

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

string decrypt(string cipher, int key)
{
    return encrypt(cipher, 26 - key);
}

int main()
{
    int key;
    string plaintext, ciphertext;

    cout << "Shift Cipher Program" << endl;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key (an integer): ";
    cin >> key;

    ciphertext = encrypt(plaintext, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    plaintext = decrypt(ciphertext, key);
    cout << "Decrypted Text: " << plaintext << endl;

    return 0;
}
