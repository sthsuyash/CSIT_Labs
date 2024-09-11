package Practical8.RMI3;

import java.rmi.registry.*;
import java.util.*;

public class Client {
    public static void main(String[] args) throws Exception {
        Registry registry = LocateRegistry.getRegistry(5000);
        ServiceProvider serviceProvider = (ServiceProvider) registry.lookup("Server");
        Scanner sc = new Scanner(System.in);

        System.out.println("******* Reverse String *******");
        System.out.print("Enter a string: ");
        String text = sc.nextLine();
        System.out.println(serviceProvider.reverse(text));

        System.out.println("\n******* Check Prime Number *******");
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        System.out.println(serviceProvider.findPrime(num));
    }
}
