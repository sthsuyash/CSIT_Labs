package Practical4;

import java.sql.*;
import java.util.Scanner;

public class PreparedStatementCrud {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/crud_db";
        String user = "root";
        String password = "password";
        Scanner sc = new Scanner(System.in);

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection connection = DriverManager.getConnection(url, user, password);

            // Create operation
            String insertSQL = "INSERT INTO students (id, name) VALUES (?, ?)";
            PreparedStatement preparedStatement = connection.prepareStatement(insertSQL);

            System.out.print("Enter id: ");
            int id = sc.nextInt();
            System.out.print("Enter name: ");
            String name = sc.next();
            preparedStatement.setInt(1, id);
            preparedStatement.setString(2, name);
            preparedStatement.executeUpdate();

            // Read operation
            String selectSQL = "SELECT * FROM students";
            ResultSet resultSet = preparedStatement.executeQuery(selectSQL);
            while (resultSet.next()) {
                System.out.println("ID: " + resultSet.getInt("id") +
                        ", Name: " + resultSet.getString("name"));
            }

            // Update operation
            String updateSQL = "UPDATE students SET name = ? WHERE id = ?";
            preparedStatement = connection.prepareStatement(updateSQL);

            System.out.print("Enter id to update: ");
            id = sc.nextInt();
            System.out.print("Enter new name: ");
            name = sc.next();
            preparedStatement.setString(1, name);
            preparedStatement.setInt(2, id);
            preparedStatement.executeUpdate();
            System.out.println("Data updated successfully");

            // Delete operation
            String deleteSQL = "DELETE FROM students WHERE id = ?";
            preparedStatement = connection.prepareStatement(deleteSQL);

            System.out.print("Enter id to delete: ");
            id = sc.nextInt();
            preparedStatement.setInt(1, id);
            preparedStatement.executeUpdate();
            System.out.println("Data deleted successfully");

            connection.close();
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
