package Unit2.AdvancedSwingComponents;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * JTable Component                                                                                        *
 *---------------------------------------------------------------------------------------------------------*
 * `JTable` is used to display data in a tabular form, consisting of rows and columns.                     *
 * To create a `JTable`, instantiate its object with parameters that specify the data and column names.    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
//        table1.setPreferredScrollableViewportSize(new Dimension(500, 40));
//        table1.setBounds(30, 40, 200, 300);

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

public class JTables {
    public static void main(String[] args) {
        JTableImpl jtable = new JTableImpl();
        jtable.setTable();
    }
}
