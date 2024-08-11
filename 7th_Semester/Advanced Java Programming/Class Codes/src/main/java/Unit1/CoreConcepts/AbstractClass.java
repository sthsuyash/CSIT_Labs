package Unit1.CoreConcepts;

/**
 * Abstract class is a class that is declared with abstract keyword and cannot be instantiated. i.e. object cannot be created
 *
 * Rules of Abstract class:
 * 1. Object cannot be created.
 * 2. It can have constructors, instance variable and normal methods.
 * 3. It can have abstract methods(methods without body) and concrete methods(methods with body).
 * 4. Normal class have to inherit abstract class and implement all the abstract methods.
 */

abstract class Calculation{
    private int x;
    private int y;

    public Calculation(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void calcSum(){
        System.out.println("Sum is: " + (x + y));
    }

    // abstract method
    public abstract void calcDiff();
    public abstract void calcMul();
}

class Solution extends Calculation{
    private int x1;
    private int x2;

    public Solution(int x1, int x2){
        super(x1, x2);
        this.x1 = x1;
        this.x2 = x2;
    }

    @Override
    public void calcDiff(){
        System.out.println("Difference is: " + (x1 - x2));
    }

    @Override
    public void calcMul(){
        System.out.println("Multiplication is: " + (x1 * x2));
    }
}

public class AbstractClass {
    public static void main(String[] args) {
        // Calculation c1 = new Calculation(10, 20); // error: cannot instantiate abstract class
        Solution s1 = new Solution(10, 20);
        s1.calcSum();
        s1.calcDiff();
        s1.calcMul();
    }
}
