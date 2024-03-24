using System;

namespace Do_while_programs
{
    internal class UserInput
    {
        private string readResult { get; set; }
        
        bool validEntry = false;

        public void ValidateInputString()
        {
            Console.Write("Enter a string: ");
            do
            {
                readResult = Console.ReadLine();
            } while (readResult == null);
        }

        public void AtLeastThreeCharacters()
        {
            do
            {
                readResult = Console.ReadLine();
                if (readResult != null && readResult.Length >= 3)
                {
                    validEntry = true;
                }
                else
                {
                    Console.WriteLine("The string must be at least three characters long.");
                }
            }while (!validEntry);
            
        }
    }
}
