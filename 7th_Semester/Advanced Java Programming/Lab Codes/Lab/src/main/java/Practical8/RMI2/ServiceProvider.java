package Practical8.RMI2;

import java.rmi.*;

public interface ServiceProvider extends Remote{
    int product(int x, int y) throws Exception;
}
