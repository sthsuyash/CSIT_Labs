package Practical8.RMI;

import java.rmi.*;

public interface ServiceProvider extends Remote {
    int findSP(int CP, int discount) throws Exception;
}
