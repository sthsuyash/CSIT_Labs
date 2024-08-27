package Unit1.Files;

/**
 * Random Access File
 * ------------------
 * In java, the java.io package has a built in class called RandomAccessFile
 * that allows us to read and write data to a file randomly.
 * It has several methods to move the cursor position in file.
 */

import java.io.*;

public class RandomAccessFileDemo {
    public static void main(String[] args) {
        int a = 123;
        long b = 433234;
        String s = "Hello World!";
        try{
            RandomAccessFile raf = new RandomAccessFile("destination.txt", "rw");
            raf.writeInt(a);
            raf.writeLong(b);
            raf.writeUTF(s);
            raf.seek(125);
            System.out.println(raf.read());
            raf.close();
        }catch (IOException e){
            System.out.println(e.getMessage());
        }
    }
}
