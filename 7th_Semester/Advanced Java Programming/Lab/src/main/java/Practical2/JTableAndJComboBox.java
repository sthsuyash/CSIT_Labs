package Practical2;

import javax.swing.*;
import java.awt.*;

class JTableImpl extends JFrame {
    JTable table1;
    JComboBox<String> combobox;

    public void setTable() {
        String[] col = {"id", "name", "faculty"};
        String[][] data = {{"1", "Ram", "BCA"},
                {"2", "Hari", "CSIT"},
                {"3", "Sita", "BBA"},
                {"4", "Rita", "BIM"},
                {"5", "Ramda", "BCA"},
        };

        // creating table
        table1 = new JTable(data, col);
        table1.setPreferredScrollableViewportSize(new Dimension(500, 100));

        // adding scrollbar in table
        JScrollPane scrollPane = new JScrollPane(table1);
        // adding scrollbar in frame
        add(scrollPane);

        // creating combobox
        combobox = new JComboBox<>(new String[]{"Nepal", "India", "USA", "UK"});
        add(combobox);

        setVisible(true);
        setSize(500, 500);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(3);
    }
}

public class JTableAndJComboBox {
    public static void main(String[] args) {
        JTableImpl jtable = new JTableImpl();
        jtable.setTable();
    }
}
