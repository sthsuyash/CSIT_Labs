package Unit2.Layouts;

/**
 * GridBagLayout is one of the most flexible and complex layout managers the Java platform provides.
 * A GridBagLayout places components in a grid of rows and columns, allowing specified components to span multiple rows or columns.
 * Not all rows necessarily have the same height. Similarly, not all columns necessarily have the same width.
 * Essentially, GridBagLayout places components in rectangles (cells) in a grid,
 * and then uses the components' preferred sizes to determine how big the cells should be.
 *
 * We can specify where a content can be placed and also merge two or more cells.
 * Two classes are involved: GridBag and GridBagConstraint(for setting layout of content).
 */

import javax.swing.*;
import java.awt.*;

class GridBagImpl extends JFrame {
    JButton button1, button2, button3;

    public void setGridBag() {
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        button3 = new JButton("Button 3");

        // creating object of GridBag and Constraint
        GridBagLayout gridBagLayout = new GridBagLayout();
        GridBagConstraints gridBagConstraints = new GridBagConstraints(); // this is the main thing that is used to set components

        setVisible(true);
        setSize(500, 500);
        setLayout(new GridBagLayout());
        setDefaultCloseOperation(3);

        // setting layout of button1 at (0, 0)
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 0;
        // put the button1 horizontally
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        // add the button with frame
        add(button1, gridBagConstraints);

        // settting layout of button2 at (1, 0)
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button2, gridBagConstraints);

        // setting layout of button3 as (0, 1)
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 2;
        gridBagConstraints.fill = GridBagConstraints.HORIZONTAL;
        add(button3, gridBagConstraints);
    }
}

public class GridBagLayoutDemo {
    public static void main(String[] args) {
        GridBagImpl grid = new GridBagImpl();
        grid.setGridBag();
    }
}
