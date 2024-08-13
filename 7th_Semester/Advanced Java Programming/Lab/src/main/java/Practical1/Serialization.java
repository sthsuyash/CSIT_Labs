package Practical1;

import java.io.*;

/**
 * Serialization and Deserialization.
 * Serialization is a mechanism of converting the state of an object into a byte stream.
 * Deserialization is the reverse process where the byte stream is used to recreate the actual Java object in memory.
 */

class Person implements Serializable {
    private static final long serialVersionUID = 1L;
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

public class Serialization {
    public static void main(String[] args) {
        // Serialization
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("person.ser"))) {
            Person person = new Person("John", 25);
            oos.writeObject(person);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Deserialization
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("person.ser"))) {
            Person person = (Person) ois.readObject();
            System.out.println("Name: " + person.name + ", Age: " + person.age);
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
