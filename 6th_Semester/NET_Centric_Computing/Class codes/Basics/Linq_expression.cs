/*
 * LINQ(Language Integrated Query) is uniform query syntax in C# and VB.NET to retrieve data from different sources and formats.
 * With LINQ, a query is a first-class language construct, just like classes, methods, events.
 * It is simple, well-ordered and high-level language syntax to retrieve data from different sources and formats.
 */
using System;
using System.Collections.Generic;
using System.Linq;

namespace Basics
{
    class Linq_expression
    {
        public void Linq()
        {
            int[] scores = new int[] { 97, 92, 81, 60 };

            // LINQ Query Syntax
            IEnumerable<int> scoreQuery = from score in scores
                                          where score > 80
                                          select score;

            foreach (int i in scoreQuery)
            {
                Console.Write(i + " ");
            }
        }
    }
}
