<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    $email = $_POST["email"];
    $phone = $_POST["phone"];

    if (empty($username) || empty($email) || empty($phone)) {
        echo "All fields are required.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "Invalid email address.";
    } elseif (!preg_match("/^(98|97)/", $phone)) {
        echo "Phone number must start with 98 or 97.";
    } else {
        echo "Form data validated successfully!";
    }
}
?>

<html>
<head>
    <title>Q.7 Form validation</title>
</head>

<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <input type="text" name="username" placeholder="Username">
        <input type="text" name="email" placeholder="Email">
        <input type="text" name="phone" placeholder="Phone">
        <input type="submit" value="Submit">
    </form>
</body>
</html>