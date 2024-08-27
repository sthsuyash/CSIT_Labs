package Unit6;

import javafx.application.Application;
import javafx.stage.*; // main window
import javafx.scene.*; // sub window
import javafx.scene.control.*; // components like button
import javafx.scene.layout.*; // layout
import javafx.event.*; // event handling

public class FxLayoutDemo extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        Button button1 = new Button("Button 1");
        Button button2 = new Button("Button 2");
        Button button3 = new Button("Button 3");
        Button button4 = new Button("Button 4");

        Label label1 = new Label("Result");

        /* Layout */

        /* Flowpane: places the component from left to right */
//        FlowPane flowPane = new FlowPane();
//        flowPane.setHgap(20); // set horizontal gap
//        flowPane.getChildren().add(button1); // add button1 into flowpane
//        flowPane.getChildren().add(button2);
//        flowPane.getChildren().add(button3);
//        flowPane.getChildren().add(button4);
//        flowPane.getChildren().add(label1);

        /* Gridpane: places the component in the form of rows and columns */
        GridPane gridPane = new GridPane();
        gridPane.add(button1, 0, 0); // add button1 into gridpane at row 0 and column 0
        gridPane.add(button2, 1, 0);
        gridPane.add(button3, 2, 0);
        gridPane.add(button4, 3, 0);
        gridPane.add(label1, 0, 2);

        /* BorderPane: places the component in the form of top, bottom, left, right and center */
//        BorderPane borderPane = new BorderPane();
//        borderPane.setCenter(label1);
//        borderPane.setTop(button1);
//        borderPane.setBottom(button2);
//        borderPane.setLeft(button3);
//        borderPane.setRight(button4);

        /* HBox: places the component Horizontally */
//        HBox hbox = new HBox();
//        hbox.getChildren().addAll(button1, button2, button3, button4, label1);

        /* VBox: */
//        VBox vbox = new VBox();
//        vbox.getChildren().addAll(button1, button2, button3, button4, label1);

        // Event handling
        button1.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                label1.setText("Button 1 clicked");
            }
        });

        button2.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                label1.setText("Button 2 clicked");
            }
        });

        button3.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                label1.setText("Button 3 clicked");
            }
        });

        button4.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                label1.setText("Button 4 clicked");
            }
        });

        // add layout into scene
        Scene scene = new Scene(gridPane, 300, 200);

        // add scene into stage
        stage.setScene(scene);
        stage.setTitle("Layout Demo");
        stage.show();
    }

}
