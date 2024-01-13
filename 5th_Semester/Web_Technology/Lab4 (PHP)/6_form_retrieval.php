<html>
<head>
    <title>Q.6 Form retrieval</title>
</head>

<body>
    <form method="post" action="#">
        <input type="text" name="username" placeholder="Username">
        <input type="submit" value="Submit">
    </form>
</body>
</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    echo "Submitted username: $username";
}
?>