package Unit2.AdvancedSwingComponents;

import javax.swing.*;
import javax.swing.tree.*;

/**
 * JTree is a Swing component with which we can display the tree structure, i.e. parent and child nodes in hierarchical order.
 * JTree is quite a complex component, which has a 'root node' and 'child nodes'.
 * A node can have many children nodes but only one parent node.
 * If a node has no parent node, then it is called the root node and if a node has no child node, then it is called the leaf node.
 */

class JTreeImpl extends JFrame{
    public void setTree(){
        // creating root node
        DefaultMutableTreeNode root = new DefaultMutableTreeNode("Root");

        // creating child nodes
        DefaultMutableTreeNode child1 = new DefaultMutableTreeNode("Child1");
        DefaultMutableTreeNode child2 = new DefaultMutableTreeNode("Child2");
        DefaultMutableTreeNode child3 = new DefaultMutableTreeNode("Child3");

        // adding child nodes to root node
        root.add(child1);
        root.add(child2);
        root.add(child3);

        // creating grandchild nodes
        DefaultMutableTreeNode grandChild1 = new DefaultMutableTreeNode("GrandChild1");
        DefaultMutableTreeNode grandChild2 = new DefaultMutableTreeNode("GrandChild2");
        DefaultMutableTreeNode grandChild3 = new DefaultMutableTreeNode("GrandChild3");

        // adding grandchild nodes to child node 1
        child1.add(grandChild1);
        child1.add(grandChild2);
        child1.add(grandChild3);

        // creating JTree
        JTree tree = new JTree(root);

        // adding JTree to frame
        add(tree);

        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);
    }
}

public class JTrees {
    public static void main(String[] args) {
        JTreeImpl jTree = new JTreeImpl();
        jTree.setTree();
    }
}