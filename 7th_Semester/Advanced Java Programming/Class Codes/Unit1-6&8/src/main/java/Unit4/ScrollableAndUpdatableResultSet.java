package Unit4;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * ResultSet Overview                                                                                      *
 * ------------------------------------------------------------------------------------------------------- *
 * Using a `ResultSet` object that is only forward-only, it fetches data sequentially from the first row   *
 * to the last row. It does not support updating the data retrieved. This type of `ResultSet` is used      *
 * for read-only operations, typically with SELECT queries.                                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Using a scrollable and updatable `ResultSet`, data can be fetched in any order (random access) and      *
 * updated as needed. This type allows movement both forwards and backwards and supports modifying the     *
 * data in the `ResultSet`.                                                                                *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */


import java.sql.*;

public class ScrollableAndUpdatableResultSet {
    public static void main(String[] args) {
        final String URL = "jdbc:mysql://localhost:3306/primecsitb";
        final String USER = "root";
        final String PASS = "password";

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(URL, USER, PASS);

            String selectQuery = "SELECT * FROM tbl_reg";

            // creating scrollable and updatable result set
            int scroll = ResultSet.TYPE_SCROLL_SENSITIVE;

            // to create updatable
            int updatable = ResultSet.CONCUR_UPDATABLE;
            // to make readonly, i.e, do not update
            int read = ResultSet.CONCUR_READ_ONLY;

            Statement st = conn.createStatement(scroll, updatable); // to make it updatable
            // for readonly
            // Statement st = conn.createStatement(scroll, read); // to make it readonly

            // execute query
            ResultSet rs = st.executeQuery(selectQuery);

            // fetching data of row 2
            rs.absolute(2);
            // for last
//            rs.last();
//            // for first
//            rs.first();

            System.out.println("********** Fetching 2nd row data **********");
            System.out.println("ID: " + rs.getInt("id"));
            System.out.println("Username: " + rs.getString("username"));
            System.out.println("Password: " + rs.getString("password"));
            System.out.println();

            System.out.println("********** Updating last row data **********");
            rs.last();
            rs.updateString("course", "CSIT updated");
            rs.updateString("username", "Username updated");
            rs.updateRow();
            System.out.println("Data updated successfully");
            System.out.println();

            System.out.println("********** Fetching last row data **********");
            rs.last();
            System.out.println("ID: " + rs.getInt("id"));
            System.out.println("Username: " + rs.getString("username"));
            System.out.println("Password: " + rs.getString("password"));


        } catch (SQLException | ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
