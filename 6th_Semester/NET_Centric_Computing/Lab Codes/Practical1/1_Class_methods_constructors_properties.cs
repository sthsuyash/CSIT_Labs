using System;

// Class: It is a blueprint for creating objects.
// Properties: It is a member of a class that provides a flexible mechanism to read, write or compute the value of a private field.
// Methods: It is a code block containing a series of statements.
// Constructor: It is a special method that is called when an object is created.

namespace Practical1
{
    class Person
    {
        private String name;
        private int age;

        // properties
        public String Name
        {
            get { return name; }
            set { name = value; }
        }

        public int Age
        {
            get { return age; }
            set { age = value; }
        }
        // constructor
        public Person(String name, int age)
        {
            this.name = name;
            this.age = age;
        }

        // method
        public void Greetings()
        {
            Console.WriteLine("Hello, my name is " + name + " and I am " + age + " years old.");
        }
    }
}
