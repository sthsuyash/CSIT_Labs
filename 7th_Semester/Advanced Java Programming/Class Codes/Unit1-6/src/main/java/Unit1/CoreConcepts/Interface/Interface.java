package Unit1.CoreConcepts.Interface;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Interface                                                                                               *
 *---------------------------------------------------------------------------------------------------------*
 * Interface is a reference type in Java. It is a collection of abstract methods.                          *
 * It is similar to class. It is a blueprint of a class.                                                   *
 * It has static constants and abstract methods.                                                           *
 * It is used to achieve abstraction and multiple inheritance in Java.                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * A class implements an interface, so inheriting the abstract methods of the interface.                   *
 * The class that implements the interface must provide the method body for each method in the interface.  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

interface IBird {
    // abstract method
    void fly();
}

class BirdImpl implements IBird{
    public void fly(){
        System.out.println("Bird is flying");
    }
}

public class Interface{
    public static void main(String[] args) {
        BirdImpl obj = new BirdImpl();
        obj.fly();
    }
}
