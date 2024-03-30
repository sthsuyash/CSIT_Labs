/*
 * A generic collection enforces type safety so that other data types cannot be added to it.
 * When we retrieve an item from a generic collection, we do not need to cast it to the appropriate data type.
 * Implemented under the System.Collections.Generic namespace.
 * 
 * Classes present in the System.Collections.Generic namespace are:
 * Stack<T>, Queue<T>, List<T>, Dictionary<TKey, TValue>, SortedList<>, LinkedList<T>, SortedSet<T>, etc.
 * 
 * <T> is a placeholder for the data type that will be used with the generic collection.
 */
using System;
using System.Collections.Generic;

namespace Basics
{
    class Generics
    {
        public void GenericList()
        {
            // empty list can be created as:
            //List<int> numbers = new List<int>();
            List<int> numbers = new List<int> { 1, 2 };
            numbers.Add(3);
            numbers.Add(4);
            numbers.Add(5);

            foreach (int number in numbers)
            {
                Console.WriteLine(number);
            }

            Console.WriteLine($"Count: {numbers.Count}");
        }
    }
}
