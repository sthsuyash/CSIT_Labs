package Unit2.Layouts;

import javax.swing.*;
import java.awt.*;

/**
 * FlowLayout is used to arrange the components in a line, one after the other (in a flow).
 * It is the default layout of JPanel.
 */

class FlowLayoutImpl extends JFrame {
    public void setFlowLayout() {
        JButton button1 = new JButton("Button 1");
        JButton button2 = new JButton("Button 2");
        JButton button3 = new JButton("Button 3");
        JButton button4 = new JButton("Button 4");
        JButton button5 = new JButton("Button 5");

        add(button1);
        add(button2);
        add(button3);
        add(button4);
        add(button5);

        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
        setLayout(new FlowLayout());
    }
}

public class FlowLayoutDemo {
    public static void main(String[] args) {
        FlowLayoutImpl impl = new FlowLayoutImpl();
        impl.setFlowLayout();
    }
}
