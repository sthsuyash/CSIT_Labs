using System;

namespace Practical1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Question 1
            Console.WriteLine("1. Class, Constructor, Properties and Methods");
            Person person = new Person("John", 25);
            person.Greetings();
            Console.WriteLine("----------------------------------\n");

            // Question 2
            Console.WriteLine("2. Method Overloading");
            Calculator calculator = new Calculator();
            Console.WriteLine(calculator.Add(5, 10));
            Console.WriteLine(calculator.Add(5, 10, 15));
            Console.WriteLine(calculator.Add(5.5, 10.5));
            Console.WriteLine("----------------------------------\n");

            // Question 3
            Console.WriteLine("3. Different arithmetic operations using class");
            Calculate calculate = new Calculate();
            calculate.setCalc(10, 5);
            calculate.calcSum();
            Console.WriteLine("Multiplication of 10 and 5 is " + calculate.calcMulti());
            calculate.calcDifference();
            Console.WriteLine("----------------------------------\n");

            // Question 4
            Console.WriteLine("4. Even and Odd number");
            Number number = new Number(10, 20);
            number.FindEven();
            number.FindOdd();
            Console.WriteLine("----------------------------------\n");

            // Question 5
            Console.WriteLine("5. Area of Rectangle and Volume of Box");
            Shape rectangle = new Shape(10, 20);
            rectangle.CalcAreaRectangle();
            Shape box = new Shape(10, 20, 30);
            box.CalcVolumeBox();
            Console.WriteLine("----------------------------------\n");

            // Question 6
            Console.WriteLine("6. Salary Information");
            SalaryInfo employee = new SalaryInfo(101, "Ramesh Tiwari", 'M', "Kathmandu", "Senior Engineer", 50000);
            employee.DisplayDetails();
            employee.CalcTax();
            Console.WriteLine("----------------------------------\n");

            // Question 7
            Console.WriteLine("7. Inheritance");
            Dog dog = new Dog();
            dog.Eat();
            dog.Bark();

            Chiuaua chiuaua = new Chiuaua();
            chiuaua.Bark();
            chiuaua.SmallBark();
            Console.WriteLine("----------------------------------\n");

            // Question 8
            Console.WriteLine("8. Use of base keyword");
            Base baseObj = new Base(10);
            Derived derivedObj = new Derived(20);
            Console.WriteLine("----------------------------------\n");

            // Question 9
            Console.WriteLine("9. Method Overriding");
            Parent parent = new Child();
            parent.Display();
            Console.WriteLine("----------------------------------\n");

            // Question 10
            Console.WriteLine("10. Multiple Inheritance using Interface");
            Circle circle = new Circle();
            circle.Draw();
            circle.FillColor();
            Console.WriteLine("----------------------------------\n");

            // Question 11
            Console.WriteLine("11. Abstract Class");
            NewShape shape = new NewCircle();
            shape.Draw();
            Console.WriteLine("----------------------------------\n");

            // Question 12
            Console.WriteLine("12. Exception Handling");
            ExceptionHandling eh = new ExceptionHandling();
            eh.Divide();
            Console.WriteLine("----------------------------------\n");

            // Question 13
            Console.WriteLine("13. Interface");
            Ram ram = new Ram();
            ram.Greetings();
            Console.WriteLine("----------------------------------\n");

            // Question 14
            Console.WriteLine("14. Lambda Expression");
            LambdaExpression lambda = new LambdaExpression();
            lambda.Lambda();
            Console.WriteLine("----------------------------------\n");





            Console.ReadKey();
        }
    }
}
