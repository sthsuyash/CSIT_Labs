package Unit1.CoreConcepts;

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
