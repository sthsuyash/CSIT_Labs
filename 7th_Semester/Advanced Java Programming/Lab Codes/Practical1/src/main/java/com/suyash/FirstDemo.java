package com.suyash;

/**
 * Program to create a class, instance variable, constructor and method.
 * After this, create a class FirstDemo with main method and access the member of above class
 */

class MyClass {
    /**
     * Instance variables
     **/
    int a;
    int b;

    /**
     * Constructor
     **/
    public MyClass(int a, int b) {
        this.a = a;
        this.b = b;
    }

    /**
     * Method
     **/
    public void display() {
        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }
}

/**
 * FirstDemo class to access the member of above class
 */

public class FirstDemo{
    public static void main(String[] args){
        MyClass object = new MyClass(10, 20);
        object.display();
    }
}