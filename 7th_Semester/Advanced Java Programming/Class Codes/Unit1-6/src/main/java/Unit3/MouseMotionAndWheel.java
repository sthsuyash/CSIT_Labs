package Unit3;

/**
 * Mouse motion is generated when mouse is moved and dragged.
 * Mouse wheel event when wheel of mouse is moved.
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

class MouseMotionWheel extends JFrame {
    JLabel label = new JLabel();
    JTextArea textArea;

    public void setMouseWheel(){
        label = new JLabel("Result");
        textArea = new JTextArea(20, 20);

        // add the components
        add(label);
        add(textArea);

        setVisible(true);
        setSize(400, 400);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(3);

        // handling mouse motion event
        textArea.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
                label.setText("Mouse dragged " + e.getX() + " " + e.getY() + ".");
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                label.setText("Mouse moved " + e.getX() + " " + e.getY() + ".");
            }
        });

        textArea.addMouseWheelListener(new MouseWheelListener() {
            @Override
            public void mouseWheelMoved(MouseWheelEvent e) {
                label.setText("Mouse wheel moved " + e.getX() + " " + e.getY() + ".");
            }
        });
    }
}

public class MouseMotionAndWheel {
    public static void main(String[] args) {
        MouseMotionWheel motion = new MouseMotionWheel();
        motion.setMouseWheel();
    }
}
