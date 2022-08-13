/*
   Write a menu driven program to:
   Press:
   1 for insertion at beginning
   2 for at specific position
   3 for end
   4 for display
*/

#include <iostream>
using namespace std;

int main()
{
    int choice, size, num, pos;
    char ch;

    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size]; // declaring array

    // entering data for array
    cout << "Enter the contents of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // repeat until the user enters 'n'
    do
    {
        cout << endl
             << "Press for:" << endl
             << "1) Insertion in the begining." << endl
             << "2) Insertion in the specific position." << endl
             << "3) Insertion in the end." << endl
             << "4) Displaying the array." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Insertion in the begining
            cout << "Enter the number to be inserted: ";
            cin >> num;
            for (int i = size; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = num;
            size++;
            break;
        case 2:
            // Insertion in the specific position
            cout << "Enter the number to be inserted: ";
            cin >> num;
            cout << "Enter the position: ";
            cin >> pos;
            pos--;
            for (int i = size; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = num;
            size++;
            break;
        case 3:
            // Insertion in the end
            cout << "Enter the number to be inserted: ";
            cin >> num;
            arr[size] = num;
            size++;
            break;

        case 4:
            cout << "Displaying array: " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
        ch = tolower(ch);
    } while (ch == 'y');
    cout << "\nEnd of program.\n";
    return 0;
}
