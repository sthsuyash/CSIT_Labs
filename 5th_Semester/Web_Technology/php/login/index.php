<?php
session_start();

// Check if the user is logged in
if (isset($_SESSION['uname'])) {
    // User is logged in, display welcome message and profile image
    $username = $_SESSION['uname'];
    include "db.php";
    $sql = "SELECT * FROM login WHERE uname='$username'";
    $res = mysqli_query($conn, $sql);

    if ($res && mysqli_num_rows($res) > 0) {
        $row = mysqli_fetch_assoc($res);
        $profileImage = "uploads/" . $row['uname'] . "/" . $row['photo'];
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
                        <?php echo $username; ?>
                                </div>
                            <!-- Display the profile image below the welcome message -->
                            <img src="<?php echo $profileImage; ?>" alt="Profile Image" width="200">
                            <div class="button">
                                <a href="logout.php">Logout</a>
                            </div>
                        </div>
                    </main>
                </body>

                </html>
        <?php
    } else {
        // User not found in the database, handle this case
        echo "User not found in the database.";
    }
} else {
    // User is not logged in, redirect to the login page
    header("location: login.php");
}
?>