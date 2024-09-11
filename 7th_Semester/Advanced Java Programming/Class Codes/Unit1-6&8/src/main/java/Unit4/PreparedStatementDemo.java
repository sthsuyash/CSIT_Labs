package Unit4;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * PreparedStatement                                                                                       *
 * ------------------------------------------------------------------------------------------------------- *
 * `PreparedStatement` is used to execute precompiled SQL statements with or without parameters.           *
 * It provides a way to execute parameterized queries and is more efficient and secure compared to the     *
 * traditional `Statement`.                                                                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Key features of `PreparedStatement`:                                                                    *
 * 1. Prevents SQL injection by separating query structure from data.                                      *
 * 2. Allows parameterized queries where placeholders (`?`) are used for parameters.                       *
 * 3. Improves performance by precompiling SQL statements.                                                 *
 * 4. Provides methods to set various types of parameters (e.g., `setString`, `setInt`).                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Example usage:                                                                                          *
 * 1. Create a `PreparedStatement` object using `Connection.prepareStatement()`.                           *
 * 2. Set parameters using appropriate setter methods.                                                     *
 * 3. Execute the query using methods like `executeQuery()`, `executeUpdate()`.                            *
 * 4. Close the `PreparedStatement` to release resources.                                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

import java.sql.*;
import java.util.Scanner;

class Prepared {
    private static final String URL = "jdbc:mysql://localhost:3306/primecsitb";
    private static final String UNAME = "root";
    private static final String PASSWORD = "password";

    Scanner sc = new Scanner(System.in);

    /**
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *
     * Insert data into the database using `PreparedStatement`.   *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *
     */
    public void insertData() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");

            Connection conn = DriverManager.getConnection(URL, UNAME, PASSWORD);

            System.out.print("Enter your username: ");
            String username = sc.next();

            System.out.print("Enter your password: ");
            String password = sc.next();

            System.out.print("Enter your repassword: ");
            String repassword = sc.next();

            System.out.print("Enter your gender: ");
            String gender = sc.next();

            System.out.print("Enter your course: ");
            String course = sc.next();

            System.out.print("Enter country: ");
            String country = sc.next();

            String insertQuery = "INSERT INTO tbl_reg" +
                    "(username, password, repassword, gender, course, country)" +
                    "VALUES (?, ?, ?, ?, ?, ?)";

            PreparedStatement ps = conn.prepareStatement(insertQuery);
            ps.setString(1, username);
            ps.setString(2, password);
            ps.setString(3, repassword);
            ps.setString(4, gender);
            ps.setString(5, course);
            ps.setString(6, country);

            // execute
            int response = ps.executeUpdate();
            if (response > 0) {
                System.out.println("Data inserted successfully");
            } else {
                System.out.println("Data insertion failed");
            }
            conn.close();
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * * * * * * * * * * * * * * * * *
     * View data from the database.  *
     * * * * * * * * * * * * * * * * *
     */
    public void viewData() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, UNAME, PASSWORD);

            String selectQuery = "SELECT * FROM tbl_reg";
            PreparedStatement ps = conn.prepareStatement(selectQuery);
            ResultSet rs = ps.executeQuery();

            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id"));
                System.out.println("Username: " + rs.getString("username"));
                System.out.println("Password: " + rs.getString("password"));
                System.out.println("Repassword: " + rs.getString("repassword"));
                System.out.println("Gender: " + rs.getString("gender"));
                System.out.println("Course: " + rs.getString("course"));
                System.out.println("Country: " + rs.getString("country"));
                System.out.println("--------------------------------------");
            }

        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * * * * * * * * * *
     * View data by id *
     * * * * * * * * * *
     */
    public void viewDataById() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, UNAME, PASSWORD);

            System.out.print("Enter id: ");
            int id = sc.nextInt();

            String selectQuery = "SELECT * FROM tbl_reg WHERE id = ?";
            PreparedStatement ps = conn.prepareStatement(selectQuery);
            ps.setInt(1, id);
            ResultSet rs = ps.executeQuery();

            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id"));
                System.out.println("Username: " + rs.getString("username"));
                System.out.println("Password: " + rs.getString("password"));
                System.out.println("Repassword: " + rs.getString("repassword"));
                System.out.println("Gender: " + rs.getString("gender"));
                System.out.println("Course: " + rs.getString("course"));
                System.out.println("Country: " + rs.getString("country"));

            }
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * * * * * * * * *
     *  Update data  *
     * * * * * * * * *
     */
    public void updateData() {
        // update username to ?, course to ? whose id is ?
        try {
            Class.forName("com.mysql.jdbc.cj.Driver");
            Connection conn = DriverManager.getConnection(URL, UNAME, PASSWORD);

            System.out.print("Enter the id: ");
            int id = sc.nextInt();

            System.out.print("Enter username to update: ");
            String username = sc.next();

            System.out.print("Enter course to update: ");
            String course = sc.next();

            String updateQuery = "UPDATE tbl_reg SET username = ?, course = ? WHERE id = ?";
            PreparedStatement ps = conn.prepareStatement(updateQuery);
            ps.setString(1, username);
            ps.setString(2, course);
            ps.setInt(3, id);

            int res = ps.executeUpdate();
            if (res > 0) {
                System.out.println(res + " data updated.");
            } else {
                System.out.println("Data update failed.");
            }
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * * * * * * * *
     * Delete data *
     * * * * * * * *
     */
    public void deleteData() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, UNAME, PASSWORD);

            System.out.println("Enter id to delete: ");
            int id = sc.nextInt();

            String delQuery = "DELETE FROM tbl_reg WHERE id = ?";
            PreparedStatement ps = conn.prepareStatement(delQuery);
            ps.setInt(1, id);

            int res = ps.executeUpdate();
            if (res > 0) {
                System.out.println(res + " data deleted.");
            } else {
                System.out.println("Data deletion failed.");
            }
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class PreparedStatementDemo {
    public static void main(String[] args) {
        // menu based
        Prepared prepared = new Prepared();
        int choice;

        do {
            System.out.println("1. Insert data\n" +
                    "2. View data\n" +
                    "3. View data by id\n" +
                    "4. Update data\n" +
                    "5. Delete data\n" +
                    "6. Exit");

            System.out.print("Enter your choice: ");
            choice = new Scanner(System.in).nextInt();

            switch (choice) {
                case 1:
                    prepared.insertData();
                    break;
                case 2:
                    prepared.viewData();
                    break;
                case 3:
                    prepared.viewDataById();
                    break;
                case 4:
                    prepared.updateData();
                    break;
                case 5:
                    prepared.deleteData();
                    break;
                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (true);
    }
}
