using System;
using System.IO; // for file handling
// file handling is used to create, delete, read, write, append the data from the file

namespace C_Basic
{
    class FileHandling
    {
        public void WriteFile()
        {
            // to create a file for writing, "StreamWriter" is used
            StreamWriter sw = new StreamWriter("new.txt"); // this will create a file in the project folder
            // you can also specify the absolute path of the file
            // eg: StreamWriter sw = new StreamWriter("C:\\Users\\user\\Desktop\\new.txt");
            Console.WriteLine("Enter the text to insert in the file: ");
            string data = Console.ReadLine();
            // this will take the input from the user until the user press "Enter"

            sw.WriteLine(data);
            sw.Flush(); // clear the buffer and write the data in the file
            sw.Close(); // close the file
        }

        public void ReadFile()
        {
            StreamReader sr = new StreamReader("new.txt");
            string data = sr.ReadLine(); // read single line from the file
            Console.WriteLine("Reading from the file: ");
            Console.WriteLine(data);
            sr.Close();
        }
    }
}
