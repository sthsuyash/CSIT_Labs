package Unit1.Exception;

import java.util.Scanner;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Nested Try-Catch                                                                                        *
 *---------------------------------------------------------------------------------------------------------*
 * A nested try-catch refers to a try-catch block placed inside another try-catch block.                   *
 * The inner try-catch block is executed only if the outer try-catch block does not handle the exception.  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

public class NestedTryCatch {
    public static void main(String[] args){
        try{
            // inner try catch
            try{
                Scanner sc = new Scanner(System.in);
                int a = sc.nextInt();
                int b = sc.nextInt();

                // if value of b is 0, then exception will occur, which is handled by catch block
                int c = a/b;
                System.out.println("Division is: " + c);
            }
            catch (ArrayIndexOutOfBoundsException e){
                System.out.println("Inner catch block: " + e);
            }
        }
        catch (ArithmeticException e){
            System.out.println("Exception occurred: " + e);
        }
    }
}
