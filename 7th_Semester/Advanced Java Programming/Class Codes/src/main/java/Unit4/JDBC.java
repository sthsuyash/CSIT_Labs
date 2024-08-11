package Unit4;

/**
 * To connect with external data sources such as XML file, SQL Server, etc. we need JDBC driver.
 * For such driver mysql-connector jar needs to be downloaded and added to the project - for MySQL connection.
 * For PostgreSQL, postgresql jar needs to be downloaded.
 * <p>
 * Steps to connect to the database
 * 1. Insert the JDBC driver (jar file) in the project.
 * 2. Initialize the driver using Class.forName("com.mysql.jdbc.Driver");
 * 3. Use connection object to connect to the database. For this DriverManager.getConnection() is used.
 * It takes three parameters (protocol, serverusername, serverpassword).
 * 4. Write appropriate SQL query.
 * 5. Execute the query using Statement object.
 * 6. Close the connection.
 * For insert, update and delete => execute(): returns true of false | executeUpdate(): returns 1 or 0
 * For select => executeQuery(): returns ResultSet object
 */

import java.sql.*;
import java.util.Scanner;

class JDBCImpl {

    private static final String URL = "jdbc:mysql://localhost:3306/primecsitb";
    private static final String USERNAME = "root";
    private static final String PASSWORD = "password";

    Scanner sc = new Scanner(System.in);

    /**
     * Create a connection with the database
     */
    public void createConnectionExample() {
        try {
            // Step 1: Load the JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Connect to the database
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            if (conn != null) {
                System.out.println("Database connected successfully.");
            } else {
                System.out.println("Database connection failed.");
            }

            // Closing the connection
            conn.close();
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Create a table in the database
     */
    public void createTable() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);
            // Creating table: tbl_reg
            String createQuery = "CREATE TABLE IF NOT EXISTS tbl_reg (" +
                    "id INT PRIMARY KEY AUTO_INCREMENT," +
                    "username VARCHAR(50)," +
                    "password VARCHAR(50)," +
                    "repassword VARCHAR(50)," +
                    "gender VARCHAR(10)," +
                    "course VARCHAR(50)," +
                    "country VARCHAR(50))";
            Statement st = conn.createStatement();
            st.execute(createQuery);
            System.out.println("Table created successfully.");
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * View all the data from the table
     */
    public void viewAllData() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            if (conn == null) {
                throw new SQLException("Database connection failed.");
            }

            // Viewing data: from table tbl_reg created above
            String selectQuery = "SELECT * FROM tbl_reg";

            Statement st = conn.createStatement();
            ResultSet rs = st.executeQuery(selectQuery);

            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id"));
                System.out.println("Username: " + rs.getString("username"));
                System.out.println("Password: " + rs.getString("password"));
                System.out.println("Re-password: " + rs.getString("repassword"));
                System.out.println("Gender: " + rs.getString("gender"));
                System.out.println("Course: " + rs.getString("course"));
                System.out.println("Country: " + rs.getString("country"));
                System.out.println("----------------------------");
            }
            conn.close();
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * View individual data using id from the table
     */
    public void viewDataById() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            if (conn == null) {
                throw new SQLException("Database connection failed.");
            }

            System.out.print("Enter id to view: ");
            int id = sc.nextInt();

