package Unit2.AdvancedSwingComponents;

import javax.swing.*;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * JList Component                                                                                         * 
 *---------------------------------------------------------------------------------------------------------*
 * `JList` is a component that displays a list of objects.                                                 *
 * A user can select one or more items from the list.                                                      *
 * This list is used to format and get user input from the list of items.                                  *
 * The user can choose either one item or a list of items.                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

class JListImpl extends JFrame {
    public void setList() {
        // creating JList
        DefaultListModel<String> list = new DefaultListModel<>();
        list.addElement("Item1");
        list.addElement("Item2");
        list.addElement("Item3");
        list.addElement("Item4");

        JList<String> jlist = new JList<>(list);
        jlist.setBounds(100, 100, 75, 75);

        // adding JList to frame
        add(jlist);

        setVisible(true);
        setSize(400, 400);
        setDefaultCloseOperation(3);
    }
}

public class JLists {
    public static void main(String[] args) {
        JListImpl jList = new JListImpl();
        jList.setList();
    }
}
