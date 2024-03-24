using System;

/*
 * * Program to demonstrate Single-level and Multi-level inheritance in C#
 */
namespace Practical1
{
    // Base class
    class Animal
    {
        public void Eat()
        {
            Console.WriteLine("Animal is eating...");
        }
    }

    // Single-level inheritance
    class Dog : Animal
    {
        public void Bark()
        {
            Console.WriteLine("Dog is barking...");
        }
    }

    // Multi-level inheritance
    class Chiuaua : Dog
    {
        public void SmallBark()
        {
            Console.WriteLine("Chiuaua is barking...");
        }
    }
}
