// Game of dice using Linear Mix Congruential Random Number Generation
#include <stdio.h>
#include <stdlib.h>

int seed_value = 2;
int rollDice()
{
    return (random_num() % 6) + 1;
    // Returns a random number between 1 and 6
}

int random_num()
{
    int a = 9, c = 3, m = 31;
    // Linear mix congruential formula
    int next_value = (a * seed_value + c) % m;
    seed_value = next_value;

    return seed_value;
}

int main()
{
    printf("\n ***** Welcome to the Game of Dice!! *****\n");
    int player1, player2, ch, p1, p2;

    do
    {
        printf("\n **Options**");
        printf("\n Press 1 for Continue: \n Press 2 for Exit: ");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Player 1: Enter 1 to roll the dice: ");
            scanf("%d", &p1);
            if (p1 == 1)
            {
                player1 = rollDice();
                printf("\n Player 1 score: %d\n", player1);
            }

            printf("\n Player 2: Enter 1 to roll the dice: ");
            scanf("%d", &p2);
            if (p2 == 1)
            {
                player2 = rollDice();
                printf("\n Player 2 score: %d\n", player2);
            }

            // Determine the winner
            printf("\n Result: \n");
            if (player1 > player2)
            {
                printf("\n Congratulations !! \n Winner: Player 1\n");
            }
            else if (player2 > player1)
            {
                printf("\n Congratulations !! \n Winner: Player 2\n");
            }
            else
            {
                printf("\n It's a tie !! \n Play one more round \n\n");
            }
            continue;
        case 2:

            break;
        }
    } while (ch != 2);

    printf("\n Thanks for playing !! \n Visit again :)\n\n");
    return 0;
}