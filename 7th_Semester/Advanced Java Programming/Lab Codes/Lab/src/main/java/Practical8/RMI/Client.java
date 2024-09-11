package Practical8.RMI;

import java.rmi.registry.*;
import java.util.*;

public class Client {
    public static void main(String[] args) throws Exception {
        Registry registry = LocateRegistry.getRegistry(5000);
        ServiceProvider serviceProvider = (ServiceProvider) registry.lookup("Server");
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the cost price: ");
        int CP = scanner.nextInt();
        System.out.print("Enter the discount: ");
        int discount = scanner.nextInt();

        int SP = serviceProvider.findSP(CP, discount);
        System.out.println("The selling price is: " + SP);
    }
}
