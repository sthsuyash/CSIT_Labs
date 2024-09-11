package Practical3.MouseEvents;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

class MouseEventAdapterImpl extends JFrame {
    JLabel label;

    public void setMouseEvent() {
        label = new JLabel("Click anywhere!");
        add(label);

        // Mouse Adapter for mouse event
        label.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse Clicked at (" + e.getX() + ", " + e.getY() + ")");
            }
        });

        setVisible(true);
        setTitle("Mouse Event Adapter Demo");
        setSize(300, 150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
    }
}

public class MouseEventUsingAdapter {
    public static void main(String[] args) {
        MouseEventAdapterImpl impl = new MouseEventAdapterImpl();
        impl.setMouseEvent();
    }
}
