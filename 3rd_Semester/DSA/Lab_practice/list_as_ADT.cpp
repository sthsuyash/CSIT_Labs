#include <iostream>
using namespace std;

const int MAX_SIZE = 20;
int arr[MAX_SIZE];
int size = 0;

void displayMenu()
{
    cout << "Menu: \n";
    cout << "1. Insert element at beginning.\n";
    cout << "2. Insert element at end.\n";
    cout << "3. Insert element at specific position.\n";
    cout << "4. Delete element.\n";
    cout << "5. Display list.\n";
    cout << "6. Exit.\n";
}

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

    do
    {
        displayMenu();
        cout << "Enter choice: ";
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
            // Insertion in the end
            cout << "Enter the number to be inserted: ";
            cin >> num;
            arr[size] = num;
            size++;
            break;

        case 3:
            // Insertion in the specific position
            cout << "Enter the number to be inserted: ";
            cin >> num;
            cout << "Enter the position: ";
            cin >> pos;
            for (int i = size; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[pos] = num;
            size++;
            break;

        case 4:
            int element;
            cout << "Enter element to delete: ";
            cin >> element;

            bool found;
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == element)
                {
                    for (int j = i; j < size - 1; j++)
                    {
                        arr[j] = arr[j + 1];
                    }
                    size--;
                    found = true;
                    cout << "Element deleted successfully.\n";
                    break;
                }
            }
            if (found == false)
            {
                cout << "Error: Element not found\n";
            }
            break;

        case 5:
            if (size == 0)
            {
                cout << "List is empty" << endl;
                break;
            }
            cout << "List: ";

            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;

        case 6:
            goto end;
        default:
            cout << "Invalid choice" << endl;
            main();
            break;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
end:
    cout << "\nEnd of program.\n";
    return 0;
}
