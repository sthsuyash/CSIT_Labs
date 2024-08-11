package org.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * Layout defines how the content should be present in window.
 * Following are the layout of the swing:
 * 1. flowlayout
 * 2. borderlayout
 * 3. gridlayout
 * 4. gridbaglayout
 * 5. cardlayout
 * 6. Null layout
 */

/**
 * Border layout places the content in terms of direction: north(top), south(bottom), west(left), east(right), center(middle)
 */

class BorderLayoutImpl extends JFrame{
    JButton button1, button2, button3, button4;
    JTextArea textArea1;

    public void setBorders(){
        button1 = new JButton("North");
        button2 = new JButton("South");
        button3 = new JButton("East");
        button4 = new JButton("West");

        textArea1 = new JTextArea(20, 20);
        setVisible(true);
        setSize(500, 500);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(3);
        add(button1, BorderLayout.NORTH);
        add(button2, BorderLayout.SOUTH);
        add(button3, BorderLayout.WEST);
        add(button4, BorderLayout.EAST);
        add(textArea1, BorderLayout.CENTER);

        button1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                textArea1.setText("North button is clicked.");
            }
        });

        button2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                textArea1.setText("South button is clicked.");
            }
        });

        button3.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                textArea1.setText("East button is clicked.");
            }
        });

        button4.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                textArea1.setText("West button is clicked.");
            }
        });
    }
}

public class BorderLayoutDemo {
    public static void main(String[] args) {
        BorderLayoutImpl border1 = new BorderLayoutImpl();
        border1.setBorders();
    }
}
