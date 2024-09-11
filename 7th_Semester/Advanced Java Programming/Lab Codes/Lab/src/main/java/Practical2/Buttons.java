package Practical2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class ButtonClickDemo extends JFrame {
    private JTextField textField;
    private JButton button1, button2, button3, button4;

    public void setButtonClickDemo() {
        // Creating the text field
        textField = new JTextField(25);
        textField.setEditable(false); // Make the text field non-editable

        // Creating buttons
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        button3 = new JButton("Button 3");
        button4 = new JButton("Button 4");

        // Create a GridBagLayout with buttons below the text field
        GridBagLayout gridBagLayout = new GridBagLayout();
        GridBagConstraints gridBagConstraints = new GridBagConstraints();

        setVisible(true);
        setTitle("Button Click Demo");
        setSize(400, 200);
        setLayout(new GridBagLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        // setting layout of text field at (0, 0)
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.gridwidth = 4;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(textField, gridBagConstraints);

        // setting layout of button1 at (0, 1)
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 1;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button1, gridBagConstraints);

        // setting layout of button2 at (1, 1)
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 1;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button2, gridBagConstraints);

        // setting layout of button3 at (2, 1)
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 1;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button3, gridBagConstraints);

        // setting layout of button4 at (3, 1)
        gridBagConstraints.gridx = 3;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 1;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button4, gridBagConstraints);

        // Adding action listeners to the buttons
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textField.setText("First button is clicked");
            }
        });

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textField.setText("Second button is clicked");
            }
        });

        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textField.setText("Third button is clicked");
            }
        });

        button4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textField.setText("Fourth button is clicked");
            }
        });
    }
}

public class Buttons {
    public static void main(String[] args) {
        ButtonClickDemo buttonClickDemo = new ButtonClickDemo();
        buttonClickDemo.setButtonClickDemo();
    }
}
