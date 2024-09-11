package org.suyash.unit7.Form;

import jakarta.servlet.http.*;

import java.io.*;
import java.sql.*;


/**
 * To handle form or http request,
 * we need to extend HttpServlet class
 */

public class FormServlet extends HttpServlet {
    public void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
        /* Extract data from parameter, i.e, form */
        String name = req.getParameter("username");
        String password = req.getParameter("password");
        String repassword = req.getParameter("repassword");
        String gender = req.getParameter("gender");

        // for multiple values: use '.getParameterValues()'
        String[] courseArr = req.getParameterValues("course");

        String course = "";
        // convert array to string
        for (String cr : courseArr) {
            course += cr + " ";
        }

        String country = req.getParameter("country");

        /* Response */
        res.setContentType("text/html");
        PrintWriter writer = res.getWriter();

        try {
            /* Sql Connection */
            System.out.println("Loading the driver");
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Driver loaded successfully");

            String URL = "jdbc:mysql://localhost:3306/primecsitb";
            String USER = "root";
            String PASS = "password";

            System.out.println("Connecting to the database");
            Connection conn = DriverManager.getConnection(URL, USER, PASS);
            System.out.println("Connected to the database");

            if (conn != null) {
                System.out.println("Connected to the database");
            }
            else {
                System.out.println("Not connected to the database");
            }

            String insertQuery = "INSERT INTO tbl_reg (username, password, repassword, gender, course, country)" +
                    "VALUES (?, ?, ?, ?, ?, ?)";
            PreparedStatement ps = conn.prepareStatement(insertQuery);
            ps.setString(1, name);
            ps.setString(2, password);
            ps.setString(3, repassword);
            ps.setString(4, gender);
            ps.setString(5, course);
            ps.setString(6, country);

            int rows = ps.executeUpdate();
            if (rows > 0) {
                System.out.println("Data inserted successfully");
            }
            else {
                System.out.println("Data not inserted");
            }
            conn.close();

            /* Display submitted data to the user */
            writer.print("<h1>The submitted data is:</h1>");
            writer.println("<p>Name: " + name + "<br/>");
            writer.println("Password: " + password + "<br/>");
            writer.println("Re-password: " + repassword + "<br/>");
            writer.println("Gender: " + gender + "<br/>");
            writer.println("List of course: " + course + "<br/>");
            writer.println("Country: " + country + "</p>");

            writer.close();
        } catch (SQLException | ClassNotFoundException e) {
            System.out.println("Error message: " + e.getMessage());  // This prints the specific error message
            writer.println("Error message: " + e.getMessage());
        }
    }
}