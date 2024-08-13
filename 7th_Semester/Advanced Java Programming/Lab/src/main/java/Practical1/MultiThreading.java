package Practical1;

/**
 * Program for MultiThreading
 * MultiThreading is the ability of a CPU to execute multiple processes or threads concurrently.
 * In a single-core CPU, it is achieved by the CPU switching between different processes.
 * In a multi-core CPU, it is achieved by executing multiple threads concurrently.
 */
class MyThread extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Thread class: " + i);
        }
    }
}

class MyRunnable implements Runnable {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println("Runnable interface: " + i);
        }
    }
}

public class MultiThreading {
    public static void main(String[] args) {
        MyThread t1 = new MyThread();
        Thread t2 = new Thread(new MyRunnable());
        t1.start();
        t2.start();
    }
}
