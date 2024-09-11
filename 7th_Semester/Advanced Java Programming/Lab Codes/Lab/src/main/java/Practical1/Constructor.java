package Practical1;

/**
 * Program to demonstrate on how constructor of super class is called.
 */

class Parent {
    Parent() {
        System.out.println("Parent constructor");
    }
}

class Child extends Parent {
    Child() {
        super();
        System.out.println("Child constructor");
    }
}

public class Constructor {
    public static void main(String[] args) {
        Child child = new Child();
    }
}
