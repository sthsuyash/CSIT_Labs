<?php
session_start();

if (!isset($_SESSION['uname'])) {
    header("location: register.php"); // Redirect to the registration page if not logged in
    exit; // Ensure the script stops here
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <title>Home Page</title>
</head>

<body>
    <main>
        <div class="container">
            <div class="title">Welcome
                <?php echo $_SESSION['uname']; ?>
                </div>
            <div class="button">
                <a href="logout.php">Logout</a>
            </div>
        </div>
    </main>
</body>

</html>