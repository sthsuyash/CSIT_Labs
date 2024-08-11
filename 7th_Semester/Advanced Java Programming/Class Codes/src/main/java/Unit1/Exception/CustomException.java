package com.suyash.Unit1.Exception;

import java.util.Scanner;

/**
 * Custom Exception refers to creating own exception class(error)
 * To create own exception class, we need to extend Exception class
 * <p>
 * Program that throw error if the age given by user is less than 18
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
