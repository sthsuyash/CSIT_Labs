using System;

namespace C_Basic
{
    class Rectangle
    {
        /* 
         * Properties is used to initialize instance variable and return value of instance variable
         * Same as getter and setter
         -> set is used to initialize instance variable and 
         -> get is used to return value of instance variable
        */

        private int length;
        private int breadth;

        // using properties
        public int Length
        {
            get { return length; }
            set { this.length = value; }
        }

        public int Breadth
        {
            get { return breadth; }
            set { this.breadth = value; }
        }
    }
}
