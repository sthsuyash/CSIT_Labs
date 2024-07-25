package com.suyash;

/**
 * Constructor is a special type of method that is used to initialize the object.
 * It is called when an object is created.
 */
public class Constructor {
    // default constructor
    public Constructor() {
        System.out.println("Default constructor");
    }

    // parameterized constructor
    public Constructor(int a, int b) {
        System.out.println("Parameterized constructor");
        System.out.println("Value of a: " + a);
        System.out.println("Value of b: " + b);
    }

    public static void main(String[] args) {
        Constructor c = new Constructor();
        Constructor c1 = new Constructor(10, 20);
    }
}
