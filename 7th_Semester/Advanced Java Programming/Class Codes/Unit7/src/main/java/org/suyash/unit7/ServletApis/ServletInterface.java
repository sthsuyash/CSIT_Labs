package org.suyash.unit7.ServletApis;

/**
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Servlets are small Java programs that run on the server side of a web connection. *
 * Just as applets dynamically extend the functionality of a web browser, servlets   *
 * dynamically extend the functionality of the server.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * A servlet is an interface used to handle requests from a web browser (client)     *
 * and responses from the server.                                                    *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * There are three ways to create a servlet:                                         *
 * 1. By implementing the `Servlet` interface.                                       *
 * 2. By using the `GenericServlet` class.                                           *
 * 3. By using the `HttpServlet` class.                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Servlets can throw `ServletException` and `IOException`.                          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

import jakarta.servlet.*;

import java.io.*;

public class ServletInterface implements Servlet {
    ServletConfig config;

    /**
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Lifecycle methods: init(), service(), destroy()               *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Non-lifecycle methods: getServletConfig(), getServletInfo()   *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */

    /**
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * init(): Lifecycle method                                                  *
     * This method is used to initialize the servlet.                            *
     * This method is invoked only when the server is first loaded in the memory *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */
    @Override
    public void init(ServletConfig config) throws ServletException{
        this.config = config;
    }

    /**
     * * * * * * * * * * * * * * * * * * * * * * * * *
     * getServletConfig(): Non-life cycle method     *
     * method is used to handle request from client  *
     * * * * * * * * * * * * * * * * * * * * * * * * *
     */
    @Override
    public ServletConfig getServletConfig(){
        return this.config;
    }

    /**
     * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * service(): Lifecycle method                         *
     * This method is called to process the HTTP request.  *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */
    @Override
    public void service(ServletRequest req, ServletResponse res) throws IOException{
        res.setContentType("text/html");
        PrintWriter writer = res.getWriter();
        writer.print("<h1>Hello from first servlet</h1>");
        writer.close();
    }

    /**
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * getServletInfo(): Non-lifecycle method.                       *
     * This method is used to get information about the servlet.     *
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */
    @Override
    public String getServletInfo(){
        return "This is First Servlet";
    }

    /**
     * * * * * * * * * * * * * * * * * * * * * * * *
     * destroy(): Lifecycle method                 *
     * This method is used to destroy the servlet. *
     * * * * * * * * * * * * * * * * * * * * * * * *
     */
    @Override
    public void destroy(){
        System.out.println("Servlet is destroyed");
    }
}
