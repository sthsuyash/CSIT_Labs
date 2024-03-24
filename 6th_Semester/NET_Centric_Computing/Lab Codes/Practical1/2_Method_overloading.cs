// method overloading is a feature that allows a class to have more than one method having the same name
// if their argument lists are different.

namespace Practical1
{
    class Calculator
    {
        // method to add two integers
        public int Add(int a, int b)
        {
            return a + b;
        }

        // method to add three integers
        public int Add(int a, int b, int c)
        {
            return a + b + c;
        }

        // method to add two doubles
        public double Add(double a, double b)
        {
            return a + b;
        }
    }
}
