package com.suyash;

/**
 * Multiple Inheritance
 */

interface A {
    void displayA();
}

interface B {
    void displayB();
}

class C implements A, B {
    public void displayA() {
        System.out.println("Display A");
    }

    public void displayB() {
        System.out.println("Display B");
    }
}

public class MultipleInheritance {
    public static void main(String[] args) {
        C obj = new C();
        obj.displayA();
        obj.displayB();
    }
}
