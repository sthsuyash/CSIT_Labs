package Unit1.Thread;

import java.lang.Runnable;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Runnable Interface                                                                                      *
 *---------------------------------------------------------------------------------------------------------*
 * The `Runnable` interface represents a task that can be executed concurrently in a thread.               *
 * It contains a single method, `run()`, which is intended to contain the code that constitutes the        *
 * task to be executed by a thread.                                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Implementing the `Runnable` interface allows the task to be executed by a thread by following these     *
 * steps:                                                                                                  *
 * 1. Implement the `Runnable` interface in a class and override the `run()` method to define the task.    *
 * 2. Create an instance of the `Thread` class and pass the `Runnable` instance to its constructor.        *
 * 3. Call the `start()` method on the `Thread` instance to initiate the execution of the task.            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class Calculate3 implements Runnable {
    @Override
    public void run() {
        try {
            // display even numbers from 1 to 10 in interval of 1 seconds
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    System.out.println("Even number: " + i);
                    Thread.sleep(1000);
                }
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}

class Calculate4 implements Runnable {
    @Override
    public void run() {
        try {
            // display odd numbers from 1 to 10 in interval of 1.5 seconds
            for (int i = 0; i < 10; i++) {
                if (i % 2 != 0) {
                    System.out.println("Odd number: " + i);
                    Thread.sleep(1500);
                }
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }
    }
}

public class RunnableDemo {
    public static void main(String[] args) {
        Calculate3 c3 = new Calculate3();
        Calculate4 c4 = new Calculate4();

        // To create thread, we need to create object of Thread class
        Thread t1 = new Thread(c3);
        Thread t2 = new Thread(c4);

        // starting thread
        t1.start(); // calls run method
        t2.start();
    }
}
