package Unit8.RMI;

import java.rmi.*;

public interface ServiceProvider extends Remote {
    // first service: send two number return sum
    int findSum(int x, int y) throws Exception;

    // second service: return whether given number is prime or not
    boolean isPrime(int num) throws Exception;
}
