/*
 * Structs and Enums are value types in C#.
 * 
 * Structs: Structs are value types that are typically used to encapsulate small groups of related variables.
 * Enums: Enums are value types that are typically used to define a set of named constants.
 */
using System;

namespace Basics
{
    class Structs
    {
        public struct Point
        {
            public int x;
            public int y;

            public Point(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
        }

        public void Display()
        {
            Point p1 = new Point(10, 15);
            Console.WriteLine($"p1.x = {p1.x}, p1.y = {p1.y}");
        }
    }

    class Enums
    {
        public enum Days
        {
            Sunday,
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday
        }

        public void Display()
        {
            Days today = Days.Monday;
            Console.WriteLine(today);
        }
    }
}
