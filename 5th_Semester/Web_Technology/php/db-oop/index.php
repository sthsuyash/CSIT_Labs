<?php
session_start();
include 'checkUser.php';
include 'saveUser.php';
$saveUser = new saveUser();
$obj = new checkLogin();
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
    <?php
    if ($obj->check()) {
        ?>
        <main>

            <div class="container">
                <div class="title">Welcome
                    <?php echo $_SESSION['uname']; ?>
                </div>

                <div class="button">
                    <a href="logout.php">Logout</a>
                <?php } else {
        header("location: login.php?logout=true");
    } ?>
            </div>
        </div>
    </main>

</body>

</html>