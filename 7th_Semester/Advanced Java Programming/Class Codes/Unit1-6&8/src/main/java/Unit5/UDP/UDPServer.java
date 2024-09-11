package Unit5.UDP;

import java.net.*;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Network programming shows how data are transmitted in network using UDP and TCP.          *
 * In UDP, packet are transmitted in form of datagram.                                       *
 * In Network Programming, client is known as socket and server is known as socketserver.    *
 * Both client and server is known as DataGramSocket, and packet is known as datagrampacket. *
 * We need to import java.net package for Network programming.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */
public class UDPServer {
    public static void main(String[] args) {
        // Creating socket to listen on port 1234
        try {
            DatagramSocket sc = new DatagramSocket(1234);
            // In UDP data should be sent in form of byte
            byte[] rcv = new byte[6000];
            // Datagram packet: packet for UDP
            DatagramPacket rc = null;
            System.out.println("Server started");
            System.out.println("Waiting for client");
            while (true) {
                // Creating packet to receive data
                rc = new DatagramPacket(rcv, rcv.length);
                // Receiving data
                sc.receive(rc);
                // rcv is sent as parameter to method data which will convert byte to string
                System.out.println("Client: " + data(rcv));
                // exit server if out is received
                if (data(rcv).toString().equals("out")) {
                    System.out.println("Client sent out so exiting server");
                    break;
                }
                // clearing buffer
                rcv = new byte[6000];
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * * * * * * * * * * * * * * * * * *
     * Converting byte array to string *
     * * * * * * * * * * * * * * * * * *
     */
    public static StringBuilder data(byte[] a) {
        if (a == null) {
            return null;

        }
        StringBuilder build = new StringBuilder();
        int i = 0;
        while (a[i] != 0) {
            build.append((char) a[i]);
            i++;
        }
        return build;
    }
}