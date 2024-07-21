package com.suyash;

/**
 * Program to demonstrate method overriding
 */

class Par {
    public void display() {
        System.out.println("Parent class method");
    }
}

class Chi extends Par{
    @Override
    public void display(){
        System.out.println("Child class method");
    }
}

public class MethodOverriding {
    public static void main(String[] args){
        Par obj = new Chi();
        obj.display();
    }
}
