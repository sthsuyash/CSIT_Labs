using System;

/*
 * Create a class Number having instance variable x and y both in integer, 
 * default constructor that set the value of x and y to 0, 
 * parameterized constructor that sets the value of x and y, 
 * method findOdd() that calculates the odd no. occurring between x and y and display the result, 
 * method findEven() that calculates the even no. occurring between x and y and display the result. 
 * Now, create some instance of Number and invoke all the methods. 
 */
namespace Practical1
{
    class Number
    {
        // Instance variables
        private int x;
        private int y;

        // Default constructor setting x and y to 0
        public Number()
        {
            x = 0;
            y = 0;
        }

        // Parameterized constructor setting x and y
        public Number(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        // Method to find and display even numbers between x and y
        public void FindEven()
        {
            Console.Write("Even numbers between " + x + " and " + y + ": ");
            for (int i = x; i <= y; i++)
            {
                if (i % 2 == 0)
                {
                    Console.Write(i + " ");
                }
            }
            Console.WriteLine();
        }

        // Method to find and display odd numbers between x and y
        public void FindOdd()
        {
            Console.Write("Odd numbers between " + x + " and " + y + ": ");
            for (int i = x; i <= y; i++)
            {
                if (i % 2 != 0)
                {
                    Console.Write(i + " ");
                }
            }
            Console.WriteLine();
        }
    }
}
