package Unit1.Files;

import java.io.*;

public class ByteStream {
    public static void main(String[] args) {
        try {
            FileInputStream fis = new FileInputStream("source.txt");
            FileOutputStream ois = new FileOutputStream("destination.txt");

            String s = "";
            int i = 0;

            while (true) {
                i = fis.read();
                if (i == -1) {
                    break;
                } else {
                    s = s + (char) i;
                }
            }

            byte b[] = s.getBytes();
            
            ois.write(b);

            fis.close();
            ois.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
