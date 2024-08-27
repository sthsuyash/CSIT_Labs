package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Constructor                                                                                   *
 *-----------------------------------------------------------------------------------------------*
 * A special method used to initialize objects of a class.                                       *                                                                                              *
 * Key Points about Constructors in Java:                                                        *
 * 1. The constructor has the same name as the class and no return type (not even void).         *
 * 2. It is automatically called when an object of the class is created.                         *
 * 3. There are two types of constructors:                                                       *
 *    - Default Constructor: A no-argument constructor provided by Java or defined by the user.  *
 *    - Parameterized Constructor: A constructor that accepts arguments to initialize fields.    *
 * 4. If no constructor is defined, the compiler provides a default constructor.                 *
 * 5. Constructors can be overloaded to create multiple constructors with different parameters.  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class ConstructorEg {
    // default constructor
    public ConstructorEg() {
        System.out.println("Default constructor");
    }

    // parameterized constructor
    public ConstructorEg(int a, int b) {
        System.out.println("Parameterized constructor");
        System.out.println("Value of a: " + a);
        System.out.println("Value of b: " + b);
    }
}

public class Constructor {
    public static void main(String[] args) {
        ConstructorEg c = new ConstructorEg();
        System.out.println();
        ConstructorEg c1 = new ConstructorEg(10, 20);
    }
}
