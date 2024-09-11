package org.suyash.unit7.ServletApis;

import java.io.*;

import jakarta.servlet.*;
import jakarta.servlet.http.*;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * HttpServlet Class                                                           *
 * --------------------------------------------------------------------------- *
 * It extends the GenericServlet class and implements Serializable interface.  *
 * It provides http specific methods such as:                                  *
 * - doGet,     - doPost,       - doHead,                                      *
 * - doPut,     -doDelete,      - doOptions,                                   *
 * - doTrace.                                                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * - doGet() method is used to handle GET requests.                            *
 * - doPost() method is used to handle POST requests.                          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

public class HttpServletDemo extends HttpServlet {
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        res.setContentType("text/html");
        PrintWriter writer = res.getWriter();
        writer.print("<h1>Hello from HttpServlet</h1>");
        writer.close();
    }
}
