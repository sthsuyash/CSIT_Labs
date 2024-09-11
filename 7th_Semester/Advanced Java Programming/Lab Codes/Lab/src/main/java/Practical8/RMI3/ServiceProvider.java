package Practical8.RMI3;

import java.rmi.*;

public interface ServiceProvider extends Remote {
    String reverse(String text) throws Exception;
    String findPrime(int num) throws Exception;
}
