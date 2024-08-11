package org.example;
import javax.swing.*;
import java.awt.GridLayout;

/**
 * Places the content in form of row and columns i.e. like table format
 */


class Grid extends JFrame {
    JButton button1, button2, button3, button4, button5;
    JTextArea textArea1;

    public void setGrid() {
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        button3 = new JButton("Button 3");
        button4 = new JButton("Button 4");
        button5 = new JButton("Button 5");

        textArea1 = new JTextArea(10, 5);
        add(button1);
        add(button2);
        add(button3);
        add(button4);
        add(button5);
        add(textArea1);

        setVisible(true);
        setSize(400, 400);
        setLayout(new GridLayout(3, 2));
        setDefaultCloseOperation(3);
    }
}

public class GridLayoutDemo {
    public static void main(String[] args) {
        Grid grid = new Grid();
        grid.setGrid();
    }
}
