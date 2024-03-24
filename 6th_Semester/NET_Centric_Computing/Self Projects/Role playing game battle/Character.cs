using System;

namespace Role_playing_game_battle
{
    internal class Character
    {
        private string name { get; set; }
        private int health { get; set; }

        public Character(int health)
        {
            this.health = health;
        }

        public int getHealth()
        {
            return this.health;
        }

        public void setHealth(int health)
        {
            this.health = health;
        }

    }
}
