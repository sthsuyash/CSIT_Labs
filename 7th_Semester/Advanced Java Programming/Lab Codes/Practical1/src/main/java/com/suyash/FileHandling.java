package com.suyash;

import java.io.*;

public class FileHandling {
    public static void main(String[] args) {
        try {
            File f1 = new File("file.txt");
            if (!f1.exists()) {
                f1.createNewFile();
            } else {
                System.out.println("File already exists");
            }

            // Write to file
            FileOutputStream fos = new FileOutputStream(f1);
            String str = "This is file handling";

            // Change into byte
            byte[] data = str.getBytes();
            fos.write(data); //write into file
            fos.close();


            // Reading from file using byte stream
            FileInputStream fis = new FileInputStream(f1);
            int i = 0;
            while ((i = fis.read()) != -1) {
                System.out.print((char) i); //cast into character
            }


        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
