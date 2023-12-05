<?php
session_start();
include "db.php";

$uname = $_POST["uname"];
$password = $_POST["password"];
$hashedPassword = sha1($password); // Assuming passwords are stored as SHA1 hashes in the database

$sql = "SELECT * FROM login WHERE uname='$uname' AND password='$hashedPassword'";
$res = mysqli_query($conn, $sql);

if (mysqli_num_rows($res) > 0) {
    $_SESSION['uname'] = $uname;
    header('location:index.php?login=true');
} else {
    header('location:login.php?login=false');
}
?>