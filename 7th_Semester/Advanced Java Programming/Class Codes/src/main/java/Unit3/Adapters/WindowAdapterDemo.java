package Unit3.Adapters;

/**
 * Using listener, we have to use all the methods compulsory defined by it.
 * But using adapter lass, we can use any number of methods.
 *
 * Window listener contains 7 methods. Now, using adapter class we can use any method out of 7.
 */
import javax.swing.*;
import java.awt.event.*;

class WindowAdapterImpl extends JFrame{
    public void setWindowAdapterImpl(){
        JFrame frame = new JFrame();
        frame.setVisible(true);
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(3);

        frame.addWindowListener(new WindowAdapter() {
            // out of 7 methods, use any
            @Override
            public void windowIconified(WindowEvent e){
                System.out.println("Window minimized");
            }

            @Override
            public void windowDeiconified(WindowEvent e){
                System.out.println("Window maximized");
            }
        });
    }
}

public class WindowAdapterDemo {
    public static void main(String[] args){
        WindowAdapterImpl window = new WindowAdapterImpl();
        window.setWindowAdapterImpl();
    }
}
