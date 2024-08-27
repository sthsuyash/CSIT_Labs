package Unit2.Layouts;

/**
 * CardLayout places the content like sequence of card, i.e. one card at a time. one after the other.
 * One content is hidden by another content.
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Card extends JFrame {
    JButton button1, button2, button3;

    public void setCard() {
        button1 = new JButton("Card1");
        button2 = new JButton("Card2");
        button3 = new JButton("Card3");

        // adding controls into sub window-panel
        JPanel panel1 = new JPanel(); // JFrame is big window, JPanel is small window
        panel1.add(button1, "but1"); // but1 is index, it is used to identify the button
        panel1.add(button2, "but2");
        panel1.add(button3, "but3");

        CardLayout card = new CardLayout();
        // add layout into panel
        panel1.setLayout(card);
        add(panel1); // adding sub-window into frame

        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(3);

        //        card.next(panel1); // it will display next card

        // after clicking on button1, it will display next card
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                card.next(panel1); // it will display next card
            }
        });

        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                card.next(panel1);
            }
        });

    }
}

public class CardLayoutDemo {
    public static void main(String[] args) {
        Card card = new Card();
        card.setCard();
    }
}
