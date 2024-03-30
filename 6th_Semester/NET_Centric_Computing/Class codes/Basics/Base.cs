/*
 * Use of base keyword in C#
 * In C#, the base keyword is used to access the base class members such as fields, methods, and properties. 
 * It is used to access the base class constructor, base class methods, and base class fields.
 */
using System;

namespace Basics
{
    class ParentClass
    {
        public int x = 10;

        public ParentClass()
        {
            Console.WriteLine("Parent class constructor");
        }
    }

    class ChildClass : ParentClass
    {
        public ChildClass() : base()
        {
            Console.WriteLine("Child class constructor");
        }

        public void Display()
        {
            Console.WriteLine("Value of x is: " + base.x);
        }
    }
}
