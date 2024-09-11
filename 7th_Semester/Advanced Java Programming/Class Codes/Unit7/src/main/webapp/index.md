<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
<%--<body>--%>
<%--<h1><%= "Servlet APIs" %>--%>
<%--</h1>--%>
<%--<br/>--%>
<%--<a href="servlet-interface">Servlet Interface</a>--%>
<%--<br/>--%>
<%--<a href="generic-servlet">Generic Servlet Class</a>--%>
<%--<br/>--%>
<%--<a href="httpservlet">HttpServlet Class</a>--%>
<%--</body>--%>

<body>
<div>
    <form method="post" action="FormServlet">
        <label>Name</label>
        <input type="text" name="name"/>
        <br/>

        <label>Password</label>
        <input type="password" name="password"/>
        <br/>

        <label>Repassword</label>
        <input type="password" name="re-pass"/>
        <br/>

        <label>Gender</label>
        <input type="radio" name="gender" value="male"/>Male
        <input type="radio" name="gender" value="female"/>Female
        <br/>

        <label>Course</label>
        <input type="checkbox" name="course" value="java"/>Java
        <input type="checkbox" name="course" value="php"/>PHP
        <input type="checkbox" name="course" value="python"/>Python
        <br/>

        <label>Country</label>
        <select name="country">
            <option value="india">India</option>
            <option value="usa">USA</option>
            <option value="uk">UK</option>
        </select>
        <br/>

        <input type="submit" value="submit"/>
    </form>
</div>
</body>
</html>
