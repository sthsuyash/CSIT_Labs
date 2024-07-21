package com.suyash;

/**
 * Interface Inheritance
 */

interface As {
    void displayA();
}

interface Bs extends As {
    void displayB();
}

class Cs implements Bs {
    public void displayA() {
        System.out.println("Display A");
    }

    public void displayB() {
        System.out.println("Display B");
    }
}

public class InterfaceInheritance {
    public static void main(String[] args) {
        Cs obj = new Cs();
        obj.displayA();
        obj.displayB();
    }
}
