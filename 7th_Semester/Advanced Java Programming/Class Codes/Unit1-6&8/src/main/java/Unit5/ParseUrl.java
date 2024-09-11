package Unit5;

import java.net.*;
import java.io.*;

public class ParseUrl {
    public static void main(String[] args) throws Exception {
        URL url = new URL("https://books.com:80/docs/books/tutorial" + "/index.html?name=networking#DOWNLOADING");

        // getProtocol(): returns the protocol identifier of the URL
        System.out.println("Protocol: " + url.getProtocol());

        // getAuthority(): returns the combination of host and port
        System.out.println("Authority: " + url.getAuthority());

        // getHost(): returns the host name of the URL
        System.out.println("Host: " + url.getHost());

        // getPort(): returns the port number of the URL.
        // It returns an integer value.
        // If the port is not set, it returns -1
        System.out.println("Port: " + url.getPort());

        // getPath(): returns the path of the URL
        System.out.println("Path: " + url.getPath());

        // getQuery(): returns the query string of the URL
        System.out.println("Query: " + url.getQuery());

        // getFile(): returns the filename of the URL
        // returns the same as getPath() + getQuery()
        System.out.println("Filename: " + url.getFile());

        // getRef(): returns the reference of the URL
        // i.e. the anchor part of the URL
        System.out.println("Ref: " + url.getRef());
    }
}
