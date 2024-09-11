package Unit1.Exception;

import java.util.Scanner;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Exception Handling                                                                                      *
 *---------------------------------------------------------------------------------------------------------*
 * Exception handling is a mechanism to handle runtime errors so that the normal flow of the application   *
 * can be maintained.                                                                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Key Components of Exception Handling:                                                                   *
 * 1) `try`: Code sections that can produce exceptions are placed in a try block.                          *
 * 2) `catch`: If an error occurs in the try block, the exception is caught in the catch block.            *
 * 3) `throw`: Used to explicitly throw an exception.                                                      *
 * 4) `throws`: Declares that a method can throw exceptions, specified in the method signature.            *
 * 5) `finally`: A block that always executes, whether an exception occurs or not.                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Difference Between `throw` and `throws`:                                                                *
 * 1) `throw`: Used to explicitly throw an exception.                                                      *
 * 2) `throws`: Used to declare an exception.                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

public class ExceptionHandling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        // if value of b is 0, then exception will occur, which is handled by catch block
        try {
            int c = a / b;
            System.out.println("Division is: " + c);

            // ArrayIndexOutOfBoundsException occurs when array index is out of bound
            int arr[] = new int[2];
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 3;
        } catch (ArithmeticException | ArrayIndexOutOfBoundsException e) {
            System.out.println("Exception occurred: " + e);
        } catch (Exception e) {
            System.out.println("Exception occurred: " + e);
        } finally {
            System.out.println("Finally block executed");
        }

        System.out.println("Out of try-catch block");
    }
}
