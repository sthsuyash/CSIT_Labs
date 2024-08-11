package com.suyash.Unit1.Exception;

import java.util.Scanner;

/**
 * Try catch inside another try catch block is called nested try catch
 * inner try catch block is executed only if outer try catch block does not handle the exception
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
