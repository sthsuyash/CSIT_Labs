using System;

namespace C_Basic
{
    // method overloading refers to two or more method
    // having same name but different parameters
    // method overloading: for polymorphism // static polymorphism
    // no of params or data type of params
    class Calculations
    {
        public void calc()
        {
            Console.WriteLine("This is default method");
        }

        public void calc(int a)
        {
            Console.WriteLine("This is method with one parameter");
        }

        // if number of parameters are also same then their data types should be different
        public void calc(string a)
        {
            Console.WriteLine("The value is: " + a);
        }

        public int calc(int a, int b)
        {
            return a * b;
        }
    }

}
