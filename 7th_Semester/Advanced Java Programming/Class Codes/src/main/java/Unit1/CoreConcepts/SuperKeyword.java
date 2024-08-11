package Unit1.CoreConcepts;

/**
 * In inheritance, constructor of superclass cannot be called by subclass's object.
 * And also if the method in superclass and subclass are same (method overriding)
 * then super keyword should be used to call the overridden method of superclass.
 * <p>
 * Uses of super keyword:
 * 1. To call superclass constructor
 * 2. To call overridden method of superclass from subclass.
 * <p>
 * If both superclass and subclass have same method and its definition then such condition is called method overriding.
 * It is used to achieve runtime polymorphism/dynamic polymorphism.
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
