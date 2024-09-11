package Practical5.TCP;

import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws IOException {
        // Create server socket on port 6789
        ServerSocket serverSocket = new ServerSocket(6789);
        System.out.println("Sever waiting for client");

        // Wait for a client to connect
        Socket connectionSocket = serverSocket.accept();
        System.out.println("Client connected");

        // Setup input and output streams
        BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
        DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());

        // Read client input
        String clientInput = inFromClient.readLine();
        System.out.println("Received from client: " + clientInput);

        // Process input and send response
        if(clientInput.equalsIgnoreCase("Hello")){
            outToClient.writeBytes("Welcome\n");
        }
        else{
            outToClient.writeBytes("Error in input\n");
        }

        // Close connection
        connectionSocket.close();
        serverSocket.close();
    }
}
