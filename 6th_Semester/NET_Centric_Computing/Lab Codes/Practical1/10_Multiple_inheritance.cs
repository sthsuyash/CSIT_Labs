using System;

/*
 * Multiple inheritance using interfaces
 */

namespace Practical1
{
    public interface IShape
    {
        void Draw();
    }

    public interface IColor
    {
        void FillColor();
    }

    public class Circle : IShape, IColor
    {
        public void Draw()
        {
            Console.WriteLine("Drawing Circle");
        }

        public void FillColor()
        {
            Console.WriteLine("Filling color in Circle");
        }
    }
}
