using System;

namespace Do_while_programs
{
    internal class ValidateIntegerInput
    {
        private int number;

        public ValidateIntegerInput()
        {
            do
            {
                Console.Write("Enter an integer between 5 and 10: ");
                string input = Console.ReadLine();

                if (int.TryParse(input, out number))
                {
                    if (number < 5 || number > 10)
                    {
                        Console.WriteLine("You entered {0}. Please enter a number between 5 and 10.", number);
                    }
                    else
                    {
                        Console.WriteLine("Your input value ({0}) has been accepted.", number);
                    }
                }
                else
                {
                    Console.WriteLine("Sorry, you entered an invalid number, please try again.");
                }

            } while (number < 5 || number > 10);

        }
    }
}
