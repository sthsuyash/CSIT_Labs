package Unit1.Files;

import java.io.*;

/**
 * Serialization is the process of writing object to  a file. For this ObjectOutputstream is used.
 * Reading an object from a file is knows as deserialization. To read o objectinpurstream is used
 * <p>
 * Steps:
 * 1. Create a class whose object is to be written to file. Such class should implement serializable interface
 * 2. open file in write mode using byte stream
 * 3, create object of ObjectOutputstream and pass object of FileOutputStream as parameter
 * 4. call method writeObject and pass object of class as parameterF
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
