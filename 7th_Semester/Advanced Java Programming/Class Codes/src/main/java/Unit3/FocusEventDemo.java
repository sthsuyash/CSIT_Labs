package Unit3;

/**
 *
 * Generated when any component gets focus from mouse key, etc. to handle focus event focus listener is used.
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Focus extends JFrame {
    JLabel label1;
    JTextField textField1, textField2;

    public void setFocus() {
        label1 = new JLabel("Result");
        textField1 = new JTextField(20);
        textField2 = new JTextField(20);
        add(label1);
        add(textField1);
        add(textField2);
        setVisible(true);
        setSize(400, 400);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(3);

        textField1.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                label1.setText("textField1 got focused.");
            }

            @Override
            public void focusLost(FocusEvent e) {
                label1.setText("textField1 lost focus.");
            }
        });
    }
}

public class FocusEventDemo {
    public static void main(String[] args) {
        Focus focus = new Focus();
        focus.setFocus();
    }

}
