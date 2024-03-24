using System;

/*
 * Program to demonstrate the use of Interface
 */

namespace Practical1
{
    interface IPerson
    {
        void Greetings();
    }

    class Ram : IPerson
    {
        public void Greetings()
        {
            Console.WriteLine("Hello, I am Ram.");
        }
    }
}
