package Practical3;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class ActionEventImpl extends JFrame {
    private JRadioButton radioButton1, radioButton2;
    private JButton button;
    private JTextField textField;

    public void handle() {
        textField = new JTextField(20);
        add(textField);

        // Radio Buttons and Button (Action Event)
        radioButton1 = new JRadioButton("Option 1");
        radioButton2 = new JRadioButton("Option 2");
        ButtonGroup group = new ButtonGroup();
        group.add(radioButton1);
        group.add(radioButton2);

        radioButton1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textField.setText("Radio Button 1 Selected");

            }
        });

        radioButton2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textField.setText("Radio Button 2 Selected");
            }
        });

        add(radioButton1);
        add(radioButton2);

        // Button
        button = new JButton("Click Me");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textField.setText("Button Clicked!");
            }
        });
        add(button);

        setVisible(true);
        setTitle("Action Event Handling Demo");
        setSize(600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
    }
}

public class ActionEventDemo {
    public static void main(String[] args) {
        ActionEventImpl impl = new ActionEventImpl();
        impl.handle();
    }
}
