package Unit3.Adapters;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MouseEventImpl extends JFrame{
    JLabel label1;
    JTextArea textArea1;

    public void setMouseEventImpl(){
        label1 = new JLabel("Result");
        textArea1 = new JTextArea(20, 20);

        // handling mouse event in text area
        textArea1.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                label1.setText("Mouse clicked.");
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

public class MouseAdapterDemo {
    public static void main(String[] args) {
        MouseEventImpl mouseEventImpl = new MouseEventImpl();
        mouseEventImpl.setMouseEventImpl();
    }
}
