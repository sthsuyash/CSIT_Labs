package Unit3.Adapters;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

class KeyAdapterImpl extends JFrame {
    JLabel label1;
    JTextArea textArea1;

    public void setKeyAdapterImpl() {
        label1 = new JLabel("Result");
        textArea1 = new JTextArea(20, 20);

        textArea1.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                label1.setText("Key Typed: " + e.getKeyChar());
            }
        });

        add(label1);
        add(textArea1);
        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
        setLayout(new FlowLayout());
    }
}

public class KeyAdapterDemo {
    public static void main(String[] args) {
        KeyAdapterImpl keyAdapterImpl = new KeyAdapterImpl();
        keyAdapterImpl.setKeyAdapterImpl();
    }
}
