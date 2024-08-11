package Unit1.CoreConcepts;

/**
 * Array is the collection of similar types of elements under the same variable name having contiguous memory locations.
 * Java array is an object that contains elements of similar data type.
 * There are two types of arrays in java:
 * 1. Single Dimensional Array : int arr[] = new int[5];
 * 2. Multi Dimensional Array : int arr[][] = new int[3][3];
 */

public class Array {
    public static void main(String[] args) {
        /**
         * Single Dimensional Array
         */
        int[] arr = new int[5];
        // set the value of array with index + 1
        for (int i = 0; i < 5; i++) {
            arr[i] = i + 1;
        }

        // read the value of array using for each loop
        for (int i : arr) {
            System.out.print(i + " ");
        }

        System.out.println("\n");
        /**
         * Multi Dimensional Array
         */
        int[][] arr2 = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                arr2[j][j] = j + j;
            }
        }

        // display the 3D array in matrix form using foreach loop
        for (int[] i : arr2) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
