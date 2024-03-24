using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Do_while_programs
{
    internal class ValidateStringInput
    {
        private string role;
        public ValidateStringInput()
        {
            do
            {
                Console.Write("Enter your role (User, Manager, Administrator): ");
                role = Console.ReadLine().Trim().ToLower();
                if (role != "user" && role != "manager" && role != "administrator")
                {
                    Console.WriteLine($"Sorry, you entered an invalid role ({role}), please try again.");
                }
                else
                {
                    Console.WriteLine($"Your role ({role}) has been accepted.");
                    break;
                }
            }while(true);
        }
    }
}
