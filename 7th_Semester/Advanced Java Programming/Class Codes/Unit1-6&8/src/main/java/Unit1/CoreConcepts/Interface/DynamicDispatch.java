package Unit1.CoreConcepts.Interface;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Dynamic method dispatch                                                               *           
 *---------------------------------------------------------------------------------------*
 * It is a process of assigning subclass's object to reference variable of superclass.   *
 * Now superclass ref will call subclass version of override method                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
interface Calculation1{
    void findSquare(int a);
    void findSquareRoot(int a);
}

interface Calculation2{
    void findMulti(int x, int y);
}

class Sol implements Calculation1, Calculation2{
    public void findSquare(int a){
        System.out.println("Square of " + a + " is: " + a*a);
    }

    public void findSquareRoot(int a){
        System.out.println("Square root of " + a + " is: " + Math.sqrt(a));
    }

    public void findMulti(int x, int y){
        System.out.println("Multiplication of " + x + " and " + y + " is: " + x*y);
    }
}

public class DynamicDispatch {
    public static void main(String[] args) {
        Calculation1 c1;
        Sol s = new Sol();
        c1 = s; // reference variable of superclass is assigned to subclass object
        c1.findSquare(5);
        c1.findSquareRoot(25);
        // c1.findMulti(5, 10); // error as c1 is reference variable of Calculation1 interface and findMulti is not present in it
    }
}
