package Practical3;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;

class ListSelectionImpl extends JFrame {
    private JList<String> list;
    private JLabel label;

    public void showList() {
        String[] items = {"Item 1", "Item 2", "Item 3", "Item 4"};
        list = new JList<>(items);
        list.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    label.setText("Selected: " + list.getSelectedValue());
                }
            }
        });

        add(list);
        label = new JLabel("Selected: None");
        add(label);

        setVisible(true);
        setTitle("List Selection Event Demo");
        setSize(300, 150);
        setDefaultCloseOperation(3);
        setLayout(new FlowLayout());
    }
}

public class ListSelectionEventDemo {
    public static void main(String[] args) {
        ListSelectionImpl impl = new ListSelectionImpl();
        impl.showList();
    }
}
