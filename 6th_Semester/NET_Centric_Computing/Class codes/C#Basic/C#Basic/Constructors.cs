using System;

// constructor of super class cannot be called directly by sub class
// to use the constructor of super class, we use base keyword

// base keyword is used to access the base class members such as constructors, methods, and fields
// it uses:
// 1. to call the superclass constructor
// 2. to access the overridden methods of the base class(overriding)
namespace C_Basic
{
    class Parent
    {
        private int x;
        private int y;

        public Parent()
        {
            Console.WriteLine("Default constructor of parent class");
        }

        public Parent(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public void add()
        {
            Console.WriteLine($"Sum: {x + y}");
        }
    }

    class Child : Parent
    {
        private int z;

        public Child() : base() // calls default constructor of parent class
        {
            Console.WriteLine("Default constructor of child class");
        }

        public Child(int x, int y, int z) : base(x, y) // calls parameterized constructor of parent class
        {
            this.z = z;
        }

        public void square()
        {
            Console.WriteLine($"Square: {z * z}");
        }
    }
}
