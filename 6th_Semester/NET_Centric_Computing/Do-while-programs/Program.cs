using System;

namespace Do_while_programs
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***** Code that validates integer input *****");
            ValidateIntegerInput validateIntegerInput = new ValidateIntegerInput();
            Console.WriteLine();

            Console.WriteLine("***** Code that validates string input *****");
            ValidateStringInput validateStringInput = new ValidateStringInput();
            Console.WriteLine();

            Console.WriteLine("***** Code that processes strings *****");
            ProcessString processString = new ProcessString();
            Console.WriteLine();

        }
    }
}
