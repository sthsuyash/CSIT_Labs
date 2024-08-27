package Unit3;

/**
 * WindowEvent is generated when the window is opened, closed, activated, deactivated, iconified, deiconified, etc.
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class WindowEventImpl {
    JFrame frame;

    public void setWindowEventImpl() {
        frame = new JFrame();
        frame.setSize(500, 500);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(3);

        JButton button = new JButton("Close");
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.dispose(); // Close the window
            }
        });

        frame.setLayout(new FlowLayout());
        button.setBounds(100, 100, 100, 100); // x, y, width, height
        frame.add(button);

        // handling events on frame
        frame.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
                System.out.println("Window Opened");
            }

            @Override
            public void windowClosing(WindowEvent e) {
                System.out.println("Window Closing");
            }

            @Override
            public void windowClosed(WindowEvent e) {
                //when window is closed using tab
                System.out.println("Window closed");
            }

            @Override
            //minimize
            public void windowIconified(WindowEvent e) {
                System.out.println("Window minimize (Iconify)");
            }

            @Override
            public void windowDeiconified(WindowEvent e) {
                // window back to normal after minimize
                System.out.println("Window maximized (Deiconify)");
            }

            @Override
            public void windowActivated(WindowEvent e) {
                // when window is working
                System.out.println("Window activated");
            }

            @Override
            public void windowDeactivated(WindowEvent e) {
                // when window is not working
                System.out.println("Window deactivated");
            }
        });
    }
}

public class WindowEventDemo {
    public static void main(String[] args) {
        WindowEventImpl impl = new WindowEventImpl();
        impl.setWindowEventImpl();
    }
}