            // Viewing data: from table tbl_reg
            String selectQuery = "SELECT * FROM tbl_reg WHERE id = ?";
            PreparedStatement pst = conn.prepareStatement(selectQuery);
            pst.setInt(1, id);
            ResultSet rs = pst.executeQuery();
            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id"));
                System.out.println("Username: " + rs.getString("username"));
                System.out.println("Password: " + rs.getString("password"));
                System.out.println("Re-password: " + rs.getString("repassword"));
                System.out.println("Gender: " + rs.getString("gender"));
                System.out.println("Course: " + rs.getString("course"));
                System.out.println("Country: " + rs.getString("country"));
            }
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }

    public void insertData() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            if (conn == null) {
                throw new SQLException("Database connection failed.");
            }

            // Inserting data: to table tbl_reg created above
            String insertQuery = "INSERT INTO tbl_reg (" +
                    "username, password, repassword, gender, course, country)" +
                    "VALUES ('ram', 'rampassword', 'rampassword', 'male', 'BSc.CSIT', 'Nepal')";

            // Executing the query: Statement object is used
            Statement st = conn.createStatement();
            boolean rowsAffected = st.execute(insertQuery);

            if (rowsAffected) {
                System.out.println("Data inserted successfully.");
            } else {
                System.out.println("Data insertion failed.");
            }
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Insert data into the table
     * by taking input from the user
     */
    public void insertDataFromUser() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            if (conn == null) {
                throw new SQLException("Database connection failed.");
            }

            // Inserting data: to table tbl_reg created above
            String insertQuery = "INSERT INTO tbl_reg (" +
                    "username, password, repassword, gender, course, country)" +
                    "VALUES (?, ?, ?, ?, ?, ?)";
            // The ? is a placeholder for the values

            // Prepared statement is used to insert data by replacing the placeholders with the actual values
            PreparedStatement pst = conn.prepareStatement(insertQuery);
            System.out.print("Enter username: ");
            pst.setString(1, sc.next());
            System.out.print("Enter password: ");
            pst.setString(2, sc.next());
            System.out.print("Re-enter password: ");
            pst.setString(3, sc.next());
            System.out.print("Enter gender: ");
            pst.setString(4, sc.next());
            System.out.print("Enter course: ");
            pst.setString(5, sc.next());
            System.out.print("Enter country: ");
            pst.setString(6, sc.next());

            int rowsAffected = pst.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Data inserted successfully.");
            } else {
                System.out.println("Data insertion failed.");
            }
            conn.close();
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Update data in the table
     */
    public void updateData() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            if (conn == null) {
                throw new SQLException("Database connection failed.");
            }

            // Updating data: in table tbl_reg
            System.out.print("Enter id to update: ");
            int id = sc.nextInt();
//            sc.nextLine();  // Consume newline

            System.out.print("Enter new username: ");
            String username = sc.nextLine();

            String updateQuery = "UPDATE tbl_reg SET username = ? WHERE id = ?";

            try (PreparedStatement pst = conn.prepareStatement(updateQuery)) {
                pst.setString(1, username);
                pst.setInt(2, id);

                boolean rowsAffected = pst.execute();
                if (rowsAffected) {
                    System.out.println("Data updated successfully.");
                } else {
                    System.out.println("Data updation failed.");
                }
            }
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    /**
     * Delete data from the table by id
     */
    public void deleteData() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USERNAME, PASSWORD);

            if (conn == null) {
                throw new SQLException("Database connection failed.");
            }

            // Deleting data: from table tbl_reg
            System.out.print("Enter id to delete: ");
            int id = sc.nextInt();

            String deleteQuery = "DELETE FROM tbl_reg WHERE id = ?";

            PreparedStatement pst = conn.prepareStatement(deleteQuery);
            pst.setInt(1, id);

            int rowsAffected = pst.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Data deleted successfully.");
            } else {
                System.out.println("Data deletion failed.");
            }
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class JDBC {
    public static void main(String[] args) {
        JDBCImpl impl = new JDBCImpl();
        impl.createConnectionExample();
        impl.createTable();

        int choice;
        do {
            System.out.println();
            System.out.println("1. View data");
            System.out.println("2. View data by id");
            System.out.println("3. Insert data");
            System.out.println("4. Insert data from user");
            System.out.println("5. Update data");
            System.out.println("6. Delete data");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");

            Scanner sc = new Scanner(System.in);
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    impl.viewAllData();
                    break;
                case 2:
                    impl.viewDataById();
                    break;
                case 3:
                    impl.insertData();
                    break;
                case 4:
                    impl.insertDataFromUser();
                    break;
                case 5:
                    impl.updateData();
                    break;
                case 6:
                    impl.deleteData();
                    break;
                case 7:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 7);
    }
}
