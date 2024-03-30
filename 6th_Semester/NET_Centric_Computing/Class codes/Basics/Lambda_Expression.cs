/*
 * Lambda Expression:
 * Lambda expression is a short way to define a method without any name.
 * It is a way to write anonymous methods. It provides a concise way to represent one method interface using an expression.
 * It is used to create delegates or expression tree types.
 */

using System;

namespace Basics
{
    class Lambda_Expression
    {
        public void Lambda()
        {
            int add(int x, int y) => x + y;
            Console.WriteLine(add(10, 20));
        }
    }
}
