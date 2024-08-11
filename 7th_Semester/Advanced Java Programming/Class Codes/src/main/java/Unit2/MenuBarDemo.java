package Unit2;

/**
 * Menubar is a tab that contains sequence of item known as menu
 * and menu contain list of other sub items known as menu item.
 * Step1: Create menu item
 * Step2: Create menu and menu item
 * <p>
 * Add menu item to menu and menu into menu bar
 */

import javax.swing.*;
import java.awt.*;

class Menu extends JFrame {
    JMenuBar mb;

    // Three main menu items and one submenu
    JMenu m1, m2, m3, m4;

    // now create a menu
    public void setMenu() {
        mb = new JMenuBar();
        m1 = new JMenu("File");

        // shortcut key -> mnemonic
        m1.setMnemonic('f');

        // adding menuitem to menu m1 i.e.File
        JMenuItem mi1 = new JMenuItem("Open", 'o');
        JMenuItem mi2 = new JMenuItem("Save", 's');
        JMenuItem mi3 = new JMenuItem("Save as", 'd');

        // adding menuitem to the menu m1
        m1.add(mi1);
        m1.add(mi2);
        m1.add(mi3);

        // add menu into menubar
        mb.add(m1);

        // creating submenu item and adding into m1
        m2 = new JMenu("New");
        m2.setMnemonic('n');
        JMenuItem n1 = new JMenuItem("New File", 'y');
        JMenuItem n2 = new JMenuItem("New Folder", 'z');

        // add the submenu items to m2 menu
        m2.add(n1);
        m2.add(n2);

        // adding m2 into m1 for creating sub menu
        m1.add(m2);

        m3 = new JMenu("Edit");
//        m3.setMnemonic('e');
        JRadioButtonMenuItem r1 = new JRadioButtonMenuItem("Copy");
        JRadioButtonMenuItem r2 = new JRadioButtonMenuItem("Paste");
        m3.add(r1);
        m3.add(r2);
        mb.add(m3);

        // creating checkbox menu item in m4
        m4 = new JMenu("View");
        JCheckBoxMenuItem c1 = new JCheckBoxMenuItem("Zoom In");
        JCheckBoxMenuItem c2 = new JCheckBoxMenuItem("Zoom Out");
        m4.add(c1);
        m4.add(c2);
        mb.add(m4);

        // add menubar into JFrame
        add(mb);
        setVisible(true);
        setSize(500, 500);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(3);
    }
}

public class MenuBarDemo {
    public static void main(String[] args) {
        Menu m = new Menu();
        m.setMenu();
    }
}
