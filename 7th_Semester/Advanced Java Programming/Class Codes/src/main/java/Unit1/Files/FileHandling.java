package Unit1.Files;

import java.io.File;
import java.io.IOException;

/**
 * In java file is created by creating object of File class. It is inside package java.io.*;
 * Data are passed to and from file stream. Stream is considered as sequence of byte
 * <p>
 * There are two ways to pass data to and from file :
 * 1. Byte stream: here data are changed into byte then transfer into file. Two classes are used:
 *  a. FileOutputStream: to write to file using bytestream
 *  b. FileInputStrem: to read file using bytestream
 * <p>
 * 2. Character stream: here data are changed into unicode then transfer into file. Two classes are used:
 *  a. FileWriter: to write into file using character stream
 *  b. FileReader: to read from file using character stream
 */

public class FileHandling {
    public static void main(String[] args) {
        try{
            File f1 = new File("csit.txt");
            if(!f1.exists()){
                f1.createNewFile();
            }else{
                System.out.println("File already exists");
            }

            // file properties
            System.out.println("Does file exists? "+ f1.exists());
            System.out.println("Path of file is: "+ f1.getPath());
            System.out.println("Absolute path of file is: "+ f1.getAbsolutePath());
            System.out.println("File size: "+f1.getFreeSpace());
            System.out.println("Directory or not? "+ f1.isDirectory());
            System.out.println("--------------- Reading and writing to file");
        }catch (IOException e){
            System.out.println(e.getMessage());
        }
    }
}
