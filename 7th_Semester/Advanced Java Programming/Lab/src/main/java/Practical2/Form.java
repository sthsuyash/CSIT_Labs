package Practical2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class FormImpl extends JFrame {
    JTextField nameField;
    JPasswordField passwordField;
    JRadioButton maleButton, femaleButton;
    JCheckBox checkBox1, checkBox2;
    JComboBox<String> comboBox;
    JTextArea textArea;
    JLabel nameLabel, passwordLabel, genderLabel, interestLabel, countryLabel, commentsLabel, resultLabel;
    JButton submitButton;
    JScrollPane resultScrollPane;

    public void setForm() {
        setLayout(new GridLayout(8, 1));

        // Name label and text field
        nameLabel = new JLabel("Name:");
        nameField = new JTextField();
        add(nameLabel);
        add(nameField);

        // Password label and password field
        passwordLabel = new JLabel("Password:");
        add(passwordLabel);
        passwordField = new JPasswordField();
        add(passwordField);

        // Gender label and radio buttons
        genderLabel = new JLabel("Gender:");
        add(genderLabel);
        maleButton = new JRadioButton("Male");
        femaleButton = new JRadioButton("Female");

        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(maleButton);
        genderGroup.add(femaleButton);

        JPanel genderPanel = new JPanel();
        genderPanel.add(maleButton);
        genderPanel.add(femaleButton);
        add(genderPanel);

        // Interests label and checkboxes
        interestLabel = new JLabel("Interests:");
        add(interestLabel);
        checkBox1 = new JCheckBox("Programming");
        checkBox2 = new JCheckBox("Reading");
        JPanel checkBoxPanel = new JPanel();
        checkBoxPanel.add(checkBox1);
        checkBoxPanel.add(checkBox2);
        add(checkBoxPanel);

        // Country label and combo box
        countryLabel = new JLabel("Country:");
        add(countryLabel);
        comboBox = new JComboBox<>(new String[]{"Nepal", "India", "USA", "China"});
        add(comboBox);

        // Comments label and text area
        commentsLabel = new JLabel("Comments:");
        add(commentsLabel);
        textArea = new JTextArea(3, 20);
        add(textArea);

        // Submit button
        submitButton = new JButton("Submit");
        add(submitButton);
        add(new JLabel());

        submitButton.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nameField.getText();
                String password = new String(passwordField.getPassword());
                String gender = maleButton.isSelected() ? "Male" : "Female";
                String interests = "";
                if (checkBox1.isSelected()) interests += "Programming ";
                if (checkBox2.isSelected()) interests += "Reading ";
                String country = (String) comboBox.getSelectedItem();
                String comments = textArea.getText();

                resultLabel.setText("<html>Name: " + name + "<br>Password: " + password + "<br>Gender: " + gender
                        + "<br>Interests: " + interests + "<br>Country: " + country + "<br>Comments: " + comments + "</html>");
            }
        });


        // Result label to display form data
        resultLabel = new JLabel("Form data will be displayed here.");
        resultScrollPane = new JScrollPane(resultLabel);
        add(resultScrollPane);

        setTitle("Complete Form Demo");
        setVisible(true);
        setSize(500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}

public class Form {
    public static void main(String[] args) {
        FormImpl impl = new FormImpl();
        impl.setForm();
    }
}