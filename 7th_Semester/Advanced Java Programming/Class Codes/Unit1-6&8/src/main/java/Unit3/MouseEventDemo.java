package Unit3;

/**
 * When any action is performed, like clicking, moving mouse or typing then mouse event is generated.
 * Such events are listened by listener and provides some methods to handle the event.
 * <p>
 * Listener is an interface which contains list of methods and all the method should be used compulsorily.
 * This is also known as delegation event method.
 * <p>
 * Button -> Action event
 * Radio button -> Action event
 * Checkbox -> Item event and action event
 * Combobox -> Item event and action event
 * List -> List selection event
 * <p>
 * Mouse event -> Mouse listener: generated when mouse is clicked, pressed, released, entered, exited, moved, dragged.
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MouseEventImpl extends JFrame {
    JLabel label1;
    JTextArea textArea1;

    public void setMouseEventImpl() {
        label1 = new JLabel("Result");
        textArea1 = new JTextArea(20, 20);

        // handling mouse event in text area
        textArea1.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                label1.setText("Mouse clicked.");
            }

            @Override
            public void mousePressed(MouseEvent e) {
                textArea1.setText("Mouse pressed.");
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                textArea1.setText("Mouse released.");
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                textArea1.setText("Mouse entered.");
            }

            @Override
            public void mouseExited(MouseEvent e) {
                textArea1.setText("Mouse exited.");
            }
        });

        add(label1);
        add(textArea1);
        setVisible(true);
        setDefaultCloseOperation(3);
        setSize(500, 500);
        setLayout(new FlowLayout());
    }
}

public class MouseEventDemo {
    public static void main(String[] args) {
        MouseEventImpl mouseEventImpl = new MouseEventImpl();
        mouseEventImpl.setMouseEventImpl();
    }
}
