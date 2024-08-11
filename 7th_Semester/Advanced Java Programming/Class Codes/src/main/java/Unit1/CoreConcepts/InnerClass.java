package Unit1.CoreConcepts;

/**
 * Inner class refers to the class that is declared inside another class or interface which were introduced, to sum up,
 * same logically relatable classes.
 * Following are certain advantages associated with inner classes:
 * -> Making code clean and readable
 * -> Code optimization
 * -> Private methods of outer class can be accessed, so bringing a new dimension and making it closer to real world.
 * <p>
 * We use inner classes mainly where we want certain operations to be performed, granting access to limited classes.
 * There are basically four types of inner classes in java:
 * -> Nested Inner Class
 * -> Method Local Inner Class
 * -> Anonymous Inner Class
 * -> Static Nested Inner Class
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
