using System;
using System.Collections.Generic;
using System.Linq;

// list stores collection of similar data.
// It uses generics so it can accept any type including object
// To use list, <>symbol have to be used which indicate which type does list support
namespace C_Basic
{
    class ListDemo
    {
        public void setList()
        {
            List<int> intList = new List<int> { 1, 2, 3, 4, 5 };
            // using predetermined method
            List<string> stringList = new List<string>();
            stringList.Add("Ram");
            stringList.Add("Hari");
            stringList.Add("Sam");

            // foreach loop to display element
            foreach (var integers in intList)
            {
                Console.WriteLine(integers);
            }

            // checking whether given character are present or not
            bool containHari = stringList.Contains("Hari");
            Console.WriteLine(containHari);

            // lambda expression
            List<int> intListLambda = intList.FindAll(x => (x % 2) == 0);
            stringList.FindAll(name => name == "Sam");

            foreach (int integers in intListLambda)
            {
                Console.WriteLine(integers);
            }

            // find cube of each int using lamda expression
            var cubeIntList = intList.Select(x => (x * x * x));

            Console.WriteLine("Cube of int list:");
            foreach (int cubes in cubeIntList)
            {
                Console.Write(cubes + " ");
            }
        }
    }

    // list and lambda expression
    class Teachers
    {
        private int id;
        private string name;
        private string department;

        public int Id
        {
            get { return Id; }
            set { id = value; }
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string Department
        {
            get { return department; }
            set { department = value; }
        }


    }
}
