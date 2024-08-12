package Practical3.WindowEvents;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class WindowEventImpl{
    public void setWindow(){
        JFrame frame = new JFrame();
        frame.setVisible(true);
        frame.setTitle("Window Event Adapter");
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(3);
        frame.setLayout(new FlowLayout());

        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowOpened(WindowEvent e) {
                System.out.println("Window opened");
            }

            @Override
            public void windowClosed(WindowEvent e) {
                System.out.println("Window closed");
            }
        });
    }
}

public class WindowEventUsingAdapter {
    public static void main(String[] args){
        WindowEventImpl window = new WindowEventImpl();
        window.setWindow();
    }
}
