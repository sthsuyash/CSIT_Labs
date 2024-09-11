package Unit5.TCP;

import java.net.*;
import java.io.*;

public class TcpClient {
    private Socket socket;
    private DataInputStream inputStream; // to input data
    private DataOutputStream outputStream; // to output data

    public TcpClient(String address, int port){
        try{
            socket = new Socket(address, port);
            System.out.println("Client ready.");
            System.out.println("Send any string and press out to end.");

            inputStream = new DataInputStream(System.in);
            outputStream = new DataOutputStream(socket.getOutputStream());

            // take input from user and send to server
            String str = "";
            while(!str.equals("out")){
                str = inputStream.readLine(); // reading from console
                outputStream.writeUTF(str); // writing to client
                outputStream.flush(); // memory flush
            }
            inputStream.close();
            outputStream.close();
            socket.close();
        }
        catch ( IOException e){
            System.out.println(e.getMessage());
        }
    }

    public static void main(String[] args) {
        TcpClient client = new TcpClient("localhost",5000);
    }
}
