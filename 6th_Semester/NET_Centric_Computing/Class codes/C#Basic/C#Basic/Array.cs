using System;

namespace C_Basic
{
    class Array
    {
        public void set1DArray()
        {
            // one dimensional array
            // direct method
            int[] arr1 = { 1, 2, 3, 4, 5 };

            // foreach is used to iterate through the array
            foreach (int data in arr1)
            {
                Console.Write(data + " ");
            }

            // or we can also use for loop and get the data from the array using index, eg: arr1[0], arr1[1], ...
            Console.WriteLine();
            for (int i = 0; i < arr1.Length; i++)
            {
                Console.Write(arr1[i] + " ");
            }
            Console.WriteLine();
        }

        public void set2DArray()
        {
            int[,] arr2 =
            {
                {1,2,3},
                {4,5,6}
            };

            foreach(int data2 in arr2)
            {
                Console.Write(data2 + " ");
            }

            // in matrix format
            Console.WriteLine();
            for (int i = 0; i < arr2.GetLength(0); i++)
            {
                for (int j = 0; j < arr2.GetLength(1); j++)
                {
                    Console.Write(arr2[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        // jagged array
        public void setJaggedArray()
        {
            int[][] arr3 = new int[3][];
            arr3[0] = new int[] { 1, 2, 3 };
            arr3[1] = new int[] { 4, 5, 6, 7 };
            arr3[2] = new int[] { 8, 9 };

            foreach (int[] data3 in arr3)
            {
                foreach (int data in data3)
                {
                    Console.Write(data + " ");
                }
                Console.WriteLine();
            }
        }



    }
}
