package com.suyash;

import java.util.Scanner;

/**
 * Program to create one dimensional and multidimensional array.
 * Then display the array using "for loop" and "for each loop"
 * All the array data should be taken from user.
 */

public class Array {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        /* One-dimensional array */
        System.out.print("Enter the size of one-dimensional array: ");
        int n = sc.nextInt();

        int[] oneDArray = new int[n];
        System.out.print("Enter elements of one-dimensional array: ");
        /* for loop to enter the elements */
        for (int i = 0; i < n; i++) {
            oneDArray[i] = sc.nextInt();
        }

        /* for each loop to display the elements */
        System.out.println("One-dimensional array:");
        for (int i : oneDArray) {
            System.out.print(i + " ");
        }
        System.out.println();

        /* Multidimensional array */
        System.out.print("Enter the size of multidimensional array (rows and columns): ");
        int rows = sc.nextInt();
        int cols = sc.nextInt();

        int[][] multiDArray = new int[rows][cols];
        System.out.println("Enter elements of multidimensional array:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                multiDArray[i][j] = sc.nextInt();
            }
        }

        /* for each loop to print the output in matrix form */
        System.out.println("Multidimensional array:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(multiDArray[i][j] + " ");
            }
            System.out.println();
        }
    }
}