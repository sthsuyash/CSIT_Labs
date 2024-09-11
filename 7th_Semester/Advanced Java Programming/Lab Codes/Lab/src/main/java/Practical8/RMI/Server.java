package Practical8.RMI;

import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;

public class Server extends UnicastRemoteObject implements ServiceProvider {
    public Server() throws RemoteException {}

    @Override
    public int findSP(int CP, int discount) throws Exception {
        return CP - discount;
    }

    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.createRegistry(5000);
            registry.rebind("Server", new Server());
        } catch (RemoteException e) {
            System.out.println(e.getMessage());
        }
    }
}
