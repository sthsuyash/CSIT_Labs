using System;
using System.Collections.Generic;
using System.Linq;

namespace Basics
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("**** Constructors ****");
            /* default constructor */
            Constructor cons2 = new Constructor();
            cons2.Display();
            Console.WriteLine();
            /* parameterized constructor */
            Constructor cons1 = new Constructor("Hello World");
            cons1.Display();
            Console.WriteLine("\n\n----------------------------\n\n");

            Console.WriteLine("**** Example of set, get properties ****");
            PropertiesExpression props = new PropertiesExpression();
            props.Example();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Strings ****");
            StringExpression strExp = new StringExpression();
            strExp.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Array ****");
            Array array = new Array();
            array.set1DArray();
            array.set2DArray();
            array.setJaggedArray();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Indexers ****");
            Indexers indexers = new Indexers();
            indexers.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Inheritance ****");
            Console.WriteLine();
            Console.WriteLine("**** Single level inheritance ****");
            Teacher teacher = new Teacher();
            teacher.SetTeacher("C#", "Masters", 2, "Hari", "Kathmandu", "IT");
            teacher.GetTeacher();
            Console.WriteLine();

            // create 5 objects of Employee class using list
            List<Employee> employees = new List<Employee>()
            {
                new Employee() { id = 1, name = "Suyash", address = "Kathmandu", department = "CSIT" },
                new Employee() { id = 2, name = "Sandesh", address= "Bhaktapur", department = "CSIT" },
                new Employee() { id = 3, name = "Shreyan", address = "Butwal", department = "CSIT" },
                new Employee() { id = 4, name = "Prashanna", address = "Pokhara", department = "CSIT" },
                new Employee() { id = 5, name = "Amish", address = "Kathmandu", department = "CSIT" }
            };

            foreach (var employee in employees)
            {
                Console.WriteLine($"Id: {employee.id}");
                Console.WriteLine($"Name: {employee.name}");
                Console.WriteLine($"Address: {employee.address}");
                Console.WriteLine($"Department: {employee.department}");
            }

            // using lambda to sort object and display
            var employeesSorted = employees.OrderBy(employee => employee.name);
            foreach (var employee in employeesSorted)
            {
                Console.WriteLine($"Id: {employee.id}");
                Console.WriteLine($"Name: {employee.name}");
                Console.WriteLine($"Address: {employee.address}");
                Console.WriteLine($"Department: {employee.department}");
            }

            var findEmployee = employees.FindAll(employee => employee.id == 1);
            foreach (var employee in findEmployee)
            {
                Console.WriteLine($"Id: {employee.id}");
                Console.WriteLine($"Name: {employee.name}");
                Console.WriteLine($"Address: {employee.address}");
                Console.WriteLine($"Department: {employee.department}");
            }
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Multilevel inheritance ****");
            PartTimeTeacher hari = new PartTimeTeacher();
            hari.SetPartTimeTeacher(20, "C#", "Masters", 2, "Hari", "Kathmandu", "IT");
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Base keyword ****");
            ChildClass childClass = new ChildClass();
            childClass.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Method Hiding ****");
            MethodHidingChild methodHiding = new MethodHidingChild();
            methodHiding.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Structs ****");
            Structs str = new Structs();
            str.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Enums ****");
            Enums en = new Enums();
            en.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Abstract class ****");
            InheritAbstract inheritAbstract = new InheritAbstract();
            inheritAbstract.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Sealed class ****");
            SealedExpression sealedExpression = new SealedExpression();
            sealedExpression.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Interface ****");
            InterfaceExpression inter = new InterfaceExpression();
            inter.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Partial class ****");
            Partial_class partialClass = new Partial_class(1, 2);
            partialClass.PrintItems();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Delegates and Events ****");
            Delegates_and_Events delegates = new Delegates_and_Events();
            delegates.DelegateMethod();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Collections ****");
            Collections collections = new Collections();
            collections.List();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Generics ****");
            Generics generics = new Generics();
            generics.GenericList();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** File handling ****");
            FileIO fileIO = new FileIO();
            Console.WriteLine("Do you want to read or write the file? (r/w): ");
            if (Console.ReadLine() == "w")
                fileIO.Write();
            else
                fileIO.Read();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** PolyMorphism in code extensibility ****");
            /* Static polymorphism */
            Console.WriteLine("**** Method Overloading ****");
            MethodOverloading methodOverriding = new MethodOverloading();
            methodOverriding.Add(10, 20);
            methodOverriding.Add(10, 20, 30);
            methodOverriding.Add(10.5, 20.5);
            Console.WriteLine();

            /* Dynamic polymorphism */
            Console.WriteLine("**** Method Overriding ****");
            MethodOverrdingParent methodOverrdingParent = new MethodOverridingChild();
            methodOverrdingParent.Display();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** LINQ ****");
            Linq_expression linq = new Linq_expression();
            linq.Linq();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Lambda expression ****");
            Lambda_Expression lambdaExpression = new Lambda_Expression();
            lambdaExpression.Lambda();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Exception Handling ****");
            ExceptionHandling exceptionHandling = new ExceptionHandling();
            exceptionHandling.SetData();
            exceptionHandling.Divide();
            Console.WriteLine("\n----------------------------\n\n");

            Console.WriteLine("**** Asynchronous programming ****");
            Asynchronous_Programming async = new Asynchronous_Programming();
            async.CallProcess();
            Console.WriteLine("\n----------------------------\n\n");
            Console.WriteLine("hello there");

            Console.ReadKey(); // to hold the console screen
        }
    }
}
