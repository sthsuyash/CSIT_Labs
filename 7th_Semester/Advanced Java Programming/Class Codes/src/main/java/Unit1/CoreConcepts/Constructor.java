package com.suyash.Unit1.CoreConcepts;

/**
 * Constructor is a special type of method that is used to initialize the object.
 * It is called when an object is created.
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
