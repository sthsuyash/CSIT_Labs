package com.suyash.Unit1.Thread;

/**
 * Creating a thread by extending Thread class
 */
class Calculate extends Thread {
    // It contains run method, which should be compulsory to use
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

class Calculate2 extends Thread {
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

public class ThreadClass {
    public static void main(String[] args) {
        // creating object of Calculate class
        Calculate c = new Calculate();
        Calculate2 c2 = new Calculate2();
        // starting thread
        c.start(); // calls run method
        c2.start();
    }
}
