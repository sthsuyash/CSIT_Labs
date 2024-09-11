package Unit1.Files;

import java.io.File;
import java.io.IOException;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * File Handling in Java                                                                                   *
 *---------------------------------------------------------------------------------------------------------*
 * In Java, a file is created by instantiating an object of the `File` class, which is inside the          *
 * `java.io.*` package. Data is passed to and from a file using streams, which are considered as a         *
 * sequence of bytes.                                                                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * There are two ways to pass data to and from a file:                                                     *
 * 1. Byte Stream: Data is converted into bytes and then transferred to the file. The following classes    *
 *    are used for byte stream operations:                                                                 *
 *    a. `FileOutputStream`: Used to write data to a file using a byte stream.                             *
 *    b. `FileInputStream`: Used to read data from a file using a byte stream.                             *
 *                                                                                                         *
 * 2. Character Stream: Data is converted into Unicode and then transferred to the file. The following     *
 *    classes are used for character stream operations:                                                    *
 *    a. `FileWriter`: Used to write data to a file using a character stream.                              *
 *    b. `FileReader`: Used to read data from a file using a character stream.                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
