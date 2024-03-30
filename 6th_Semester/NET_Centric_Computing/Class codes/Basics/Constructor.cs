/*
 * Constructor is a special method that is called when an object is created.
 * It is used to initialize the object, to assign values to the object's fields or properties.
 * The constructor has the same name as the class and does not have a return type.
 * They can be overloaded and a class can have multiple constructors.
 * There are two types of constructors:
 * Parameterized Constructor: Constructor with parameters.
 * Default Constructor: Constructor without parameters.
 */
using System;

namespace Basics
{
    class Constructor
    {
        private string message;

        // Default Constructor
        public Constructor()
        {
            // set message to default value
            this.message = "Default Message";
            Console.WriteLine("Default Constructor");
        }

        // Parameterized Constructor
        public Constructor(string message)
        {
            this.message = message;
        }

        // display method
        public void Display()
        {
            Console.WriteLine("Message: " + message);
        }
    }
}
