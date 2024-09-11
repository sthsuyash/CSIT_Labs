package Unit1.Thread;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Multithreading in Java                                                                                  *
 *---------------------------------------------------------------------------------------------------------*
 * Multithreading is a mechanism that allows a program to perform multiple tasks simultaneously.           *
 * In Java, multithreading can be achieved in two ways:                                                    *
 * 1. By implementing the `Runnable` interface.                                                            *
 * 2. By extending (inheriting) the `Thread` class.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * When a Java program is created, one thread is always running. This thread is known as the main thread.  *
 * To execute a thread, the `run()` method is used.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

public class ThreadDemo {
    public static void main(String[] args) {
        // main thread
        // extracting current thread
        Thread t1 = Thread.currentThread();

        /** Get Set name **/
        t1.setName("CSIT");
        System.out.println("Name of thread is: " + t1.getName());
        /** get priority **/
        t1.getPriority();

        /** Get priority **/
        // it is 5 by default
        System.out.println("Priority is: " + t1.getPriority());
        /** Setting priority **/
        t1.setPriority(2);
        System.out.println("New priority is: " + t1.getPriority());

        /** Checking if thread is alive **/
        System.out.println("State is: " + t1.getState());

        /** Suspending thread **/
        // displaying data 10 times by suspending one second
        try {
            for (int i = 0; i < 10; i++) {
                System.out.println("This is main thread");
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            // InterruptedException occurs when a thread is waiting, sleeping, or doing some work,
            // and another thread interrupts it using the interrupt() method in the Thread class.
            System.out.println(e.getMessage());
        }

    }
}
