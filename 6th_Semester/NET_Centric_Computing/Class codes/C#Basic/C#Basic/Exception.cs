using System;

// exception is any kind of error that disturbs the normal flow of the program.
// if exception occurs, then whole program is stopped.
// to deal with such error exception handling mechanism is required.
// it contains 4 keywords

 // 1. try: use to surround a code that can cause error
 // 2. catch: use to handle the error
 // 3. throw: use to throw an exception
 // 4. finally: this block will always execute whether exception occurs or not
          
namespace C_Basic
{
    class ExceptionDemo
    {
        private int x;
        private int y;

        public void setData()
        {
            Console.WriteLine("Enter first number: ");
            this.x = Int32.Parse(Console.ReadLine());

            Console.WriteLine("Enter second number: ");
            this.y = Int32.Parse(Console.ReadLine());
        }

        public void divide()
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
