package Unit1.Files;

import java.io.*;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Serialization and Deserialization in Java                                                               *
 * ------------------------------------------------------------------------------------------------------- *
 * Serialization is the process of writing an object to a file, for which `ObjectOutputStream` is used.    *
 * Deserialization refers to reading an object from a file, which is done using `ObjectInputStream`.       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Steps to Serialize an Object:                                                                           *
 * 1. Create a class whose object is to be written to a file. This class should implement the              *
 * `Serializable` interface.                                                                               *
 * 2. Open the file in write mode using a byte stream.                                                     *
 * 3. Create an object of `ObjectOutputStream` and pass an object of `FileOutputStream` as a parameter.    *
 * 4. Call the `writeObject` method and pass the object of the class as a parameter.                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class Box implements Serializable {
    int width;
    int height;

    public Box(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public void calculateArea() {
        System.out.println("Area of box is: " + width * height);
    }
}

public class Serialization {
    public static void main(String[] args) {
        try {
            Box box = new Box(10, 20);
            // create new file
            File f1 = new File("box.txt");
            // f1.createNewFile();

            // open file in write mode
            FileOutputStream fos = new FileOutputStream(f1);
            // create object of objectoutputstream
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            // write object to file
            oos.writeObject(box);

            System.out.println("----------- Reading object from file -----------");

            FileInputStream fis = new FileInputStream(f1);
            ObjectInputStream ois = new ObjectInputStream(fis);

            // When object is read, then it returns object of type Object,
            // so we have to case such object into appropriate class
            Box b = (Box) ois.readObject();
            b.calculateArea();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
