package Unit5.TCP;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Network program deals with sending and receiving data from network.                 *
 * Here client is known as socket and server is known as serversocket.                 *
 * In UDP, both client and server is treated as datagramsocket  and                    *
 * data of UDP is known as datagram (send in byte).                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Steps to create TCP client server:                                                  *
 * 1. Create server by registering port and provide service.                           *
 * 2. Create client by invoking address and port of server and send request to server. *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * To use network, java.net package
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

// to use network, java.net package should be imported.

import java.net.*;
import java.io.*;

public class TcpServer {
    private Socket client; // client to connect with server
    private ServerSocket server;
    private DataInputStream input; // to take data from client

    // create constructor to connect with client
    public TcpServer(int port) {
        try {
            server = new ServerSocket(port); // port ready
            System.out.println("Server is ready.");
            System.out.println("Waiting for client.");

            // connecting server and client
            client = server.accept();

            // extract data from client
            input = new DataInputStream(new BufferedInputStream(client.getInputStream()));

            // provide intended service
            // provide string reverse service
            String text = "";
            while (!text.equals("out")) {
                text = input.readUTF(); // read string
                System.out.println("Client says " + text);
                System.out.println("Reverse form of client data: ");

                String reverse = "";
                for (int i = 0; i < text.length(); i++) {
                    reverse = text.charAt(i) + reverse;
                }
                System.out.println(reverse);
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        TcpServer tcpServer = new TcpServer(5000);
    }
}
