package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Inheritance and the `super` Keyword                                                                     *
 *---------------------------------------------------------------------------------------------------------*
 * In inheritance, the constructor of the superclass cannot be directly called by the subclass's object.   *
 * If a method in the superclass is overridden in the subclass (method overriding), the `super` keyword    *
 * should be used to call the overridden method of the superclass.                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Uses of the `super` Keyword:                                                                            *
 * 1. To call the superclass constructor.                                                                  *
 * 2. To call an overridden method of the superclass from the subclass.                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Method Overriding:                                                                                      *
 * If both the superclass and subclass have the same method and its definition, this is called method      *
 * overriding. It is used to achieve runtime polymorphism, also known as dynamic polymorphism.             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */


class Vehicles {
    private int reg;
    private String name;

    // default constructor
    public Vehicles(){}

    // parameterized constructor
    public Vehicles(int reg, String name){
        this.reg = reg;
        this.name = name;
    }

    public void display(){
        System.out.println("Vehicle Registration: " + reg);
        System.out.println("Vehicle Name: " + name);
    }
}

// now creating a subclass to inherit the properties of superclass
class Car extends Vehicles{
    private String price;

    // default constructor
    public Car(){}

    // parameterized constructor
    public Car(int reg, String name, String price){
        super(reg, name);
        this.price = price;
    }

    // method overriding condition
    public void display(){
        super.display(); // calls display of superclass
        System.out.println("Car Price: " + price);
    }
}

public class SuperKeyword {
    public static void main(String[] args) {
        Car car = new Car();
        car.display();

        System.out.println();
        Car car2 = new Car(1234, "Audi", "1000000");
        car2.display();
    }
}
