package Unit1.Exception;

import java.util.Scanner;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Custom Exception                                                                                        *
 *---------------------------------------------------------------------------------------------------------*
 * A custom exception refers to creating your own exception class (error).                                 *
 * To create a custom exception class, extend the `Exception` class.                                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Example:                                                                                                *
 * Program that throws an error if the age provided by the user is less than 18.                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class AgeException extends Exception {
    @Override
    public String toString() {
        return "AgeException: Age is less than 18";
    }
}

class Age {
    public void setAge(int age) throws AgeException {
        if (age < 18) {
            throw new AgeException();
        } else {
            System.out.println("Age is: " + age);
        }
    }
}

public class CustomException {
    public static void main(String[] args) {
        try {
            System.out.print("Enter age: ");
            Scanner sc = new Scanner(System.in);
            int age = sc.nextInt();

            Age a = new Age();
            a.setAge(age);
        } catch (AgeException e) {
            System.out.println(e);
        }
    }
}
