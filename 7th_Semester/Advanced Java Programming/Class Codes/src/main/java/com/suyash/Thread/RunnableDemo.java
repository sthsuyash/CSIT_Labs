package com.suyash.Thread;

import java.lang.Runnable;

/**
 * Creating a thread by implementing Runnable interface
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
