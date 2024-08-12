package Practical2;

/**
 * Write a program to demonstrate different layout manager (null, flow layout, card layout,
 * border layout, grid layout, grid bag layout and group layout)
 */

import javax.swing.*;
import java.awt.*;

class LayoutImpl extends JFrame {
    JButton button1, button2;

    public void setNullLayout() {
        button1 = new JButton("Button 1");
        add(button1);
        setVisible(true);
        setSize(200, 200);
        setDefaultCloseOperation(3);
        setLayout(null);

        button1.setBounds(50, 50, 100, 30);
    }

    public void setFlowLayout() {
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        add(button1);
        add(button2);
        setVisible(true);
        setSize(200, 200);
        setDefaultCloseOperation(3);
        setLayout(new FlowLayout());
    }

    public void setCardLayout() {
        CardLayout cardLayout = new CardLayout();
        setLayout(cardLayout);
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        JButton button3 = new JButton("Button 3");
        add(button1, "1");
        add(button2, "2");
        add(button3, "3");
        cardLayout.show(this.getContentPane(), "1");

        setVisible(true);
        setSize(200, 200);
        setDefaultCloseOperation(3);
    }

    public void setBorderLayout() {
        JButton button1 = new JButton("North Button");
        JButton button2 = new JButton("South Button");
        JButton button3 = new JButton("East Button");
        JButton button4 = new JButton("West Button");
        JTextArea textArea1 = new JTextArea(20, 20);
        add(button1, BorderLayout.NORTH);
        add(button2, BorderLayout.SOUTH);
        add(button3, BorderLayout.EAST);
        add(button4, BorderLayout.WEST);
        add(textArea1, BorderLayout.CENTER);

        setSize(400, 400);
        setVisible(true);
        setDefaultCloseOperation(3);
        setLayout(new BorderLayout());
    }

    public void setGridLayout() {
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        JButton button3 = new JButton("Button 3");
        JButton button4 = new JButton("Button 4");
        JButton button5 = new JButton("Button 5");
        JTextArea textArea = new JTextArea(10, 5);
        textArea.setText("This is a text area");
        add(button1);
        add(button2);
        add(button3);
        add(button4);
        add(button5);
        add(textArea);
        setLayout(new GridLayout(2, 3));
        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
    }

    public void setGridBagLayout() {
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        JButton button3 = new JButton("Button 3");
        GridBagLayout gridBagLayout = new GridBagLayout();
        GridBagConstraints gridBagConstraints = new GridBagConstraints();

        setVisible(true);
        setSize(500, 500);
        setLayout(new GridBagLayout());
        setDefaultCloseOperation(3);

        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button1, gridBagConstraints);
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button2, gridBagConstraints);
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 2;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button3, gridBagConstraints);
    }

    public void setGroupLayout() {
        GroupLayout groupLayout = new GroupLayout(getContentPane());
        getContentPane().setLayout(groupLayout);
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        JButton button3 = new JButton("Button 3");
        JButton button4 = new JButton("Button 4");
        JButton button5 = new JButton("Button 5");
        JTextArea textArea = new JTextArea(10, 5);
        textArea.setText("This is a text area");
        groupLayout.setHorizontalGroup(groupLayout.createSequentialGroup()
                .addGroup(groupLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(button1)
                        .addComponent(button4))
                .addGroup(groupLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(button2)
                        .addComponent(button5))
                .addGroup(groupLayout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(button3)
                        .addComponent(textArea)));
        groupLayout.setVerticalGroup(groupLayout.createSequentialGroup()
                .addGroup(groupLayout.createParallelGroup(GroupLayout.Alignment.BASELINE)
                        .addComponent(button1)
                        .addComponent(button2)
                        .addComponent(button3))
                .addGroup(groupLayout.createParallelGroup(GroupLayout.Alignment.BASELINE)
                        .addComponent(button4)
                        .addComponent(button5)
                        .addComponent(textArea)));
        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
    }

}

public class LayoutManager {
    public static void main(String[] args) {
        LayoutImpl impl = new LayoutImpl();

//        impl.setNullLayout();
//        impl.setFlowLayout();
//        impl.setCardLayout();
//        impl.setBorderLayout();
//        impl.setGridLayout();
//        impl.setGridBagLayout();
        impl.setGroupLayout();
    }
}
