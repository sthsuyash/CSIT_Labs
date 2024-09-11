package Practical3.WindowEvents;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class WindowEventImpl2 {
    public void setWindow() {
        JFrame frame = new JFrame();
        frame.setVisible(true);
        frame.setTitle("Window Event Adapter");
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(3);
        frame.setLayout(new FlowLayout());

        frame.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
                System.out.println("Window opened");
            }

            @Override
            public void windowClosing(WindowEvent e) {
                System.out.println("Window closing");
            }

            @Override
            public void windowClosed(WindowEvent e) {
                System.out.println("Window closed");
            }

            @Override
            public void windowIconified(WindowEvent e) {
                System.out.println("Window minimized");
            }

            @Override
            public void windowDeiconified(WindowEvent e) {
                System.out.println("Window maximized");
            }

            @Override
            public void windowActivated(WindowEvent e) {
                System.out.println("Window activated");
            }

            @Override
            public void windowDeactivated(WindowEvent e) {
                System.out.println("Window deactivated");
            }
        });
    }
}

public class WindowEventUsingDelegation {
    public static void main(String[] args) {
        WindowEventImpl2 window = new WindowEventImpl2();
        window.setWindow();
    }
}
