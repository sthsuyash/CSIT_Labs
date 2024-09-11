package Unit2;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * SplitPane Component                                                             *
 *---------------------------------------------------------------------------------*
 * `JSplitPane` divides the content into two parts with a slider in between.       *
 * To create a split pane, instantiate an object of `JSplitPane`.                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

import javax.swing.*;

class SplitPaneImpl extends JFrame {
    JTextField textfield;
    JComboBox comboBox;
    JSplitPane splitPane;

    public void setSplitPane() {
        textfield = new JTextField(20);
        String[] data = {"java", "C", "C++", "Python", "Ruby"};
        comboBox = new JComboBox(data);

        // adding text field and combobox in split pane
        // it needs separate window for each component
        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();

        panel1.add(comboBox);
        panel2.add(textfield);

        splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, panel1, panel2);

        splitPane.setOneTouchExpandable(true); // to expand and merge the split pane with one click
        // gap between the content and slider
        splitPane.setDividerSize(20);

        add(splitPane);

        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
    }
}

public class SplitPaneDemo {
    public static void main(String[] args) {
        SplitPaneImpl splitPane = new SplitPaneImpl();
        splitPane.setSplitPane();
    }
}
