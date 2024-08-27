package Unit6;

import javafx.application  .Application;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.event.*;

public class FxForm extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Label usernameLabel = new Label("Username:");
        Label passwordLabel = new Label("Password:");
        Label genderLabel = new Label("Gender");
        Label courseLabel = new Label("Course");
        Label countryLabel = new Label("Country");

        TextField resultField = new TextField();
        TextField textField = new TextField();
        PasswordField passwordField = new PasswordField();
        RadioButton maleButton = new RadioButton("Male");
        RadioButton femaleButton = new RadioButton("Female");

        ToggleGroup toggleGroup = new ToggleGroup();
        maleButton.setToggleGroup(toggleGroup);
        femaleButton.setToggleGroup(toggleGroup);

        CheckBox javaCheckBox = new CheckBox("Java");
        CheckBox cppCheckBox = new CheckBox("C++");

        // Dropdown: Choicebox
        ChoiceBox choiceBox = new ChoiceBox();
        choiceBox.getItems().addAll("Nepal", "India", "Other");

        Button button = new Button("Submit");

        // Grid layout
        GridPane gridPane = new GridPane();
        gridPane.add(usernameLabel, 0, 0);
        gridPane.add(textField, 1, 0);

        gridPane.add(passwordLabel, 0, 1);
        gridPane.add(passwordField, 1, 1);

        gridPane.add(genderLabel, 0, 2);
        gridPane.add(maleButton, 1, 2);

        gridPane.add(new Label(), 0, 3);
        gridPane.add(femaleButton, 2, 2);

        gridPane.add(courseLabel, 0, 4);
        gridPane.add(javaCheckBox, 1, 4);
        gridPane.add(cppCheckBox, 1, 5);

        gridPane.add(countryLabel, 0, 7);
        gridPane.add(choiceBox, 1, 7);

        gridPane.add(button, 1, 8);

        // Button event handling
        button.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                String username = textField.getText();
                String password = passwordField.getText();
                String gender = "";
                if (maleButton.isSelected()) {
                    gender = maleButton.getText();
                } else if (femaleButton.isSelected()) {
                    gender = femaleButton.getText();
                }
                String course = "";
                if (javaCheckBox.isSelected()) {
                    course += javaCheckBox.getText() + " ";
                }
                if (cppCheckBox.isSelected()) {
                    course += cppCheckBox.getText() + " ";
                }


                System.out.println("Username: " + username);

                resultField.setText(
                        "Username: " + username + "\n" +
                                "Password: " + password + "\n" +
                                "Gender: " + gender + "\n" +
                                "Course: " + course + "\n"
                );
            }
        });

        Scene scene = new Scene(gridPane, 400, 400);
        stage.setTitle("Registration Form");
        stage.setScene(scene);
        stage.show();
    }
}
