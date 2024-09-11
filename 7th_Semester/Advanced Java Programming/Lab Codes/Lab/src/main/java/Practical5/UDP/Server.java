package Practical5.UDP;

import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws IOException {
        // Create a socket to listen at port 9876
        DatagramSocket serverSocket = new DatagramSocket(9876);
        byte[] receiveData = new byte[1024];
        byte[] sendData = new byte[1024];

        System.out.println("Server is running...");

        while (true) {
            // Receive packet from client
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            serverSocket.receive(receivePacket);

            // Convert the received data into a string
            String numberString = new String(receivePacket.getData(), 0, receivePacket.getLength());
            int number = Integer.parseInt(numberString);

            // Determine if the number is even or odd
            String result;
            if (number % 2 == 0) {
                result = "The number " + number + " is Even.";
            } else {
                result = "The number " + number + " is Odd.";
            }

            // Send the result back to the client
            InetAddress clientAddress = receivePacket.getAddress();
            int clientPort = receivePacket.getPort();
            sendData = result.getBytes();

            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, clientAddress, clientPort);
            serverSocket.send(sendPacket);
        }
    }
}
