package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Non-Access Modifiers                                                                          *
 *-----------------------------------------------------------------------------------------------*
 * Non-access modifiers in Java provide special properties to variables and methods.             *
 *                                                                                               *
 * Static Modifier:                                                                              *
 * 1. Static variables:                                                                          *
 *    - Used to refer to the common property of all objects (not unique for each object).        *
 *    - Only one copy of the static variable is created and shared among all objects of the      *
 *      class.                                                                                   *
 *                                                                                               *
 * 2. Static methods:                                                                            *
 *    - Used to refer to the common property of all objects (not unique for each object).        *
 *    - Can be accessed without creating an object of the class, by using the class name.        *
 *      Example: Math.pow(2, 3)                                                                  *
 *                                                                                               *
 * Final Modifier:                                                                               *
 * 1. Final variables:                                                                           *
 *    - Used to restrict the user from changing the value of the variable.                       *
 *                                                                                               *
 * 2. Final methods:                                                                             *
 *    - Used to restrict the user from overriding the method.                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class StaticFinalDemo {
    // static variable
    static int staticVar = 5;

    // final variable
    final static int finalVar = 10;

    // static method
    static void staticMethod() {
        System.out.println("Static method");
    }

    // final method
    final static void finalMethod() {
        System.out.println("Final method");
    }
}

public class FinalStaticModifiers {
    public static void main(String[] args) {
        // static variable
        System.out.println("Static variable");
        System.out.println("Value of static variable: " + StaticFinalDemo.staticVar);
        StaticFinalDemo.staticVar = 10;
        System.out.println("Value of static variable: " + StaticFinalDemo.staticVar);

        // static method
        System.out.println("\nStatic method");
        StaticFinalDemo.staticMethod();

        // final variable
        System.out.println("\nFinal variable");
        System.out.println("Value of final variable: " + StaticFinalDemo.finalVar);
        // StaticFinalDemo.finalVar = 10; // cannot change the value of final variable

        // final method
        System.out.println("\nFinal method");
        StaticFinalDemo.finalMethod();
    }
}
