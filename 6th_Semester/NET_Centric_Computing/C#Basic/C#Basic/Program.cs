using System;

namespace C_Basic
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("**** Example of constructors ****");
            // create object of the box class
            // parameterized constructor
            Box box1 = new Box(3, 5, 6);
            box1.area();
            box1.volume();

            // default constructor
            Box box2 = new Box();

            Console.WriteLine("\n\n----------------------------\n\n");

            Console.WriteLine("**** Example of set, get properties ****");
            Rectangle rectangle1 = new Rectangle();

            // calling set of length and breadth
            rectangle1.Length = 20;
            rectangle1.Breadth = 35;

            Console.WriteLine($"Length of rectangle: {rectangle1.Length}");
            Console.WriteLine("Breadth of rectangle: " + rectangle1.Breadth);
            Console.WriteLine("Area of rectangle: " + rectangle1.Length * rectangle1.Breadth);

            Console.WriteLine("\n\n----------------------------\n\n");

            Console.WriteLine("**** Example of method overloading ****");
            Calculations calculation = new Calculations();
            calculation.calc();
            calculation.calc(10);
            calculation.calc("Hello");
            int result = calculation.calc(10, 20);
            Console.WriteLine(result);

            Console.WriteLine("\n\n----------------------------\n\n");

            Console.WriteLine("**** Example of single level inheritance ****");
            Employee employee = new Employee();
            employee.setEmployee(1, "Ramesh", "Kathmandu", "IT");
            employee.getEmployee();

            Console.WriteLine("\n\n----------------------------\n\n");
            Teacher teacher = new Teacher();
            teacher.setTeacher("C#", "Masters", 2, "Hari", "Kathmandu", "IT");
            teacher.getTeacher();


            FullTimeTeacher fullTimeTeacher = new FullTimeTeacher();
            fullTimeTeacher.setTeacher("C#", "Masters", 3, "Hari", "Kathmandu", "IT");
            fullTimeTeacher.setFullTimeTeacher(20000);

            Console.WriteLine("\n\n----------------------------\n\n");

            Console.WriteLine("**** Example of multilevel inheritance ****");
            ElectricBike electricBike = new ElectricBike();
            // using grandparent -> TwoWheeler
            electricBike.Reg = 1234;
            electricBike.Name = "Yamaha";
            electricBike.Model = "Yamaha 125";

            // using parent -> Bike
            electricBike.Color = "Black";
            electricBike.Speed = 60;

            // using self -> ElectricBike
            electricBike.Range = 100;

            electricBike.getElectricBike();


            Console.WriteLine("\n\n----------------------------\n\n");

            // make object of the Bike
            Bike bike = new Bike();
            bike.Reg = 1234;
            bike.Name = "Yamaha";
            bike.Model = "Yamaha 125";
            bike.Color = "Black";
            bike.Speed = 60;

            // bike.Range // not accessible

            Console.WriteLine($"Registration: {bike.Reg}");
            Console.WriteLine($"Name: {bike.Name}");
            Console.WriteLine($"Model: {bike.Model}");
            Console.WriteLine($"Color: {bike.Color}");
            Console.WriteLine($"Speed: {bike.Speed}");



            Console.WriteLine("\n\n----------------------------\n\n");


            Console.WriteLine("**** Example of base keyword ****");
            Child child1 = new Child();
            Child child = new Child(2, 3, 4);
            child.add();
            child.square();
            Console.WriteLine("\n\n----------------------------\n\n");

            // Console.ReadKey(); // to hold the console screen

        }
    }
}