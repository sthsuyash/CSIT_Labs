package Unit1.Exception;

import java.util.Scanner;

/**
 * Exception handling: It is a mechanism to handle runtime errors so that normal flow of the application can be maintained
 * <p>
 * try: any code section that can produce exception is placed on try block
 * catch: if any error occur in try block then such exception should be caught in catch block
 * throw: to explicitly throw an exception
 * throws: if exception can occur from method then it should be declared in method signature
 * finally: block that will always execute whether exception occurs or not
 * <p>
 * difference between throw and throws:
 * 1) throw: used to throw an exception explicitly
 * 2) throws: used to declare an exception
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
