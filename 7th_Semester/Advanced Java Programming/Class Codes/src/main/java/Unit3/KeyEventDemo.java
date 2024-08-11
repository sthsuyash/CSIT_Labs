package Unit3;

/**
 * KeyEvent is generated when any key is pressed or released.
 * To handle KeyEvent, KeyListener is used.
 * The three methods of KeyListener interface are:
 * 1. keyTyped(KeyEvent e)
 * 2. keyPressed(KeyEvent e)
 * 3. keyReleased(KeyEvent e)
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class KeyEventImpl extends JFrame {
    JLabel label1;
    JTextArea textArea1;

    public void setKeyEventImpl() {
        label1 = new JLabel("Result");
        textArea1 = new JTextArea(20, 20);

        textArea1.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {
                label1.setText("Key Typed: " + e.getKeyChar());
            }

            @Override
            public void keyPressed(KeyEvent e) {
                label1.setText("Key Pressed: " + e.getKeyChar());
            }

            @Override
            public void keyReleased(KeyEvent e) {
                label1.setText("Key Released: " + e.getKeyChar());
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

public class KeyEventDemo {
    public static void main(String[] args) {
        KeyEventImpl keyEventImpl = new KeyEventImpl();
        keyEventImpl.setKeyEventImpl();
    }
}
