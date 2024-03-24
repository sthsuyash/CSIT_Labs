using System;

namespace Role_playing_game_battle
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to the Role playing game battle: ");

            Character monster = new Character(10);
            Character player = new Character(10);

            Random random = new Random();

            do
            {
                int roll = random.Next(1, 11);
                monster.setHealth(monster.getHealth() - roll);
                switch (roll)
                {
                    case 0:
                        Console.WriteLine($"You missed! Monster was not affected and has health {monster.getHealth()}");
                        break;
                    default:
                        Console.WriteLine($"You hit the monster! Monster lost {roll} XP and has health {monster.getHealth()}");
                        break;
                }

                if (monster.getHealth() <= 0) continue;

                roll = random.Next(1, 11);
                player.setHealth(player.getHealth() - roll);
                switch (roll)
                {
                    case 0:
                        Console.WriteLine($"Monster missed! You were not affected and have health {player.getHealth()}");
                        break;
                    default:
                        Console.WriteLine($"Monster hit you! You lost {roll} XP and have health {player.getHealth()}");
                        break;
                }

            } while (monster.getHealth() > 0 && player.getHealth() > 0);

            // now the final result
            Console.WriteLine(monster.getHealth() <= 0 ? "Player won!" : "Player lost!");

        }
    }
}