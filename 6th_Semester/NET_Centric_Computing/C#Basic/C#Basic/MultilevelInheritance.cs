using System;

namespace C_Basic
{
    class TwoWheeler
    {
        private int reg;
        private string name;
        string model;

        // properties
        public int Reg
        {
            get { return reg; }
            set { reg = value; }
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public string Model
        {
            get { return model; }
            set { model = value; }
        }
    }

    // class that inherits TwoWheeler
    class Bike : TwoWheeler
    {
        private string color;
        private double speed;

        public string Color
        {
            get { return color; }
            set { color = value; }
        }

        public double Speed
        {
            get { return speed; }
            set { speed = value; }
        }
    }

    // class that inherits Bike
    class ElectricBike : Bike
    {
        public double range;

        public double Range
        {
            get { return range; }
            set { range = value; }
        }

        public void getElectricBike()
        {
            Console.WriteLine($"Registration: {this.Reg}");
            Console.WriteLine($"Name: {this.Name}");
            Console.WriteLine($"Model: {this.Model}");
            Console.WriteLine($"Color: {this.Color}");
            Console.WriteLine($"Speed: {this.Speed}");
            Console.WriteLine($"Range: {this.Range}");
        }
    }
}
