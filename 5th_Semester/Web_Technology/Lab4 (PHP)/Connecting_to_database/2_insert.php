<?php
include "1_connection.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Validate and sanitize input data
    $name = filter_var($_POST["name"], FILTER_SANITIZE_STRING);
    $email = filter_var($_POST["email"], FILTER_VALIDATE_EMAIL);

    // Check if data is valid
    if ($name && $email) {
        $sql = "INSERT INTO first_semester (name, email) VALUES ('$name', '$email')";
        if (mysqli_query($conn, $sql)) {
            echo "Record inserted successfully!";
        } else {
            echo "Error: " . $sql . "<br>" . mysqli_error($conn);
        }
    } else {
        echo "Invalid data provided.";
    }

    mysqli_close($conn);
}
?>

<html>

<head>
    <title>Form validation and database insertion</title>
</head>

<body>
    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <input type="text" name="name" placeholder="Name">
        <input type="text" name="email" placeholder="Email">
        <input type="submit" value="Submit">
    </form>
</body>

</html>