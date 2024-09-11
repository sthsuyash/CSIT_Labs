package Unit2.Layouts;

import javax.swing.*;
import java.awt.*;

/**
 * GroupLayout groups its components and places them in a Container hierarchically.
 * The grouping is done by instances of the Group class. For the components, GroupLayout provides two types of groups: sequential and parallel.
 * 1. Sequential groups are groups of components that are placed one after another.
 * 2. Parallel groups are groups of components that are placed at the same place.
 */

class GroupLayoutImpl extends JFrame {
    JButton button1, button2, button3, button4;
    JTextArea textArea;

    public void setGroupLayout() {
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        button3 = new JButton("Button 3");
        button4 = new JButton("Button 4");
        textArea = new JTextArea(10, 5);
        textArea.setText("This is a text area");

        GroupLayout layout = new GroupLayout(getContentPane());
        getContentPane().setLayout(layout);

        layout.setAutoCreateGaps(true);
        layout.setAutoCreateContainerGaps(true);

        layout.setHorizontalGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(button1)
                        .addComponent(button3))
                .addGroup(layout.createParallelGroup(GroupLayout.Alignment.LEADING)
                        .addComponent(button2)
                        .addComponent(button4))
                .addComponent(textArea)
        );

        layout.setVerticalGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE)
                        .addComponent(button1)
                        .addComponent(button2))
                .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE)
                        .addComponent(button3)
                        .addComponent(button4))
                .addComponent(textArea)
        );

        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
    }
}

public class GroupLayoutDemo {
    public static void main(String[] args) {
        GroupLayoutImpl impl = new GroupLayoutImpl();
        impl.setGroupLayout();
    }
}
