package Practical4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

class FormImpl extends JFrame {
    JTextField idField, usernameField;
    JPasswordField passwordField, rePasswordField;
    JRadioButton maleRadioButton, femaleRadioButton;
    JCheckBox course1CheckBox, course2CheckBox;
    JComboBox<String> countryComboBox;
    JButton submitButton, resetButton;
    JLabel idLabel, usernameLabel, passwordLabel, rePasswordLabel, genderLabel, courseLabel, countryLabel, messageLabel;

    public void setForm() {
        // ID
        idLabel = new JLabel("ID:");
        add(idLabel);
        idField = new JTextField();
        add(idField);

        // Username
        usernameLabel = new JLabel("Username:");
        add(usernameLabel);
        usernameField = new JTextField();
        add(usernameField);

        // Password
        passwordLabel = new JLabel("Password:");
        add(passwordLabel);
        passwordField = new JPasswordField();
        add(passwordField);

        // Re-Enter Password
        rePasswordLabel = new JLabel("Re-Enter Password:");
        add(rePasswordLabel);
        rePasswordField = new JPasswordField();
        add(rePasswordField);

        // Gender
        genderLabel = new JLabel("Gender:");
        add(genderLabel);
        maleRadioButton = new JRadioButton("Male");
        femaleRadioButton = new JRadioButton("Female");
        ButtonGroup genderGroup = new ButtonGroup();
        genderGroup.add(maleRadioButton);
        genderGroup.add(femaleRadioButton);
        JPanel genderPanel = new JPanel();
        genderPanel.add(maleRadioButton);
        genderPanel.add(femaleRadioButton);
        add(genderPanel);

        // Course
        courseLabel = new JLabel("Course:");
        add(courseLabel);
        course1CheckBox = new JCheckBox("Course 1");
        course2CheckBox = new JCheckBox("Course 2");
        JPanel coursePanel = new JPanel();
        coursePanel.add(course1CheckBox);
        coursePanel.add(course2CheckBox);
        add(coursePanel);

        // Country
        countryLabel = new JLabel("Country:");
        add(countryLabel);
        countryComboBox = new JComboBox<>(new String[]{"Nepal", "India", "USA"});
        add(countryComboBox);

        // Submit and Reset Buttons
        submitButton = new JButton("Submit");
        resetButton = new JButton("Reset");
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Form validation
                String id = idField.getText();
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());
                String rePassword = new String(rePasswordField.getPassword());

                if (id.isEmpty() || username.isEmpty() || password.isEmpty() || rePassword.isEmpty() ||
                        (!maleRadioButton.isSelected() && !femaleRadioButton.isSelected()) ||
                        (!course1CheckBox.isSelected() && !course2CheckBox.isSelected()) ||
                        countryComboBox.getSelectedItem().equals("")) {
                    messageLabel.setText("All fields must be filled!");
                    return;
                }

                if (!password.equals(rePassword)) {
                    messageLabel.setText("Passwords do not match!");
                    return;
                }

                // Database Insertion
                try {
                    Class.forName("com.mysql.cj.jdbc.Driver");
                    Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/crud_db", "root", "password");

                    // create table if not exists
                    String createTable = "CREATE TABLE IF NOT EXISTS students (" +
                            "id VARCHAR(10) PRIMARY KEY, " +
                            "username VARCHAR(50), " +
                            "password VARCHAR(50), " +
                            "repassword VARCHAR(50), " +
                            "gender VARCHAR(10), " +
                            "course VARCHAR(50), " +
                            "country VARCHAR(50))";
                    Statement statement = conn.createStatement();
                    int res = statement.executeUpdate(createTable);
                    if (res >= 0) {
                        System.out.println("Table created successfully");
                    } else {
                        System.out.println("Table creation failed");
                    }

                    String sql = "INSERT INTO students (id, username, password, gender, course, country) VALUES (?, ?, ?, ?, ?, ?)";
                    PreparedStatement preparedStatement = conn.prepareStatement(sql);
                    preparedStatement.setString(1, id);
                    preparedStatement.setString(2, username);
                    preparedStatement.setString(3, password);
                    preparedStatement.setString(4, maleRadioButton.isSelected() ? "Male" : "Female");
                    preparedStatement.setString(5, (course1CheckBox.isSelected() ? "Course 1 " : "") + (course2CheckBox.isSelected() ? "Course 2" : ""));
                    preparedStatement.setString(6, countryComboBox.getSelectedItem().toString());
                    preparedStatement.executeUpdate();
                    messageLabel.setText("Data inserted successfully!");
                } catch (SQLException | ClassNotFoundException ex) {
                    System.out.println(ex.getMessage());
                    messageLabel.setText("Database error!" + ex.getMessage());
                }
            }
        });

        resetButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                idField.setText("");
                usernameField.setText("");
                passwordField.setText("");
                rePasswordField.setText("");
                maleRadioButton.setSelected(false);
                femaleRadioButton.setSelected(false);
                course1CheckBox.setSelected(false);
                course2CheckBox.setSelected(false);
                countryComboBox.setSelectedIndex(0);
                messageLabel.setText("");
            }
        });

        add(submitButton);
        add(resetButton);

        // Message Label
        messageLabel = new JLabel();
        add(messageLabel);

        setVisible(true);
        // Frame settings
        setTitle("Registration Form");
        setSize(350, 400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(10, 2));
    }
}

public class Form {
    public static void main(String[] args) {
        FormImpl impl = new FormImpl();
        impl.setForm();
    }
}
