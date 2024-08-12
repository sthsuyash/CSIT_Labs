package Practical3;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class FocusEventImpl extends JFrame {
    private JTextField textField1, textField2;
    private JLabel label;

    public void setFocus() {
        textField1 = new JTextField(20);
        textField1.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                label.setText("Focus Gained on Text Field 1");
            }

            @Override
            public void focusLost(FocusEvent e) {
                label.setText("Focus Lost on Text Field 1");
            }
        });

        textField2 = new JTextField(20);
        textField2.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                label.setText("Focus Gained on Text Field 2");
            }

            @Override
            public void focusLost(FocusEvent e) {
                label.setText("Focus Lost on Text Field 2");
            }
        });

        label = new JLabel("Focus on a text field");
        add(label);

        add(textField1);
        add(textField2);

        setVisible(true);
        setTitle("Focus Event Demo");
        setSize(300, 150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
    }
}

public class FocusEventDemo {
    public static void main(String[] args) {
        FocusEventImpl impl = new FocusEventImpl();
        impl.setFocus();
    }
}
