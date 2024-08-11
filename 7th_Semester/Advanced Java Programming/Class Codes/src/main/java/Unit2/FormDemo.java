package Unit2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Form extends JFrame {
    JLabel label1, label2, label3;
    JTextField textField1, textField2;
    JButton button1, button2;

    public void setForm() {
        // Creating labels
        label1 = new JLabel("Enter First Number");
        label2 = new JLabel("Enter Second Number");
        label3 = new JLabel("Result");

        // Creating text fields
        textField1 = new JTextField(20);
        textField2 = new JTextField(20);

        // Creating button
        button1 = new JButton("Add");
        button2 = new JButton("Subtract");
        add(label1);
        add(textField1);
        add(label2);
        add(textField2);
        add(button1);
        add(button2);
        add(label3);

        setVisible(true);
        setSize(500, 500);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(3); // 3 is for exit on close => JFrame.EXIT_ON_CLOSE

        /**
         * When button is pressed, it will generate event known as ActionEvent.
         * To handle any event listener is used.
         * Listener is interface, so we have to use all the methods of listener.
         * It contains actionPerformed method which should be overridden
         */
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // extract form field
                int num1 = Integer.parseInt(textField1.getText());
                int num2 = Integer.parseInt(textField2.getText());

                int sum = num1 + num2;
                label3.setText("Sum is: " + sum);
            }
        });

        // for second button to perform subtraction
        button2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                int num1 = Integer.parseInt(textField2.getText());
                int num2 = Integer.parseInt(textField1.getText());

                int diff = num1 - num2;
                label3.setText("Difference is: " + diff);
            }
        });
    }
}

public class FormDemo {
    public static void main(String[] args) {
        Form form = new Form();
        form.setForm();
    }
}
