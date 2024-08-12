package Unit2.Layouts;

import javax.swing.*;
import java.awt.*;

/**
 * Components can be arranged in containers without the use of any layout manager.
 * Items must be manually placed in the container. It means no layout manager is assigned and components can be put at specific location x, y coordinates.
 * The setBounds() method is used to set the position and size of the component.
 */

class NoLayout extends JFrame {
    JButton button1;

    public void setNoLayout() {
        button1 = new JButton("Click Here!");
        button1.setBounds(50, 100, 100, 30);
        add(button1);

        setLayout(null);
        setVisible(true);
        setSize(400, 400);
        setDefaultCloseOperation(3);
    }
}

public class NoLayoutDemo {
    public static void main(String[] args) {
        NoLayout layout = new NoLayout();
        layout.setNoLayout();
    }
}
