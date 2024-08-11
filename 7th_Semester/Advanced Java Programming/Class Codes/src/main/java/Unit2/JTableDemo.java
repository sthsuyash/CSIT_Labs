package Unit2;

/**
 * JTable: It is used to display data in tabular form, i.e. rows and columns.
 * To create JTable, its object is created and parameter accepting data and column of table
 */

import javax.swing.*;
import java.awt.*;

class JTableImpl extends JFrame {
    JTable table1;


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
        table1.setPreferredScrollableViewportSize(new Dimension(500, 40));

        // adding scrollbar in table
        JScrollPane scrollPane = new JScrollPane(table1);
        // adding scrollbar in frame
        add(scrollPane);

        setVisible(true);
        setSize(500, 500);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(3);
    }

}

public class JTableDemo {
    public static void main(String[] args) {
        JTableImpl jtable = new JTableImpl();
        jtable.setTable();
    }
}
