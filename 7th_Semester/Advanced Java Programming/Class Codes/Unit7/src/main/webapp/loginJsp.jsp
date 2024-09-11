<%--
  Created by IntelliJ IDEA.
  User: Suyash Shrestha
  Date: 9/5/2024
  Time: 7:47 AM
  To change this template use File | Settings | File Templates.
--%>

<!-- declarative <%%> -->

<!-- need to remember the syntax -->
<%@page contentType="text/html" pageEncoding="UTF-8" %>
<%@page import="java.sql.*" %>
<html>
<head>
    <title>Login JSP form</title>
</head>
<body>
<%
    for (int i = 0; i <= 10; i++) {
        out.println("Hello world");
    }
%>
<form method="post" action="FormServlet">
    <label>
        Username
        <input type="text" name="username"/>
    </label>
    <br/>

    <label>Password
        <input type="password" name="password"/>
    </label>
    <br/>
</form>
</body>
</html>
