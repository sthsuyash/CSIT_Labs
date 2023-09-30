#include <iostream>
#include <cstdlib>
#include <ctime> // For seeding the random number generator
using namespace std;

// Function to generate a random number between 1 and 6
int rollDice()
{
    return (rand() % 6) + 1;
}

int main()
{
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "\n***** Welcome to the Game of Dice!! *****\n";
    int player1, player2, ch, p1, p2;

    do
    {
        cout << "\n**Options**";
        cout << "\nPress 1 to Continue\nPress 2 to Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nPlayer 1:\nEnter 1 to roll the dice: ";
            cin >> p1;
            if (p1 == 1)
            {
                player1 = rollDice();
                cout << "Player 1 score: " << player1 << "\n";
            }

            cout << "\nPlayer 2:\nEnter 1 to roll the dice: ";
            cin >> p2;
            if (p2 == 1)
            {
                player2 = rollDice();
                cout << "Player 2 score: " << player2 << "\n";
            }

            // Determine the winner
            cout << "\nResult:\n";
            if (player1 > player2)
            {
                cout << "Congratulations!! Winner: Player 1\n";
            }
            else if (player2 > player1)
            {
                cout << "Congratulations!! Winner: Player 2\n";
            }
            else
            {
                cout << "It's a tie!\nPlay one more round\n\n";
            }
            continue;
        case 2:
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            main();
            break;
        }
    } while (ch != 2);

    cout << "\nThanks for playing!! Visit again :)\n\n";
    return 0;
}
