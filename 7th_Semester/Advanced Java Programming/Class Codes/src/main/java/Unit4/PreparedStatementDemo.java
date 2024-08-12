package Unit4;

import java.sql.*;
import java.util.Scanner;

class Prepared {
    private static final String URL = "jdbc:mysql://localhost:3306/primecsitb";
    private static final String UNAME = "root";
    private static final String PASSWORD = "password";

    Scanner sc = new Scanner(System.in);

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
}

public class PreparedStatementDemo {
    public static void main(String[] args) {
        // menu based
        Prepared prepared = new Prepared();
        prepared.viewData();
    }
}
