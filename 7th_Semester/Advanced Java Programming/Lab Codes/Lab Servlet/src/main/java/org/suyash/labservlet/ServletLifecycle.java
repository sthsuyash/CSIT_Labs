package org.suyash.labservlet;

import jakarta.servlet.*;

import java.io.*;

public class ServletLifecycle implements Servlet {
    ServletConfig config;

    /**
     * Lifecycle methods:
     * - init(),
     * - service()
     * - destroy()
     */
    @Override
    public void init(ServletConfig config) throws ServletException {
        this.config = config;
    }

    @Override
    public void service(ServletRequest req, ServletResponse res) throws IOException {
        res.setContentType("text/html");
        PrintWriter writer = res.getWriter();
        writer.println("<p>Hello from Servlet</p>");
        writer.close();
    }

    @Override
    public void destroy() {
        System.out.println("Servlet is destroyed");
    }

    /**
     * Non-lifecycle methods:
     * - getServletConfig()
     * - getServletInfo()
     */
    @Override
    public ServletConfig getServletConfig() {
        return this.config;
    }

    @Override
    public String getServletInfo() {
        return "Servlet Lifecycle";
    }
}
