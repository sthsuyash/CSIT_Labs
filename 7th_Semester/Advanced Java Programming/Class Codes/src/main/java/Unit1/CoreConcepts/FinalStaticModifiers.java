package Unit1.CoreConcepts;

/**
 * They are non-access modifiers in Java, providing special properties to the variables and methods.
 * Static modifier is used to create class methods and variables -> belongs to the class and not to the instance.
 * Final modifier is used to restrict the user -> cannot change the value.
 * <p>
 * Static Modifier:
 * 1. Static variables: It is used to refer the common property of all objects (that is not unique for each object).
 * Only one copy of static variable is created and shared among all the objects of the class.
 * 2. Static methods: It is used to refer the common property of all objects (that is not unique for each object).
 * It can be accessed without creating an object of the class. i.e. by using the class name. e.g. Math.pow(2, 3)
 * <p>
 * Final Modifier:
 * 1. Final variables: It is used to restrict the user -> cannot change the value.
 * 2. Final methods: It is used to restrict the user -> cannot override the method.
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
