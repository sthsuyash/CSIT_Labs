/*
 * Interface is not a class, it is a structure that defines the contract in the form of methods, properties, events, or indexers.
 * It is defined by using the interface keyword.
 * By convention, interface names are prefixed with the letter I, such as IShape, IData, etc.
 * It is just a declaration and does not provide any implementation.
 * A class or struct can implement one or more interfaces.
 * Interfaces are used to implement multiple inheritance in C#.
 */
using System;

namespace Basics
{
    class InterfaceExpression
    {
        private interface IShape
        {
            void Draw();
        }

        private class Circle : IShape
        {
            public void Draw()
            {
                Console.WriteLine("Drawing Circle");
            }
        }

        public void Display()
        {
            Circle circle = new Circle();
            circle.Draw();
        }
    }
}
