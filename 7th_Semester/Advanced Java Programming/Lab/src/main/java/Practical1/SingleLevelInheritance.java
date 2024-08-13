package Practical1;

/**
 * Single level inheritance.
 * It is a type of inheritance in which a class inherits only one class. i.e. one class extends another class and no further inheritance is done.
 * Two child classes Dog and Cat inherit the Animal class.
 */
class Animal {
    public void eat() {
        System.out.println("Animal is eating");
    }
}

class Dog extends Animal {
    public void bark() {
        System.out.println("Dog is barking");
    }
}

class Cat extends Animal {
    public void meow() {
        System.out.println("Cat is meowing");
    }
}

public class SingleLevelInheritance {
    public static void main(String[] args){
        Dog dog = new Dog();
        dog.eat();
        dog.bark();

        Cat cat = new Cat();
        cat.eat();
        cat.meow();
    }
}
