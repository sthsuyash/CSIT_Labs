package Unit1.CoreConcepts;

class Parent{
    void show(){
        System.out.println("Parent's show");
    }
}

class Child extends Parent{
    @Override
    void show(){
        System.out.println("Child's show");
    }
}

public class Overriding {
    public static void main(String[] args) {
        Parent p = new Parent();
        p.show();

        /**
         * If a parent's type reference refers to a Child object, Child's show() is called.
         * This is called runtime polymorphism.
         */
        p = new Child();
        p.show();
    }
}
