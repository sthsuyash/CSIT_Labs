package Unit8.RMI;

import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;

public class Server extends UnicastRemoteObject implements ServiceProvider {
    // It throws RemoteException because it extends UnicastRemoteObject => U
    public Server() throws RemoteException {}

    @Override
    public int findSum(int x, int y) throws Exception {
        return x + y;
    }

    @Override
    public boolean isPrime(int num) throws Exception {
        if (num <= 1) return false;
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        // creating server
        try {
            Registry registry = LocateRegistry.createRegistry(5050);
            // binding server
            registry.rebind("Server", new Server());
        } catch (RemoteException e) {
            System.out.println(e.getMessage());
        }
    }
}
