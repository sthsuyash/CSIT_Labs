package Unit5.UDP;

// Here, in UDP client is also refer as datagramSocket

import java.net.*;
import java.util.*;

public class UDPClient {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);

            // Creating socket for carrying data
            DatagramSocket ds = new DatagramSocket();
            InetAddress ip = InetAddress.getLocalHost();
            byte[] buff = null;

            // Accept input till out is type
            System.out.println("Enter any thing you want to send");
            System.out.println("Enter out to end ");
            while (true) {
                String str = sc.nextLine();
                buff = str.getBytes(); // Extracting byte from string value
                // Create packet for sending data
                DatagramPacket pkt = new DatagramPacket(buff, buff.length, ip, 1234);
                // Sending data using send()
                ds.send(pkt);
                if (str.equals("out")) {
                    break;
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}