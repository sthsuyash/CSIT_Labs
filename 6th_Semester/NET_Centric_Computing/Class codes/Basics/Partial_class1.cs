/*
 * Partial class is a class that is divided into two or more separate files.
 * The partial keyword is used to create a partial class.
 * Class definition can be split into multiple files.
 * Here, the class is divided into two files: Partial_class1.cs and Partial_class2.cs.
 */
namespace Basics
{
    public partial class Partial_class
    {
        private int x;
        private int y;

        public Partial_class(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
}
