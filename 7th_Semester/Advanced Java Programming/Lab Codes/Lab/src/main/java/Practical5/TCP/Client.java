package Practical5.TCP;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
        // Create a socket to connect to the server
        Socket clientSocket = new Socket("localhost", 6789);

        // Set up input and output streams
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

        // Get input from the user
        System.out.print("Enter message to send to server: ");
        String sentence = inFromUser.readLine();

        // Send input to server
        outToServer.writeBytes(sentence + "\n");

        // Receive and print response from server
        String response = inFromServer.readLine();
        System.out.println("Response from server: " + response);

        // Close the socket
        clientSocket.close();
    }
}
