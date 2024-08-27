package Unit1.CoreConcepts;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Method Overloading                                                                                      *
 *---------------------------------------------------------------------------------------------------------*
 * Method overloading is a feature that allows a class to have more than one method having the same name,  *
 * if their argument lists are different.                                                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * It is used to achieve compile-time polymorphism, i.e. static polymorphism.                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class Overload{
    public void sum(int a, int b){
        System.out.println("Sum of two integers: " + (a + b));
    }

    public void sum(float a, float b){
        System.out.println("Sum of two floats: " + (a + b));
    }
}

public class Overloading {
    public static void main(String[] args) {
        Overload overload = new Overload();
        overload.sum(10, 20);
        overload.sum(10.7f, 20.6f);
    }
}
