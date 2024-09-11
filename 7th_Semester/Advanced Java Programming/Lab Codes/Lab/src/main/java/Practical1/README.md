# Practical 1

1. Write a program to create a class, instance variable, constructor and method. After this create a class FirstDemo
   with main method and access the member of above class. [Solution](src/main/java/com/suyash/FirstDemo.java)

   ### Theory:

    - **Class**: A blueprint for creating objects. A class encapsulates data for the object and methods to manipulate
      that
      data.
    - **Instance Variable**: A variable that is defined in a class for which each instantiated object of the class has a
      separate copy.
    - **Constructor**: A special method that is called when an object is instantiated. It is used to initialize the
      object.
    - **Method**: A function defined in a class that operates on instances of that class.


2. Write a program to create one dimensional and multidimensional array and display the array using for and for each
   loop. All the data of array should be taken from user. [Solution](src/main/java/com/suyash/Array.java)

   ### Theory:

    - **One-Dimensional Array**: A list of elements of the same type.
    - **Multidimensional Array**: An array of arrays, where each element is itself an array.


3. Write a program to demonstrate method overloading
   condition. [Solution](src/main/java/com/suyash/MethodOverloading.java)

   ### Theory:

   Defining multiple methods with the same name but different parameters within the same class. It allows a class to
   have more than one method having the same name, if their parameter lists are different.


4. Write a program to demonstrate single level and multi-level
   inheritance. [Solution](src/main/java/com/suyash/Inheritance.java)

   ### Theory:

    - **Inheritance**: The mechanism by which one class acquires the properties and behavior of another class.
    - **Single Inheritance**: A class can inherit from only one class.
    - **Multi-Level Inheritance**: A class can inherit from another class, which in turn can inherit from another class.
    - Done by using the `extends` keyword.
    - Example: `class Child extends Parent`


5. Provide an example of single inheritance of your choice. (Two child class inheriting single parent
   class). [Solution](src/main/java/com/suyash/SingleLevelInheritance.java)

   ### Theory:

    - **Single Inheritance**: A class can inherit from only one class.


6. Provide an example of multi-level inheritance of your
   choice. [Solution](src/main/java/com/suyash/MultiLevelInheritance.java)

   ### Theory:

    - **Multi-Level Inheritance**: A class can inherit from another class, which in turn can inherit from another class.


7. Provide example on how constructor of super class is called. [Solution](src/main/java/com/suyash/Constructor.java)

   ### Theory:

    - **Super Class**: The class from which a subclass inherits.
    - **Super Keyword**: Used to refer to the superclass of the class in which it appears.
    - **Superclass Constructor**: The constructor of the superclass.


8. Provide example on method overriding condition.[Solution](src/main/java/com/suyash/MethodOverriding.java)

   ### Theory:

    - **Method Overriding**: A subclass providing a specific implementation of a method that is already provided by its
      superclass.
    - **Overriding Condition**: The method in the subclass must have the same name, same parameters or signature, and
      same return type as the method in the superclass.


9. Provide example on dynamic method dispatch. [Solution](src/main/java/com/suyash/DynamicMethodDispatch.java)

   ### Theory:

    - **Dynamic Method Dispatch**: The mechanism by which a call to an overridden method is resolved at runtime, rather
      than compile-time.
    - **Polymorphism**: The ability of an object to take on many forms.
    - **Method Overriding**: A subclass providing a specific implementation of a method that is already provided by its
      superclass.


10. Demonstrate multiple inheritance using interface. [Solution](src/main/java/com/suyash/MultipleInheritance.java)

    ### Theory:

    - **Multiple Inheritance**: A class can inherit from more than one class.
    - Done by using the `implements` keyword.
    - Interface is used to achieve multiple inheritance in Java.


11. Demonstrate inheritance in interface (extending the
    interface). [Solution](src/main/java/com/suyash/InterfaceInheritance.java)

    ### Theory:

    - **Interface**: A reference type in Java, similar to a class, that can contain only constants, method signatures,
      default methods, static methods, and nested types.
    - **Inheritance in Interface**: An interface can inherit from another interface.


12. Write a program to demonstrate multithreading using both Thread class and Runnable
    interface. [Solution](src/main/java/com/suyash/MultiThreading.java)

    ### Theory:

    - **Multithreading**: The ability of a CPU to execute multiple threads concurrently.
    - **Thread Class**: A class in Java that provides methods to create and perform operations on a thread.
    - **Runnable Interface**: An interface in Java that provides a method to run a thread.
    - **Thread**: A path of execution within a program.
    - **Concurrency**: The ability of different parts or units of a program, algorithm, or problem to be executed
      out-of-order or in partial order, without affecting the final outcome.
    - **Synchronization**: The coordination of multiple threads to prevent conflicts
    - **Deadlock**: A situation where two or more threads are waiting for each other to release a resource, preventing
      them from continuing.


13. Write a program to demonstrate inter thread
    communication. [Solution](src/main/java/com/suyash/InterThreadCommunication.java)

    ### Theory:

    - **Inter-Thread Communication**: The process of communication between two or more threads.
    - **wait()**: Causes the current thread to wait until another thread invokes the `notify()` method or
      the `notifyAll()` method for this object.
    - **notify()**: Wakes up a single thread that is waiting on this object's monitor.
    - **notifyAll()**: Wakes up all threads that are waiting on this object's monitor.


14. Write a program to demonstrate reading and writing data in
    file. [Solution](src/main/java/com/suyash/FileHandling.java)

    ### Theory:

    - **File Handling**: The process of working with files on a computer.
    - **Reading Data**: The process of reading data from a file is performed using input streams like BufferedReader.
    - **Writing Data**: The process of writing data to a file is performed using output streams like BufferedWriter.


15) Write a program to demonstrate serialization and
    deserialization. [Solution](src/main/java/com/suyash/Serialization.java)

    ### Theory:

    - **Serialization**: The process of converting an object into a stream of bytes to store the object or transmit it
      to memory, a database, or a file.
    - **Deserialization**: The process of converting a stream of bytes back into an object.
