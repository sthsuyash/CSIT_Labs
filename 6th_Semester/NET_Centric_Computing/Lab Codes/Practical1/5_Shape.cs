using System;

/*
 * Create a class Shape that contains instance variable length, breadth and height. 
 * Create a default constructor that sets the value of instance variable to zero, 
 * constructor with two parameter that will sets the value of length and breadth only and 
 * constructor with three parameter that will sets the value of length, breadth and height. 
 * After this create calcAreaRectangle() that calculates the area of rectangle, 
 * calcVolumeBox() that calculates volume of box and display the result. 
 * 
 * 1. Create first object of Shape wihich will have name rectangle and calls constructor with two parameter and calAreaRectangle() method
 * 2. Create second object of Shape that will have name Box which will call constructor with three parameter and calcVolumeBox() method.
 */

namespace Practical1
{
    class Shape
    {
        // Instance variables
        private double length;
        private double breadth;
        private double height;

        // Default constructor setting length, breadth, and height to 0
        public Shape()
        {
            length = 0;
            breadth = 0;
            height = 0;
        }

        // Constructor with two parameters for length and breadth
        public Shape(double length, double breadth)
        {
            this.length = length;
            this.breadth = breadth;
            height = 0; // Setting height to 0
        }

        // Constructor with three parameters for length, breadth, and height
        public Shape(double length, double breadth, double height)
        {
            this.length = length;
            this.breadth = breadth;
            this.height = height;
        }

        // Method to calculate and display the area of a rectangle
        public void CalcAreaRectangle()
        {
            double area = length * breadth;
            Console.WriteLine("Area of rectangle: " + area);
        }

        // Method to calculate and display the volume of a box
        public void CalcVolumeBox()
        {
            double volume = length * breadth * height;
            Console.WriteLine("Volume of box: " + volume);
        }
    }
}
