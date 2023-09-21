<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <title>Login form</title>
</head>

<body>
    <main>
        <?php
        if (isset($_GET['success'])) {
            echo "<h2 class='php-value inserted'>Registration successful. Please login</h2>";
        }
        if (isset($_GET['login']) === false) {
            echo "<h2 class='php-value error'>Username or password is incorrect</h2>";
        }
        ?>
        <div class="container">
            <div class="title">Login</div>
            <div class="content">
                <form method="POST" action="checkUser.php">
                    <div class="user-details">
                        <div class="input-box">
                            <span class="details">Username</span>
                            <input type="text" placeholder="Enter your username" required>
                        </div>
                        <div class="input-box">
                            <span class="details">Password</span>
                            <input type="password" placeholder="Enter your password" required>
                        </div>
                        <div class="button">
                            <input type="submit" value="Login">
                        </div>
                </form>
            </div>
        </div>
    </main>
</body>

</html>