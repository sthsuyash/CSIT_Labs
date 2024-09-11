package Unit1.Files;

import java.io.*;

public class CharacterStream {
    public static void main(String[] args) throws Exception {
        try {
            FileReader in = new FileReader("source.txt");
            FileWriter out = new FileWriter("destination.txt");
            int charData;

            while (true) {
                charData = in.read();
                if (charData == -1) {
                    break;
                } else {
                    out.write(charData);
                }
            }
            in.close();
            out.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}
