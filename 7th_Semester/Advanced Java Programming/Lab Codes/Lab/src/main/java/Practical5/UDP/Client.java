package Practical5.UDP;

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        // Create a socket for communication
        DatagramSocket clientSocket = new DatagramSocket();
        InetAddress IPAddress = InetAddress.getByName("localhost");

        // Prepare input and output buffers
        byte[] sendData = new byte[1024];
        byte[] receiveData = new byte[1024];

        // Get number from the user
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        String number = scanner.nextLine();

        // Send the number to the server
        sendData = number.getBytes();
        DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 9876);
        clientSocket.send(sendPacket);

        // Receive the server's response
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
        clientSocket.receive(receivePacket);

        // Print the server's response
        String serverResponse = new String(receivePacket.getData(), 0, receivePacket.getLength());
        System.out.println("Server Response: " + serverResponse);

        // Close the socket
        clientSocket.close();
    }
}
