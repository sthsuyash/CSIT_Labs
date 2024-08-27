package Unit6;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class JavaFxDemo extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) {
        Label label = new Label("Hello, JavaFX!");
        Scene scene = new Scene(label, 300, 200);
        stage.setScene(scene);
        stage.setTitle("Basic JavaFX App");
        stage.show();
    }
}
