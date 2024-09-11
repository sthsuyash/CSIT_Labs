package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Method Overriding                                                                                       *
 *---------------------------------------------------------------------------------------------------------*
 * Method overriding occurs when a subclass provides a specific implementation of a method that is already *
 * defined in its superclass. The method in the subclass must have the same name, return type, and         *
 * parameter list as the method in the superclass.                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * It is used to achieve runtime polymorphism, also known as dynamic polymorphism, allowing a subclass to  *
 * define behavior specific to its type while reusing the interface of the superclass.                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */


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
         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
         * If a parent's type reference refers to a Child object, Child's show() is called.  *
         * This is called runtime polymorphism.                                              *
         * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
         */
        p = new Child();
        p.show();
    }
}
