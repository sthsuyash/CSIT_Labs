package Practical1;

/**
 * Single level and multi-level inheritance.
 */

/* Super class */
class Vehicle {
    void drive() {
        System.out.println("Vehicle is driven");
    }
}

/* Single level inheritance */
class Car extends Vehicle{
    void drive() {
        System.out.println("Car is driven");
    }
}

/* Multi level inheritance */
class Audi extends Car {
    void drive() {
        System.out.println("Audi is driven");
    }
}

public class Inheritance {
    public static void main(String[] args) {
        Car car = new Car();
        car.drive();

        Audi audi = new Audi();
        audi.drive();
    }
}