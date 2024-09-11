package Practical2;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import java.awt.*;
import java.awt.event.*;
import java.io.File;

public class SwingMenuDemo extends JFrame implements ActionListener {
    private JTextArea textArea;
    private JTree tree;

    public SwingMenuDemo() {
        // Frame settings
        setTitle("Swing Menu Demo");
        setSize(600, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Text Area
        textArea = new JTextArea();
        add(new JScrollPane(textArea), BorderLayout.CENTER);

        // Menu Bar
        JMenuBar menuBar = new JMenuBar();

        // File Menu
        JMenu fileMenu = new JMenu("File");
        fileMenu.setMnemonic('F');

        JMenuItem openItem = new JMenuItem("Open");
        openItem.setMnemonic('O');
        openItem.addActionListener(this);
        fileMenu.add(openItem);

        JMenuItem exitItem = new JMenuItem("Exit");
        exitItem.setMnemonic('E');
        exitItem.addActionListener(this);
        fileMenu.add(exitItem);

        menuBar.add(fileMenu);

        // Edit Menu
        JMenu editMenu = new JMenu("Edit");
        editMenu.setMnemonic('E');

        JMenuItem colorItem = new JMenuItem("Choose Color");
        colorItem.setMnemonic('C');
        colorItem.addActionListener(this);
        editMenu.add(colorItem);

        JMenuItem dialogItem = new JMenuItem("Show Dialog");
        dialogItem.setMnemonic('D');
        dialogItem.addActionListener(this);
        editMenu.add(dialogItem);

        menuBar.add(editMenu);

        // View Menu with Radio Button Menu Items
        JMenu viewMenu = new JMenu("View");
        viewMenu.setMnemonic('V');

        JRadioButtonMenuItem radio1 = new JRadioButtonMenuItem("Option 1");
        JRadioButtonMenuItem radio2 = new JRadioButtonMenuItem("Option 2");
        radio1.addActionListener(this);
        radio2.addActionListener(this);

        ButtonGroup group = new ButtonGroup();
        group.add(radio1);
        group.add(radio2);

        viewMenu.add(radio1);
        viewMenu.add(radio2);

        menuBar.add(viewMenu);

        // Tools Menu with Checkbox Menu Items
        JMenu toolsMenu = new JMenu("Tools");
        toolsMenu.setMnemonic('T');

        JCheckBoxMenuItem checkBox1 = new JCheckBoxMenuItem("Tool 1");
        JCheckBoxMenuItem checkBox2 = new JCheckBoxMenuItem("Tool 2");
        checkBox1.addActionListener(this);
        checkBox2.addActionListener(this);

        toolsMenu.add(checkBox1);
        toolsMenu.add(checkBox2);

        menuBar.add(toolsMenu);

        setJMenuBar(menuBar);

        // Tree Component
        DefaultMutableTreeNode root = new DefaultMutableTreeNode("Root");
        DefaultMutableTreeNode node1 = new DefaultMutableTreeNode("Node 1");
        DefaultMutableTreeNode node2 = new DefaultMutableTreeNode("Node 2");

        root.add(node1);
        root.add(node2);

        tree = new JTree(new DefaultTreeModel(root));
        add(new JScrollPane(tree), BorderLayout.WEST);

        // Display the frame
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        switch (command) {
            case "Open":
                // File Chooser
                JFileChooser fileChooser = new JFileChooser();
                int returnValue = fileChooser.showOpenDialog(this);
                if (returnValue == JFileChooser.APPROVE_OPTION) {
                    File selectedFile = fileChooser.getSelectedFile();
                    textArea.setText("Selected file: " + selectedFile.getAbsolutePath());
                }
                break;

            case "Exit":
                System.exit(0);
                break;

            case "Choose Color":
                // Color Chooser
                Color color = JColorChooser.showDialog(this, "Choose a color", Color.WHITE);
                if (color != null) {
                    textArea.setForeground(color);
                }
                break;

            case "Show Dialog":
                // Dialog Box
                JOptionPane.showMessageDialog(this, "This is a dialog box!", "Dialog", JOptionPane.INFORMATION_MESSAGE);
                break;

            case "Option 1":
                textArea.setText("Option 1 selected.");
                break;

            case "Option 2":
                textArea.setText("Option 2 selected.");
                break;

            case "Tool 1":
                textArea.setText("Tool 1 selected.");
                break;

            case "Tool 2":
                textArea.setText("Tool 2 selected.");
                break;

            default:
                break;
        }
    }

    public static void main(String[] args) {
        new SwingMenuDemo();
    }
}
