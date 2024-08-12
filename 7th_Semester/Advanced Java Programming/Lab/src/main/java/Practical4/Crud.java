package Practical4;

import java.sql.*;

public class Crud {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/crud_db";
        String user = "root";
        String password = "password";

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection connection = DriverManager.getConnection(url, user, password);

            // Create table
            String createTableSQL = "CREATE TABLE IF NOT EXISTS students (id INT PRIMARY KEY, name VARCHAR(50))";
            Statement statement = connection.createStatement();
            statement.execute(createTableSQL);

            // Create operation
            String insertSQL = "INSERT INTO students (id, name) VALUES (1, 'John Doe')";
            statement.executeUpdate(insertSQL);
            System.out.println("User inserted successfully");

            // Read operation
            String selectSQL = "SELECT * FROM students";
            ResultSet resultSet = statement.executeQuery(selectSQL);
            while (resultSet.next()) {
                System.out.println("ID: " + resultSet.getInt("id") +
                        ", Name: " + resultSet.getString("name"));
            }

            // Update operation
            String updateSQL = "UPDATE students SET name = 'Jane Doe' WHERE id = 1";
            statement.executeUpdate(updateSQL);
            System.out.println("User updated successfully");

            // Delete operation
            String deleteSQL = "DELETE FROM students WHERE id = 1";
            statement.executeUpdate(deleteSQL);
            System.out.println("User deleted successfully");

        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
