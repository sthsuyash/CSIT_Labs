/*
 * Properties in C# are members of a class that provide a flexible mechanism to read, write, or compute the values of private fields.
 * It is a way to expose private fields of a class and to control the access to them.
 */
using System;

namespace Basics
{
    class PropertiesExpression
    {
        class Props
        {
            private int id;
            private string name;

            public int Id
            {
                get { return id; }
                set { id = value; }
            }

            public string Name
            {
                get { return name; }
                set { name = value; }
            }
        }

        public void Example()
        {
            Props p = new Props();
            // Setting the values
            p.Id = 1;
            p.Name = "John";

            // Displaying the values
            Console.WriteLine("Id: {0}, Name: {1}", p.Id, p.Name);
        }
    }
}
