package com.suyash;

/**
 * Multi level inheritance
 */
class Animals {
    public void eat() {
        System.out.println("Animal is eating");
    }
}

class Dogs extends Animals {
    public void bark() {
        System.out.println("Dog is barking");
    }
}

class GermanShepherd extends Dogs{
    public void play(){
        System.out.println("German Shepherd is playing");
    }
}

public class MultiLevelInheritance {
    public static void main(String[] args) {
        GermanShepherd gs = new GermanShepherd();
        gs.eat();
        gs.bark();
        gs.play();
    }
}
