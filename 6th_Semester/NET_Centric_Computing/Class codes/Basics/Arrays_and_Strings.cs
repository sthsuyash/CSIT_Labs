/*
 * Arrays are used to store multiple values in a single variable, instead of declaring separate variables for each value.
 * 
 * To declare an array, define the variable type with square brackets:
 * <type>[] <arrayName>;
 * Example: int[] arr;
 * 
 * Jagged arrays are arrays of arrays with different dimensions.
 * To declare a jagged array, define the variable type with square brackets:
 * <type>[][] <arrayName>;
 * They are also known as "array of arrays".
 * 
 * Strings are used for storing text.
 * In C#, a string is an object of the String class.
 */
using System;

namespace Basics
{
    class Array
    {
        public void set1DArray()
        {
            int[] arr = new int[5];
            arr[0] = 10;
            arr[1] = 20;
            arr[2] = 30;
            arr[3] = 40;
            arr[4] = 50;
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }
        }

        public void set2DArray()
        {
            int[,] arr = new int[2, 2];
            arr[0, 0] = 10;
            arr[0, 1] = 20;
            arr[1, 0] = 30;
            arr[1, 1] = 40;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    Console.Write(arr[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        public void setJaggedArray()
        {
            int[][] arr = new int[2][];
            arr[0] = new int[] { 10, 20 };
            arr[1] = new int[] { 30, 40, 50 };
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = 0; j < arr[i].Length; j++)
                {
                    Console.Write(arr[i][j] + " ");
                }
                Console.WriteLine();
            }
        }
    }

    class StringExpression
    {
        public void Display()
        {

            string str = "Hello World!";
            Console.WriteLine("String: " + str);
            Console.WriteLine("Length: " + str.Length);
            //Console.WriteLine(str.ToUpper());
            //Console.WriteLine(str.ToLower());
            //Console.WriteLine(str.Contains("World"));
            //Console.WriteLine(str.Contains("world"));
            //Console.WriteLine(str.IndexOf("World"));
            //Console.WriteLine(str.IndexOf("world"));
            //Console.WriteLine(str.Substring(6));
            //Console.WriteLine(str.Substring(6, 5));
            //Console.WriteLine(str.Replace("World", "C#"));
            //Console.WriteLine(str.Replace("world", "C#"));
            //Console.WriteLine(str.Remove(5));
            //Console.WriteLine(str.Remove(5, 6));
            //Console.WriteLine(str.Insert(6, "C# "));
            //Console.WriteLine(str.Insert(6, "c# "));
            //Console.WriteLine(str.Split(' '));
            //Console.WriteLine(str.Split(' ')[0]);
            //Console.WriteLine(str.Split(' ')[1]);
            //Console.WriteLine(str.Split(' ')[0] + " " + str.Split(' ')[1]);
        }
    }
}
