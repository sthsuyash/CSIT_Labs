package Unit2;

/**
 * Layout determines how the content should be viewed in window. Following are the layout of swing
 * Layout determines how the content should be viewed
 * *in window. following are the layout of swing
 * *1.flow layout 2. border Layout  3.Grid Layout
 * *4. Grid Bag layout 5. CardLyout 6. Null Layout
 * *Border layout: place the content in terms of
 * *direction: north (top), south (bottom), west (left)
 * east (right), center
 */



import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Border extends JFrame {
    JButton b1, b2, b3, b4;
    JTextArea t1;

    public void setBorder() {
        b1 = new JButton("North Button");
        b2 = new JButton("South Button");
        b3 = new JButton("West Button");
        b4 = new JButton("East Button");
        t1 = new JTextArea(20, 20);
        setVisible(true);
        setSize(400, 400);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(3);
        //adding component into border
        add(b1, BorderLayout.NORTH);
        add(b2, BorderLayout.SOUTH);
        add(b3, BorderLayout.WEST);
        add(b4, BorderLayout.EAST);
        add(t1, BorderLayout.CENTER);
        //after button is clicke
        b1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent a) {
                t1.setText("North button is clicked");
            }
        });
    }
}

public class BorderLayoutDemo {
    public static void main(String[] args) {
        Border b1 = new Border();
        b1.setBorder();
    }
}