package Unit1.CoreConcepts;

/**
 * Inheritance is the process of acquiring the properties and behavior of a class into another class.
 * Such class that inherits another class is subclass/derived class and the class that is inherited is superclass/base class.
 * <p>
 * Subclass can access all the public and protected members of superclass.
 * <p>
 * Types of inheritance
 * 1) Single Level (A -> B)
 * 2) Multi level (A -> B -> C)
 * 3) Multiple: not possible using java. Possible with interface (A -> B, C)
 */

/**
 * Base class
 */
class Vehicle {
    protected int reg;
    protected String name;
    protected String brand;

    protected void setVehicle(int reg, String name, String brand) {
        this.reg = reg;
        this.name = name;
        this.brand = brand;
    }

    protected void displayVehicle() {
        System.out.println("Reg is: " + reg);
        System.out.println("Name is: " + name);
        System.out.println("Brand is: " + brand);
    }
}

/**
 * Single level inheritance
 */
class Bike extends Vehicle {
    protected int mileage;

    protected void setBike(int reg, String name, String brand, int mileage) {
        super.setVehicle(reg, name, brand);
        this.mileage = mileage;
    }

    protected void displayBike() {
        super.displayVehicle();
        System.out.println("Mileage is: " + mileage);
    }
}

/**
 * Multi level inheritance
 */
class Yamaha extends Bike {
    private String model;

    public void setYamaha(int reg, String name, String brand, int mileage, String model) {
        super.setBike(reg, name, brand, mileage);
        this.model = model;
    }

    public void displayYamaha() {
        super.displayBike();
        System.out.println("Model is: " + model);
    }
}

public class Inheritance {
    public static void main(String[] args) {
        // create object of Single level inheritance
        Bike bike1 = new Bike();
        bike1.setBike(123, "NS", "Pulsar", 30);
        bike1.displayBike();

        System.out.println();

        // create object of Multi level inheritance
        Yamaha yamaha1 = new Yamaha();
        yamaha1.setYamaha(456, "FZ", "Yamaha", 40, "FZS");
        yamaha1.displayYamaha();
    }
}
