<?php
session_start();
include "db.php";

$uname = $_POST["uname"];
$pwd = sha1($_POST["pwd"]);

$sql = "SELECT * FROM login WHERE uname='$uname' AND password='$pwd'";
$res = mysqli_query($conn, $sql);
if (mysqli_num_rows($res) > 0) {
    $_SESSION['uname'] = $uname;
    header('location:home.php?login=true');
} else {
    header('location:login.php?login=false');
}