package Unit4;

import java.sql.*;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * SQL Escapes                                                                               *
 * ----------------------------------------------------------------------------------------- *
 * Escape sequences are used within an SQL statement to tell the driver.                     *
 * that the escaped part of the SQL string should be handled differently.                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * When the JDBC driver processes the escaped part of an SQL string,                         *
 * it translates that part of the string to SQL Code that can be understood by the database. *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * There are five types of escape sequences that JDBC API requires:                          *
 * - LIKE wildcard literals                                                                  *
 * - Function handling                                                                       *
 * - Date and Time literals                                                                  *
 * - Stored procedure calls                                                                  *
 * - Outer joins                                                                             *
 * - Limit escape syntax                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

public class SqlEscapes {
    public static void main(String[] args) throws SQLException {
        final String URL = "jdbc:mysql://localhost:3306/primecsitb";
        final String USER = "root";
        final String PASS = "password";

        Connection conn = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection(URL, USER, PASS);
            Statement st = conn.createStatement();

            /**
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             * LIKE wildcard literals                                                                          *
             * ----------------------------------------------------------------------------------------------- *
             * The LIKE operator is used in a WHERE clause to search for a specified pattern in a column.      *
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             * There are two wildcards often used in conjunction with the LIKE operator:                       *
             * - %: The percent sign represents zero, one, or multiple characters.                             *
             * - _: The underscore represents a single character.                                              *
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             */
            String likeSql1 = "SELECT * FROM employees WHERE last_name LIKE 'Smi%'"; // Select all employees whose last name starts with 'Smi'
            String likeSql2 = "SELECT * FROM employees WHERE last_name LIKE 'Sm_th'"; // Select all employees whose last name is 'Smith' or 'Smyth'

            ResultSet rs = st.executeQuery(likeSql1);
            while (rs.next()) {
                System.out.println("Employee: " + rs.getString("first_name") + " " + rs.getString("last_name"));
            }

            /**
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             * Function Handling                                                                               *
             * ----------------------------------------------------------------------------------------------- *
             * The JDBC API provides a way to call functions that are not supported by the SQL language.       *
             * The syntax for calling a function is {fn function_name(parameters)}                             *
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             */
            String functionSql = "SELECT {fn CONCAT(first_name, ' ', last_name)} AS full_name FROM employees";
            ResultSet rs2 = st.executeQuery(functionSql);
            while (rs2.next()) {
                System.out.println("Full Name: " + rs2.getString("full_name"));
            }

            /**
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             * Date and Time literals                                                              *
             * ----------------------------------------------------------------------------------- *
             * The JDBC API provides a way to specify date and time literals in SQL statements.    *
             * The syntax for date and time literals is {d 'yyyy-mm-dd'} and {t 'hh:mm:ss'}        *
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             */
            String dtSql = "SELECT * FROM employees WHERE hire_date = {d '2021-01-01'}";
            ResultSet rs3 = st.executeQuery(dtSql);
            while (rs3.next()) {
                System.out.println(rs3.getString("first_name"));
            }

            /**
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             * Stored Procedure Calls                                                              *
             * ----------------------------------------------------------------------------------- *
             * The JDBC API provides a way to call stored procedures from an SQL statement.        *
             * The syntax for calling a stored procedure is {call procedure_name(parameters)}      *
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             */
            String storedSql = "{call get_employee(101)}";
            ResultSet rs4 = st.executeQuery(storedSql);
            while (rs4.next()) {
                System.out.println("First Name: " + rs4.getString("first_name"));
                System.out.println("Last Name: " + rs4.getString("last_name"));
            }

            /**
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             * Outer Joins                                                                         *
             * ----------------------------------------------------------------------------------- *
             * The JDBC API provides a way to specify outer joins in SQL statements.               *
             * The syntax for outer joins is {oj table1 LEFT OUTER JOIN table2 ON condition}       *
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             */
            String outerJoinSql = "SELECT * FROM employees {oj departments LEFT OUTER JOIN employees ON departments.department_id = employees.department_id}";
            ResultSet rs5 = st.executeQuery(outerJoinSql);
            while (rs5.next()) {
                System.out.println("Employee: " + rs5.getString("first_name") + " " + rs5.getString("last_name"));
            }

            /**
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             * Limit escape syntax                                                                 *
             * ----------------------------------------------------------------------------------- *
             * The JDBC API provides a way to specify the limit clause in SQL statements.          *
             * The syntax for the limit clause is {LIMIT n OFFSET m}                               *
             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
             */
            String limitSql = "SELECT * FROM employees {LIMIT 10 OFFSET 0}";
            ResultSet rs6 = st.executeQuery(limitSql);
            while (rs6.next()) {
                System.out.println("Employee: " + rs6.getString("first_name") + " " + rs6.getString("last_name"));
            }

        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e.getMessage());
        } finally {
            if (conn != null) {
                conn.close();
            }
        }
    }
}
