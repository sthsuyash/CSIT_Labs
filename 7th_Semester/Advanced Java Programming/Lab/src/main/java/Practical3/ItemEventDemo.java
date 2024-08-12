package Practical3;

import javax.swing.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

class ItemEventImpl extends JFrame {
    private JCheckBox checkBox1, checkBox2;
    private JLabel label;

    public void setItem() {
        // Frame settings
        setTitle("Item Event Demo");
        setSize(300, 150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(null);

        // Checkboxes
        checkBox1 = new JCheckBox("Check 1");
        checkBox1.setBounds(10, 10, 100, 30);
        checkBox1.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                String selected = "Selected: ";
                if (checkBox1.isSelected()) selected += "Check 1 ";
                if (checkBox2.isSelected()) selected += "Check 2 ";
                if (!checkBox1.isSelected() && !checkBox2.isSelected()) selected = "Selected: None";
                label.setText(selected);
            }
        });

        checkBox2 = new JCheckBox("Check 2");
        checkBox2.setBounds(10, 40, 100, 30);
        checkBox2.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                String selected = "Selected: ";
                if (checkBox1.isSelected()) selected += "Check 1 ";
                if (checkBox2.isSelected()) selected += "Check 2 ";
                if (!checkBox1.isSelected() && !checkBox2.isSelected()) selected = "Selected: None";
                label.setText(selected);
            }
        });

        // Label to display selected checkboxes
        label = new JLabel("Selected: None");
        label.setBounds(10, 70, 200, 30);

        // Add components to frame
        add(checkBox1);
        add(checkBox2);
        add(label);

        // Display the frame
        setVisible(true);
    }
}

public class ItemEventDemo {
    public static void main(String[] args) {
        ItemEventImpl impl = new ItemEventImpl();
        impl.setItem();
    }
}
