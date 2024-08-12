package Unit2;

/**
 * Layout determines how the content should be viewed in window. Following are the layout of swing
 * 1.Flow layout
 * 2.Brder Layout
 * 3.Grid Layout
 * 4.Grid Bag layout
 * 5.CardLayout
 * 6.Null Layout
 * <p>
 * Border layout: place the content in terms of direction: north (top), south (bottom), west (left), east (right), center
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Border extends JFrame {
    JButton button1, button2, button3, button4;
    JTextArea textArea1;

    public void setBorder() {
        button1 = new JButton("North Button");
        button2 = new JButton("South Button");
        button3 = new JButton("East Button");
        button4 = new JButton("West Button");
        textArea1 = new JTextArea(20, 20);

        setVisible(true);
        setSize(400, 400);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(3);

        //adding component into border
        add(button1, BorderLayout.NORTH);
        add(button2, BorderLayout.SOUTH);
        add(button3, BorderLayout.EAST);
        add(button4, BorderLayout.WEST);
        add(textArea1, BorderLayout.CENTER);

        //after button is clicked
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent a) {
                textArea1.setText("North button is clicked");
            }
        });

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea1.setText("South button is clicked.");
            }
        });

        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea1.setText("East button is clicked.");
            }
        });

        button4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea1.setText("West button is clicked.");
            }
        });
    }
}

public class BorderLayoutDemo {
    public static void main(String[] args) {
        Border b1 = new Border();
        b1.setBorder();
    }
}