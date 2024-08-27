package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Multiple Inheritance                                                                      *
 *-------------------------------------------------------------------------------------------*
 * Ability of a class to inherit features from more than one parent class.                   *
 * In Java, multiple inheritance is not directly supported through classes to avoid          *
 * complexity and ambiguity. However, it can be achieved through interfaces.                 *
 *                                                                                           *
 * We can achive multiple inheritance in Java using interfaces.                              *
 * i.e, A class can implement multiple interfaces, thereby achieving multiple inheritance.   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

interface IFly{
    void fly();
}

interface ISwim{
    void swim();
}

class Duck implements IFly, ISwim{
    @Override
    public void fly(){
        System.out.println("Bird is flying");
    }

    @Override
    public void swim(){
        System.out.println("Bird is swimming");
    }
}

public class MultipleInheritance {
    public static void main(String[] args) {
        Duck obj = new Duck();
        obj.fly();
        obj.swim();
    }
}
