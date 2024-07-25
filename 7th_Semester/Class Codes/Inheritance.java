package basics;

/**
 * Types of inheritance
 * 1. Single Level A->B
 * 2. Multi level A->B->C
 * 3. Multiple : not possible using java. possible with interface
 **/

// single level inheritance
class Vehicle {
    private int reg;
    private String name;
    private String brand;

    public void setVehicle(int reg, String name, String brand) {
        this.reg = reg;
        this.name = name;
        this.brand = brand;
    }

    public void displayVehicle() {
        System.out.println("Reg is: " + reg);
        System.out.println("Name is: " + name);
        System.out.println("Brand is: " + brand);
    }
}

class Bike extends Vehicle {
    private int mileage;

    public void setBike(int mileage) {
        this.mileage = mileage;
    }

    public void displayBike() {
        System.out.println("Mileage is: " + mileage);
    }
}

public class Inheritance {
    public static void main(String[] args) {
        Bike bike1 = new Bike();
        bike1.setVehicle(123, "NS", "Pulsar");
        bike1.displayVehicle();

        bike1.setBike(30);
        bike1.displayBike();
    }
}
