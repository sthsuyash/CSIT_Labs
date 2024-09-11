package Practical4;

import java.sql.*;
import javax.sql.rowset.*;

public class RowSetAndScrollableResultSet {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/crud_db";
        String user = "root";
        String password = "password";

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection connection = DriverManager.getConnection(url, user, password);

            // Scrollable and Updatable ResultSet
            Statement statement = connection.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
            ResultSet resultSet = statement.executeQuery("SELECT * FROM students");

            resultSet.last(); // Move to the last row
            System.out.println("Last Row: " + resultSet.getInt("id") + ", " + resultSet.getString("name"));

            resultSet.first(); // Move to the first row
            System.out.println("First Row: " + resultSet.getInt("id") + ", " + resultSet.getString("name"));

            resultSet.updateString("name", "Updated Name"); // Update the first row
            resultSet.updateRow();

            // RowSet example
            JdbcRowSet rowSet = RowSetProvider.newFactory().createJdbcRowSet();
            rowSet.setUrl(url);
            rowSet.setUsername(user);
            rowSet.setPassword(password);
            rowSet.setCommand("SELECT * FROM students");
            rowSet.execute();

            while (rowSet.next()) {
                System.out.println("RowSet: " + rowSet.getInt("id") + ", " + rowSet.getString("name"));
            }

        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}

