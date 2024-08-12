package Practical3;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class SumDifference extends JFrame {
    JTextField firstNumberField, secondNumberField, resultField;
    JLabel firstNumberLabel, secondNumberLabel, resultLabel;
    JTextArea textArea;

    public void setCalculator() {
        firstNumberLabel = new JLabel("First Number:");
        add(firstNumberLabel);
        firstNumberField = new JTextField(20);
        add(firstNumberField);

        secondNumberLabel = new JLabel("Second Number:");
        add(secondNumberLabel);
        secondNumberField = new JTextField(20);
        add(secondNumberField);

        resultLabel = new JLabel("Result:");
        add(resultLabel);
        resultField = new JTextField(20);
        resultField.setEditable(false);
        add(resultField);

        textArea = new JTextArea(5, 20);
        add(textArea);

        // mouse listener
       textArea.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                // Calculate and display the sum when the mouse is clicked
                try {
                    int num1 = Integer.parseInt(firstNumberField.getText());
                    int num2 = Integer.parseInt(secondNumberField.getText());
                    int sum = num1 + num2;
                    resultField.setText(String.valueOf(sum));
                } catch (NumberFormatException ex) {
                    resultField.setText("Please enter valid numbers.");
                }
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                // Calculate and display the difference when the mouse is released
                try {
                    int num1 = Integer.parseInt(firstNumberField.getText());
                    int num2 = Integer.parseInt(secondNumberField.getText());
                    int difference = num1 - num2;
                    resultField.setText(String.valueOf(difference));
                } catch (NumberFormatException ex) {
                    resultField.setText("Please enter valid numbers.");
                }
            }
        });

        setVisible(true);
        setTitle("Sum and Difference Calculator");
        setSize(300, 150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
    }
}

public class SumDifferenceCalculator {
    public static void main(String[] args) {
       SumDifference sd = new SumDifference();
       sd.setCalculator();
    }
}
