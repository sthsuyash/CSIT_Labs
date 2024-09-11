package Practical3.KeyEvents;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

class KeyEventImpl2 extends JFrame{
    JLabel label;
    JTextArea textArea;

    public void setKeyEventImpl(){
        label = new JLabel("Result");
        textArea = new JTextArea(20, 20);

        textArea.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                super.keyTyped(e);
            }

            @Override
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
            }

            @Override
            public void keyReleased(KeyEvent e) {
                super.keyReleased(e);
            }
        });

        add(label);
        add(textArea);
        setVisible(true);
        setDefaultCloseOperation(3);
        setTitle("Key Event Using Delegation");
        setSize(500, 500);
        setLayout(new FlowLayout());
    }
}

public class KeyEventUsingDelegation {
    public static void main(String[] args) {
        KeyEventImpl2 keyEventImpl = new KeyEventImpl2();
        keyEventImpl.setKeyEventImpl();
    }
}