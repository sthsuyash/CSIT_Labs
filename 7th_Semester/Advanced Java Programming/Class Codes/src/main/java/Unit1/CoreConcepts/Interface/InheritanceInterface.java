package Unit1.CoreConcepts.Interface;

/**
 * One interface can inherit another interface.
 * In this case, the subclass interface inherits all the methods of the superclass interface.
 * A class that implements such child interface have to provide body part of methods of both interfaces.
 */

interface Calc{
    void mul(int x, int y);
}

interface Calc2 extends Calc{
    void add(int x, int y);
}

class Solution implements Calc2{
    @Override
    public void mul(int x, int y){
        System.out.println("Multiplication is: " + (x*y));
    }

    @Override
    public void add(int x, int y){
        System.out.println("Addition is: " + (x+y));
    }
}

public class InheritanceInterface {
    public static void main(String[] args) {
        Solution obj = new Solution();
        obj.mul(10, 20);
        obj.add(20, 20);
    }
}
