package org.suyash.unit7.ServletApis;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * GenericServlet Class                                                                    *
 * --------------------------------------------------------------------------------------- *
 * GenericServlet class implements the Servlet, ServletConfig and Serializable interfaces. *
 * It provides the implementation of all the methods of these interfaces,                  *
 * except the service method.                                                              *
 * It can handle any type of request. So it is protocol-independent.                       *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

import jakarta.servlet.*;

import java.io.*;

// We need to register this in web.xml
public class GenericServletDemo extends GenericServlet {
    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        res.setContentType("text/html");
        PrintWriter writer = res.getWriter();
        writer.print("<h1>Hello from Generic Servlet</h1>");
        writer.close();
    }
}
