/*
 * Exception is any kind of error that disturbs the normal flow of the program.
 * if exception occurs, then whole program is stopped.
 * to deal with such error exception handling mechanism is required.
 * it contains 4 keywords
 *
 * 1. try: use to surround a code that can cause error
 * 2. catch: use to handle the error
 * 3. throw: use to throw an exception
 * 4. finally: this block will always execute whether exception occurs or not
*/
using System;

namespace Basics
{
    class ExceptionHandling
    {
        private int x;
        private int y;

        public void SetData()
        {
            Console.WriteLine("Enter first number: ");
            x = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Enter second number: ");
            y = Convert.ToInt32(Console.ReadLine());
        }

        public void Divide()
        {
            try
            {
                int div = this.x / this.y;
                Console.WriteLine("Division: " + div);
            }
            catch (DivideByZeroException d)
            {
                Console.WriteLine($"Cannot divide {this.x} by {this.y}.\n {d}");
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
            finally
            {
                Console.WriteLine("This block will always execute whether exception occurs or not.");
            }
            Console.WriteLine("Out of try/catch block.");
        }
    }
}
