package Unit8.RMI;

import java.rmi.*;
import java.rmi.registry.*;
import java.util.*;

public class Client {
    public static void main(String[] args) throws Exception {
        // invoking the server
        Registry registry = LocateRegistry.getRegistry(5000);
        // invoke service provider
        ServiceProvider serviceProvider = (ServiceProvider) registry.lookup("Server");

        System.out.println("****** Calculate Sum ******");
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int x = sc.nextInt();
        System.out.print("Enter second number: ");
        int y = sc.nextInt();
        System.out.println("Sum: " + serviceProvider.findSum(x, y));

        System.out.println("****** Check Prime ******");
        System.out.print("Enter a number: ");
        int num = sc.nextInt();
        String pc = serviceProvider.isPrime(num) ? "Prime" : "Not Prime";
        System.out.println(pc);
        System.out.println("***************************");
    }
}
