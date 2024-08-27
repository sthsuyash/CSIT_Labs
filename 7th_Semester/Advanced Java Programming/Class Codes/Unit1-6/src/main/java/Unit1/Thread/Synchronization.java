package Unit1.Thread;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Synchronization                                                                                           *
 *-----------------------------------------------------------------------------------------------------------*
 * Synchronization is a mechanism that ensures that only one thread can access a shared resource at a time.  *
 * This is crucial when multiple threads might try to modify the same resource concurrently, leading to      *
 * potential inconsistencies or corruption.                                                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * There are several ways to achieve synchronization in Java:                                                *
 * 1. Synchronized Methods: By declaring a method as `synchronized`, it ensures that only one thread can     *
 *    execute that method at a time on the same object.                                                      *
 * 2. Synchronized Blocks: Allows finer control by synchronizing only a specific block of code rather than   *
 *    the entire method.                                                                                     *
 * 3. Locks: Using explicit lock objects from the `java.util.concurrent.locks` package for advanced control. *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class PrintTable{
    public synchronized void printTable(int n){
        System.out.println("Table of " + n + ":");
        for (int i = 1; i <= 5; i++){
            System.out.println(n * i);
            try {
                Thread.sleep(400);
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}

class MyThread1 extends Thread{
    PrintTable pt;
    MyThread1(PrintTable pt){
        this.pt = pt;
    }

    public void run(){
        pt.printTable(5);
    }
}

class MyThread2 extends Thread{
    PrintTable pt;
    MyThread2(PrintTable pt){
        this.pt = pt;
    }

    public void run(){
        pt.printTable(100);
    }
}

public class Synchronization {
    public static void main(String[] args) {
        PrintTable pt = new PrintTable();
        MyThread1 t1 = new MyThread1(pt);
        MyThread2 t2 = new MyThread2(pt);
        t1.start();
        t2.start();
    }
}
