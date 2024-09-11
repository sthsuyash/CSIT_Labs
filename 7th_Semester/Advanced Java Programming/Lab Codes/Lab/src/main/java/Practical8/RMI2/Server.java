package Practical8.RMI2;

import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;

public class Server extends UnicastRemoteObject implements ServiceProvider{
    public Server() throws RemoteException {}

    @Override
    public int product(int x, int y) throws Exception{
        return x * y;
    }

    public static void main(String[] args) {
        try{
            Registry registry = LocateRegistry.createRegistry(5000);
            registry.rebind("Server", new Server());
        }catch(RemoteException e){
            System.out.println(e.getMessage());
        }
    }
}
