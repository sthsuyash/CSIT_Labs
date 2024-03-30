/*
 * Method hiding is a concept in C# where a base class method is hidden by a derived class method.
 * It uses the "new" keyword to hide the base class method.
 * The parent class method is hidden in the derived class.
 */
using System;

namespace Basics
{
    class MethodHidingParent
    {
        public void Display()
        {
            Console.WriteLine("Parent Display");
        }
    }

    class MethodHidingChild : MethodHidingParent
    {
        public new void Display()
        {
            Console.WriteLine("Child Display");
        }
    }
}
