package Practical1;

/**
 * Method Overloading
 * It is a type of static polymorphism where
 */

class MethodOverloadingDemo{
    void display(int a){
        System.out.println("Integer: " + a);
    }

    void display(double a){
        System.out.println("Double: " + a);
    }

    void display(String a, String b){
        System.out.println("String: " + a + " " + b);
    }
}

public class MethodOverloading {
    public static void main(String[] args){
        MethodOverloadingDemo object = new MethodOverloadingDemo();
        object.display(10);
        object.display(10.5);
        object.display("Hello", "World");
    }
}

