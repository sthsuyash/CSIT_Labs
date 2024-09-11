package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Class                                                                                         *
 *-----------------------------------------------------------------------------------------------*
 * A blueprint for creating objects, providing initial values for state (member variables), and  *
 * implementations of behavior (member methods).                                                 *
 * Key Points about Classes in Java:                                                             *
 * 1. A class is defined using the `class` keyword followed by the class name.                   *
 * 2. A class can have fields (variables), methods, constructors, blocks, and nested classes.    *
 * 3. Objects are instances of a class, and they represent the real-world entities or concepts.  *
 * 4. Access modifiers (public, private, protected) control the visibility and access of the     *
 *    class and its members.                                                                     *
 * 5. A class can extend another class (inheritance) and implement interfaces.                   *
 * 6. The `new` keyword is used to create an instance (object) of a class.                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class Box {
    /**
     * Instance variable or attribute
     * => variables declared inside a class but outside a method
     */
    private int length;
    private int breadth;
    private int height;

    /**
     * default constructor
     * => a constructor with no parameters
     */
    public Box() {
        length = 0;
        breadth = 0;
        height = 0;
    }

    /**
     * Parameterized constructor
     * => a constructor with parameters
     */
    public Box(int l, int b, int h) {
        this.length = l;
        this.breadth = b;
        this.height = h;
    }

    /**
     * Method
     * => a function defined inside a class
     */
    public int volume() {
        return length * breadth * height;
    }

    public void display() {
        System.out.println("Length: " + length);
        System.out.println("Breadth: " + breadth);
        System.out.println("Height: " + height);
    }

    public void calc() {
        System.out.println("This is calc method with no parameters");
    }

    public void calc(int x, int y) {
        System.out.println("This is calc method with 2 parameters (int type)");
        System.out.println("The Sum is: " + x + y);
    }

    public void calc(double x, double y) {
        System.out.println("This is calc method with 2 parameters (double type)");
        System.out.println("The Multiplication is" + x * y);
    }

}

public class Class {
    public static void main(String[] args) {

        // creating an object of Box class
        Box b1 = new Box();
        Box b2 = new Box(10, 20, 30);

        b1.display();
        System.out.println("Volume of b1: " + b1.volume());

        System.out.println();

        b2.display();
        System.out.println("Volume of b2: " + b2.volume());

        b2.calc();
        b2.calc(5, 6);
        b2.calc(10.0, 2.0);

//        Scanner sc = new Scanner(System.in);
//
//        // hold the screen
//        System.out.println("Press enter to exit...");
//        sc.nextLine();
//
//        sc.close();
    }

}

