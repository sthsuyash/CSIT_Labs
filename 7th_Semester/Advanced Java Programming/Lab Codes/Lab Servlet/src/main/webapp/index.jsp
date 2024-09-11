<%@page contentType="text/html" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Print TU 10 times</title>
</head>
<body>
<%
    for (int i = 0; i < 10; i++) {
        out.println(i + 1 + " Tribhuvan University<br/>");
    }
%>
</body>
</html>