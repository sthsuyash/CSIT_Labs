package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Inner Class                                                                       *
 *-----------------------------------------------------------------------------------*
 * An inner class refers to a class that is declared inside another class or         *
 * interface. Inner classes were introduced to group logically related classes       *
 * together.                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Advantages of Inner Classes:                                                      *
 * -> Makes code clean and readable.                                                 *
 * -> Optimizes code.                                                                *
 * -> Allows access to private methods of the outer class, making the code more      *
 *    closely resemble real-world scenarios.                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Inner classes are mainly used when certain operations need to be performed by     *
 * granting access to a limited set of classes.                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Types of Inner Classes in Java:                                                   *
 * -> Nested Inner Class                                                             *
 * -> Method Local Inner Class                                                       *
 * -> Anonymous Inner Class                                                          *
 * -> Static Nested Inner Class                                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */


public class InnerClass {
    private int data = 30;

    class Inner {
        void msg() {
            System.out.println("data is " + data);
        }
    }

    public static void main(String[] args) {
        InnerClass obj = new InnerClass();
        InnerClass.Inner in = obj.new Inner();
        in.msg();
    }
}
