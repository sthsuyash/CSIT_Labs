package com.suyash;

class Ad {
    void display() {
        System.out.println("Class A display method");
    }
}

class Bd extends Ad {
    void display() {
        System.out.println("Class B display method");
    }
}

class Cd extends Ad {
    void display() {
        System.out.println("Class C display method");
    }
}

public class DynamicMethodDispatch {
    public static void main(String[] args) {
        Ad ad;
        ad = new Bd();
        ad.display();
        ad = new Cd();
        ad.display();
    }
}
