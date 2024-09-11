package Unit4;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Transactions in SQL using JDBC                                                    *
 * --------------------------------------------------------------------------------- *
 * A transaction is a set of one or more statements that is executed as a unit,      *
 * so either all the statements are executed or none of the statements are executed. *
 * JDBC transaction make sure a set of SQL statements are executed as a single unit. *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Transactions Handling workflow in JDBC:                                           *
 * 1. Disabling Auto Commit mode                                                     *
 * 2. Executing the statements                                                       *
 * 3. Committing the transaction                                                     *
 * 4. Handling exceptions (Rollback the transaction)                                 *
 * 5. Enabling Auto Commit mode                                                      *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

import java.sql.*;

public class TransactionsDemo {
    public static void main(String[] args) throws SQLException {
        Connection conn = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhostL3306/primecsitb", "root", "password");

            // Step 1: Begin the transaction
            conn.setAutoCommit(false);

            // Step 2: execute the statements
            Statement st = conn.createStatement();

            String updateQuery1 = "UPDATE students SET name = 'John' WHERE id = 1";
            String updateQuery2 = "UPDATE students SET name = 'Doe' WHERE id = 2";
            st.executeUpdate(updateQuery1);
            st.executeUpdate(updateQuery2);

            // Step 3: Commit the transaction
            conn.commit();
            st.close();
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
            // Handling exceptions (Rollback the transaction)
            conn.rollback();
        } finally {
            // Enabling Auto Commit mode
            if (conn != null) {
                conn.setAutoCommit(true);
                conn.close();
            }
        }
    }
}
