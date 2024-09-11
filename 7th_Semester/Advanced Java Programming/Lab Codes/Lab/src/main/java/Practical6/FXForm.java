//package Practical6;
//
//import javafx.application.Application;
//import javafx.stage.*;
//import javafx.scene.*;
//import javafx.scene.control.*;
//import javafx.scene.layout.*;
//import javafx.event.*;
//
//import java.sql.*;
//
//public class FXForm extends Application {
//    public static void main(String[] args) {
//        launch(args);
//    }
//
//    @Override
//    public void start(Stage stage) throws Exception {
//        Label usernameLabel = new Label("Username:");
//        Label passwordLabel = new Label("Password:");
//        Label rePasswordLabel = new Label("Re-enter Password:");
//        Label genderLabel = new Label("Gender");
//        Label courseLabel = new Label("Course");
//        Label countryLabel = new Label("Country");
//
//        TextField textField = new TextField();
//        PasswordField passwordField = new PasswordField();
//        PasswordField rePasswordField = new PasswordField();
//        RadioButton maleButton = new RadioButton("Male");
//        RadioButton femaleButton = new RadioButton("Female");
//
//        ToggleGroup toggleGroup = new ToggleGroup();
//        maleButton.setToggleGroup(toggleGroup);
//        femaleButton.setToggleGroup(toggleGroup);
//
//        CheckBox javaCheckBox = new CheckBox("Java");
//        CheckBox cppCheckBox = new CheckBox("C++");
//
//        // Dropdown: ChoiceBox
//        ChoiceBox<String> choiceBox = new ChoiceBox<>();
//        choiceBox.getItems().addAll("Nepal", "India", "Other");
//
//        Button button = new Button("Submit");
//        TextField resultField = new TextField();
//        resultField.setEditable(false);
//
//        // Grid layout
//        GridPane gridPane = new GridPane();
//        gridPane.add(usernameLabel, 0, 0);
//        gridPane.add(textField, 1, 0);
//
//        gridPane.add(passwordLabel, 0, 1);
//        gridPane.add(passwordField, 1, 1);
//
//        gridPane.add(rePasswordLabel, 0, 2);
//        gridPane.add(rePasswordField, 1, 2);
//
//        gridPane.add(genderLabel, 0, 3);
//        gridPane.add(maleButton, 1, 3);
//
//        gridPane.add(new Label(), 0, 4); // Spacer
//        gridPane.add(femaleButton, 1, 4);
//
//        gridPane.add(courseLabel, 0, 5);
//        gridPane.add(javaCheckBox, 1, 5);
//        gridPane.add(cppCheckBox, 1, 6);
//
//        gridPane.add(countryLabel, 0, 7);
//        gridPane.add(choiceBox, 1, 7);
//
//        gridPane.add(button, 1, 8);
//        gridPane.add(resultField, 1, 9);
//
//        // Button event handling
//        button.setOnAction(new EventHandler<ActionEvent>() {
//            @Override
//            public void handle(ActionEvent e) {
//                String username = textField.getText().trim();
//                String password = passwordField.getText().trim();
//                String rePassword = rePasswordField.getText().trim();
//                String gender = maleButton.isSelected() ? maleButton.getText() : femaleButton.isSelected() ? femaleButton.getText() : "";
//                String course = "";
//                if (javaCheckBox.isSelected()) {
//                    course += javaCheckBox.getText() + " ";
//                }
//                if (cppCheckBox.isSelected()) {
//                    course += cppCheckBox.getText() + " ";
//                }
//
//                String country = choiceBox.getValue() != null ? choiceBox.getValue() : "";
//
//                if (username.isEmpty() || password.isEmpty() || rePassword.isEmpty() || gender.isEmpty() || country.isEmpty()) {
//                    resultField.setText("Please fill all fields.");
//                    return;
//                }
//
//                if (!password.equals(rePassword)) {
//                    resultField.setText("Passwords do not match.");
//                    return;
//                }
//
//                // Insert into database
//                try {
//                    Class.forName("com.mysql.cj.jdbc.Driver");
//                    String URL = "jdbc:mysql://localhost:3306/crud_db";
//                    String USERNAME = "root";
//                    String PASSWORD = "password";
//                    Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);
//
//                    if (conn != null) {
//                        System.out.println("Connected to the database");
//                    }
//
//                    String insertQuery = "INSERT INTO students VALUES (?, ?, ?, ?, ?, ?, ?)";
//                    PreparedStatement ps = conn.prepareStatement(insertQuery);
//                    ps.setInt(1, 2);
//                    ps.setString(2, username);
//                    ps.setString(3, password);
//                    ps.setString(4, rePassword);
//                    ps.setString(5, gender);
//                    ps.setString(6, course);
//                    ps.setString(7, country);
//
//                    int result = ps.executeUpdate();
//                    if (result > 0) {
//                        resultField.setText("Data inserted successfully");
//                        System.out.println("Data inserted successfully");
//                    } else {
//                        resultField.setText("Error in inserting data");
//                    }
//                    conn.close();
//                } catch (ClassNotFoundException | SQLException ex) {
//                    resultField.setText("Error in database: " + ex.getMessage());
//                }
//            }
//        });
//
//        Scene scene = new Scene(gridPane, 400, 400);
//        stage.setTitle("Registration Form");
//        stage.setScene(scene);
//        stage.show();
//    }
//}
