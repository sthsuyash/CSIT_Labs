using System;

/*
 * Program to demonstrate abstract class
*/

namespace Practical1
{
    public abstract class NewShape
    {
        public abstract void Draw();
    }

    class NewCircle : NewShape
    {
        public override void Draw()
        {
            Console.WriteLine("Drawing Circle");
        }
    }
}
