/*
 * Indexers are used to access elements of a class or struct like arrays.
 * It is usually known as smart arrays.
 * It is a class property that allows you to access a member variable of a class using the features of an array.
 * In C#, indexers are implemented using the this keyword.
 * 
 * Creating an Indexer:
 * <modifier> <return type> this[args]
 * { get {} set {} }
 */
using System;

namespace Basics
{
    class Indexers
    {
        class IndexerExample
        {
            private string[] names = new string[10];
            public string this[int index]
            {
                get
                {
                    return names[index];
                }
                set
                {
                    names[index] = value;
                }
            }
        }

        public void Display()
        {
            IndexerExample names = new IndexerExample();
            names[0] = "John";
            names[1] = "Doe";
            names[2] = "Jane";
            names[3] = "Smith";
            names[4] = "Alice";

            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine(names[i]);
            }
        }
    }
}
