<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <title>Student Register Form</title>
</head>

<body>
    <main>
        <!-- Display error messages if received -->
        <?php
        if (isset($_GET['success'])) {
            $message = $_GET['message'];
            echo '<p class="error php-value">' . $message . '</p>';
        }

        // Display a success message if received
        if (isset($_GET['success']) && $_GET['success'] == 'true') {
            echo '<p class="inserted php-value">Registration successful. You can now <a href="login.php">login</a>.</p>';
        }
        ?>
        <div class="container">
            <div class="title">Registration</div>
            <div class="content">
                <form method="POST" action="saveUser.php" enctype="multipart/form-data">
                    <div class="user-details">
                        <div class="input-box">
                            <label class="details">Username
                                <input name="uname" type="text" placeholder="Enter your username" required>
                            </label>
                        </div>
                        <div class="input-box">
                            <label class="details">Email
                                <input name="email" type="email" placeholder="Enter your email" required>
                            </label>
                        </div>
                        <div class="input-box">
                            <label class="details">Password
                                <input name="password" type="password" placeholder="Enter your password" required>
                            </label>
                        </div>
                        <div class="input-box">
                            <label class="details">Date of Birth
                                <input name="dob" type="date" placeholder="Enter your date of birth" required>
                            </label>
                        </div>
                        <div class="input-box">
                            <label class="details">Photo
                                <input name="photo" type="file" placeholder="Place your photo">
                            </label>
                        </div>
                    </div>
                    <div class="button">
                        <input type="submit" value="Register">
                    </div>
                </form>
            </div>
        </div>
    </main>
</body>

</html>