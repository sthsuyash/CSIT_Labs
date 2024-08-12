package Unit2;

/**
 * GridLayout places the content in form of row nad column.
 */
import javax.swing.*;
import java.awt.*;

class GridLayoutImpl extends JFrame{
    JButton button1, button2, button3, button4, button5;
    JTextArea textArea;

    public void setGridLayout(){
        button1 = new JButton("Button 1");
        button2 = new JButton("Button 2");
        button3 = new JButton("Button 3");
        button4 = new JButton("Button 4");
        button5 = new JButton("Button 5");
        textArea = new JTextArea(10, 5);
        textArea.setText("This is a text area");

        add(button1);
        add(button2);
        add(button3);
        add(button4);
        add(button5);
        add(textArea);

        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
        setLayout(new GridLayout(2, 3));
    }
}

public class GridLayoutDemo {
    public static void main(String[] args) {
        GridLayoutImpl impl = new GridLayoutImpl();
        impl.setGridLayout();
    }
}
