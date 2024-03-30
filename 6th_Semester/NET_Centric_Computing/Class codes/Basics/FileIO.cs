/*
 * File IO has two main streams: input and output streams.
 * The System.IO namespace contains classes that are used for file operations.
 * The input stream is used to read data from a file, and the output stream is used to write data to a file.
 * The output stream is used to write data to a file.
 * 
 * StreamReader and StreamWriter classes are used to read and write data to a file, respectively.
 * File class is used to perform file operations such as creating, deleting, and moving files.
 * FileInfo and DirectoryInfo classes are used to perform operations on files and directories, respectively.
 * FileStream class is used to read and write data to a file in a low-level manner.
 * BinaryReader and BinaryWriter classes are used to read and write binary data to a file, respectively.
 * BufferedStream class is used to improve the performance of file operations by buffering data.
 * MemoryStream class is used to read and write data to an in-memory stream.
 * StringWriter and StringReader classes are used to read and write data to a string, respectively.
 * TextReader and TextWriter classes are used to read and write text data, respectively.
 */
using System;
using System.IO;

namespace Basics
{
    class FileIO
    {
        public void Write()
        {
            // to create a file and write data to it, "StreamWriter" class is used
            StreamWriter writer = new StreamWriter("test.txt");
            // you can also specify the absolute path of the file
            // eg: StreamWriter sw = new StreamWriter("C:\\Users\\user\\Desktop\\new.txt");
            Console.WriteLine("Enter the text to insert in the file: ");
            string data = Console.ReadLine();
            writer.WriteLine(data);
            writer.Flush(); // to clear the buffer because the data is not written to the file until the buffer is full
            writer.Close();
        }

        public void Read()
        {
            StreamReader reader = new StreamReader("test.txt");
            string data = reader.ReadLine();
            Console.WriteLine(data);
            reader.Close();
        }
    }
}
