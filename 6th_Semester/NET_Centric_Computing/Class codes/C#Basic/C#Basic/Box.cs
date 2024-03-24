using System; // basic input output commmand

namespace C_Basic
{
    class Box
    {
        // instance variable
        private int length;
        private int breadth;
        private int height;

        // constructor-> initialize the instance variable
        // default constructor: w/o parameter: public
        public Box()
        {
            length = 0;
            breadth = 0;
            height = 0;
        }

        // parameterized constructor: parameter value provided
        public Box(int lenth, int breadth, int height)
        {
            this.length = lenth;
            this.breadth = breadth;
            this.height = height;
        }

        // method: used to provide some services 
        // method: without returning value
        public void area()
        {
            int area = this.length * this.breadth;
            Console.WriteLine($"Area of the box is {area}");
        }

        public void volume()
        {
            int volume = this.length * this.breadth * this.height;
            Console.WriteLine($"Volume of the box is {volume}");
        }


    }
}
