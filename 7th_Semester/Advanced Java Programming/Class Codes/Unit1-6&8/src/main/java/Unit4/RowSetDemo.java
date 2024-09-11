package Unit4;

import java.sql.*;
import javax.sql.rowset.*;

/**
 * * * * * * * * * * * * * * * * * * * * * * * *
 * RowSet                                      *
 * ------------------------------------------- *
 * Row set is more flexible than result set,   *
 * as it is default scrollable and updatable.  *
 * It resides in package javax.sql.rowset.*.   *
 * * * * * * * * * * * * * * * * * * * * * * * *
 */

public class RowSetDemo {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");

            // create row set
            JdbcRowSet rowset = RowSetProvider.newFactory().createJdbcRowSet();

            // connecting to database
            String url = "jdbc:mysql://localhost:3306/primecsitb";
            String uname = "root";
            String pass = "password";

            rowset.setUrl(url);
            rowset.setUsername(uname);
            rowset.setPassword(pass);

            // query
            // only select is allowed in row set
            rowset.setCommand("SELECT * FROM tbl_reg");
            rowset.execute();

            // fetching 2nd row data
            rowset.absolute(2);

            System.out.println("********** Fetching 2nd row data **********");
            System.out.println("ID: " + rowset.getInt("id"));
            System.out.println("Username: " + rowset.getString("username"));

            rowset.setString("username", "ram updated");
            rowset.updateRow();

            System.out.println("Data updated successfully");

            // fetching updated data
            rowset.absolute(2);
            System.out.println("********** Fetching updated 2nd row data **********");
            System.out.println("ID: " + rowset.getInt("id"));
            System.out.println("Username: " + rowset.getString("username"));

        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
