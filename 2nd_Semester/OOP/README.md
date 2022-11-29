# Object Oriented Programming using C++

## Table of Contents

- [Overview of OOP](#introduction)
- [Basics of C++ Programming](Basics/)
- [Classes and Objects](Classes_and_objects/)
- [Operator Overloading](Operator_overloading/)
- [Inheritance](Inheritance/)
- [Virtual function, Polymorphism](VF_polymorphism/)
- [Function Templates and Exception](Function_templates_Exception/)
- [File Handling and Streams](File_handling_and_streams/)

## Introduction

Object-oriented programming (OOP) was developed to overcome the limitations of the procedure-oriented programming is an improved technique for developing the programs.

In case of OOP, the data is treated as the most critical element and the primary focus is on the data and not on the procedures. In this technique, the data is grouped together with the functions that operate on it.

- A problem is divided into entities known as objects.
- Each object maintains its own copy of data and functions.

The data cannot be accessed directly by the other objects of the program. It can only be accessed through a proper interface such as functions.

Examples of OOP languages include Simula, C++, Python, Java etc.

## Characteristics/Features of OOP

1. [Objects](#objects)
2. [Classes](#classes)
3. [Encapsulation](#encapsulation)
4. [Abstraction](#abstraction)
5. [Inheritance](#inheritance)
6. [Polymorphism](#polymorphism)

### Objects

- In object-oriented programming, a problem is divided into certain basic entities called objects. The objects can be used to represent real life objects such as people, car, and so on.
- In this type of programming, all communication is carried out between the objects. When a program is executed, the objects interact with each other by sending messages.
- The objects contain the data and the functions that can be used to manipulate the data. Each object maintains its own copy of the data and methods, which can communicate with each other through a proper channel or interface.

### Classes

- A class is a user-defined data type which is used to group the data and the functions together.
- The objects are the instances of a class.
- A class can also contain important members such as a constructor to create objects.
- The objects that belong to same class must have certain properties in common.
• For example, a table and a chair are the objects of the furniture class.
Both the objects have certain properties in common. For example,
both are made of wood and so on.

### Encapsulation

- Encapsulation is a mechanism used for wrapping up the data along with the functions that can operate on the data directly.
- This mechanism is used to keep the data safe from outside interferences.
- It hides the internal data and only provides the external interface (functions) through which it can be accessed.
- Encapsulation also provides the concept of data hiding or information hiding so that it cannot be accessed directly.

### Abstraction

- Data abstraction is one of the most essential and important feature of object oriented programming in C++.
- Abstraction means displaying only essential information(result) and hiding the details(pow() in math.h or add() defined by user).
- Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
- Consider a real life example of a man driving a car. The man only knows that pressing the accelerators will increase the speed of car or applying brakes will stop the car but he does not know about how on pressing accelerator the speed is actually increasing, he does not know about the inner mechanism of the car or the implementation of accelerator, brakes etc in the car. This is what abstraction is.

### Inheritance

- Different kinds of objects often have certain amount of properties in common with each other.
- Inheritance is the process by which one object can acquire the properties of another object. This is called the reusability of code.
- In inheritance, whenever a new object is created, it can only define those properties that makes it unique from the other objects.
- Inheritance supports the concept of the hierarchical classifications.
- For example, the fruit ‘Apple’ is a part of the class ‘Fruits’, which is again a part of the class ‘Food’.
- The two classes Fruits and Vegetables, apart from inheriting certain properties from the class Food, add some properties of their own.
- The classes Apple and Mango inherit the properties of the Fruits class while the classes Cabbage and Carrot inherit the properties of the Vegetables class.

### Polymorphism

- Polymorphism is another feature of object-oriented programming.
- Polymorphism is a Greek term that consists of two words, poly and morph. Poly means many and morph means forms. So, polymorphism
means ‘one name many forms’.
- In polymorphism, the internal structure (functioning) of the operation is different but the external interface (name) is the same. When a single function name is used to perform different operations, it is known as function overloading.

## Benefits of OOP

- By using inheritance, we can eliminate redundant code and extend the use of existing classes.
- We can build the programs from standard working modules that communicate with one another, rather than having to start writing the code from scratch which leads to saving of development time and higher productivity.
- The new technology promises greater programmer productivity, better quality of software and lesser maintenance cost.
- OOP systems can be easily upgraded from small to large systems.
- It is possible that multiple instances of objects co-exist without any interference.
- It is very easy to partition the work in a project based on objects.
- The principle of data hiding helps the programmer to build secure programs which cannot be invaded by the code in other parts of the program.
