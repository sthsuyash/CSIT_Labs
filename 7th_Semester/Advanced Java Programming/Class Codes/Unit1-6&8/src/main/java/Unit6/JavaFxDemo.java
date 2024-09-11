package Unit6;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Java FX                                                                                                   *
 * --------------------------------------------------------------------------------------------------------- *
 * JavaFX is a Java library used to develop Desktop applications as well as Rich Internet Applications (RIA).*
 * The applications built in JavaFX can run on multiple platforms including Web, Mobile and Desktops.        *
 * JavaFX is intended to replace swing in Java applications as a GUI framework.                              *
 * It provides more functionalities than swing. It is lightweight and hardware-accelerated.                  *
 * Like Swing, JavaFX also provides its own components and does not depend upon the operating system.        *
 * It supports various OS like Windows, macOS, Linux, etc.                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

public class JavaFxDemo extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        Label label = new Label("Hello, JavaFX!");
        Scene scene = new Scene(label, 300, 200);

        // file chooser

//        FileChooser fileChooser = new FileChooser();
//        fileChooser.setTitle("Open Resource File");
//        String path = fileChooser.showOpenDialog(stage).getAbsolutePath();
//        System.out.println(path);

        stage.setScene(scene);
        stage.setTitle("Basic JavaFX App");
        stage.show();
    }
}
