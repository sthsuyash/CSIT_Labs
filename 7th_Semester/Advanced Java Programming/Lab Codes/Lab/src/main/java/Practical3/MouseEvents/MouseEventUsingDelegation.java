package Practical3.MouseEvents;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

class MouseEventImpl extends JFrame {
    JLabel label;

    public void setMouseImpl() {
        label = new JLabel("Click anywhere!");
        add(label);

        // Mouse Listener for mouse event
        label.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                label.setText("Mouse Clicked at (" + e.getX() + ", " + e.getY() + ")");
            }

            @Override
            public void mousePressed(MouseEvent e) {
                label.setText("Mouse Pressed at (" + e.getX() + ", " + e.getY() + ")");
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                label.setText("Mouse Released at (" + e.getX() + ", " + e.getY() + ")");
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                label.setText("Mouse Entered at (" + e.getX() + ", " + e.getY() + ")");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                label.setText("Mouse Exited at (" + e.getX() + ", " + e.getY() + ")");
            }
        });

        setVisible(true);
        setTitle("Mouse Event Adapter Demo");
        setSize(300, 150);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
    }
}

public class MouseEventUsingDelegation {
    public static void main(String[] args) {
        MouseEventImpl impl = new MouseEventImpl();
        impl.setMouseImpl();
    }
}
