/*
 * Polymorphism in code extensibility
 * 
 * Polymorphism is the ability of an object to take on many forms. 
 * The most common use of polymorphism in OOP is when a parent class reference is used to refer to a child class object.
 * 
 * There are two types of polymorphism:
 * 1. Compile-time polymorphism: includes "method overloading" and "operator overloading"
 * 2. Run-time polymorphism: includes "method overriding" and "interface implementation"
 */
using System;

namespace Basics
{
    /* 
     * Compile-time polymorphism is implemented using method overloading.
     * The following code demonstrates method overloading
     * It is a feature that allows a class to have more than one method having the same name, if their argument lists are different
     */
    class MethodOverloading
    {
        public void Add(int a, int b)
        {
            Console.WriteLine("Sum of two numbers: " + (a + b));
        }

        public void Add(int a, int b, int c)
        {
            Console.WriteLine("Sum of three numbers: " + (a + b + c));
        }

        public void Add(double a, double b)
        {
            Console.WriteLine("Sum of two double numbers: " + (a + b));
        }
    }

    /* 
     * Dynamic polymorphism is implemented using method overriding.
     * The following code demonstrates method overriding
     * It is a feature that allows a subclass or child class to provide a specific implementation of a method that is already provided by one of its super-classes or parent classes
     * Use the "virtual" keyword in parent class to allow a method to be overridden in a derived class
     * Use the "override" keyword in child class to override a method
     */
    class MethodOverrdingParent
    {
        public virtual void Display()
        {
            Console.WriteLine("This is the base class");
        }
    }

    class MethodOverridingChild : MethodOverrdingParent
    {
        public override void Display()
        {
            Console.WriteLine("This is the derived class");
        }
    }
}

