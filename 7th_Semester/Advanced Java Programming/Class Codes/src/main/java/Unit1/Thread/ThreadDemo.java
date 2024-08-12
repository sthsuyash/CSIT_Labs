package Unit1.Thread;

/**
 * Multithreading is a mechanism by which program can do multiple work at the same time.
 * In java, multithreading can be achieved using two ways:
 * 1. By implementing runnable interface
 * 2. By extending (inheriting) thread class
 * <p>
 * One thread is always running when program is created
 * this thread is known as main thread
 * to execute thread run() method is used
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
