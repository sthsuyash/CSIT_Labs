package com.suyash;
import java.io.*;

/**
 * Program to read and write to a file.
 *
 * Reading from a file can be done using BufferedReader class.
 * It reads the text from a character-input stream, buffering characters so as to provide for the efficient reading of characters, arrays, and lines.
 *
 * Writing to a file can be done using BufferedWriter class.
 * It writes text to a character-output stream, buffering characters so as to provide for the efficient writing of single characters, arrays, and strings.
 */

public class FileIO {
    /* Writing to a file */
    public static void writeToFile(String fileName, String content) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            System.out.println("Writing to file...");
            writer.write(content);
            System.out.println("Content written successfully!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /* Reading from a file */
    public static String readFromFile(String fileName) {
        StringBuilder content = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            System.out.println("Reading from file...");
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
            System.out.println("Content read successfully!");
        } catch (IOException e) {
            e.printStackTrace();
        }
        return content.toString();
    }

    /* Main method */
    public static void main(String[] args) {
        String fileName = "file.txt";
        String content = "Hello, World!";
        writeToFile(fileName, content);
        System.out.println(readFromFile(fileName));
    }
}
