/*
 * Collections in C# are used to store a collection of objects or data.
 * It is a more flexible way to store data than arrays.
 * Unlike arrays, collections can grow and shrink dynamically as the needs of the application change.
 * For some collections, we can assign a key to any object that we put into the collection, so that we can retrieve the object by using the key.
 * 
 * A collection is a class, so we need to create an object of the collection class to use it.
 */
using System;
using System.Collections;

namespace Basics
{
    class Collections
    {
        public void List()
        {
            ArrayList list = new ArrayList();
            list.Add(1);
            list.Add("Person");
            list.Add(10.5);

            foreach (var item in list)
            {
                Console.WriteLine(item);
            }

            Console.WriteLine($"Count: {list.Count}");
        }
    }
}
