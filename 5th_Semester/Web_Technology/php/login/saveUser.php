<?php
include "db.php";

$uname = $_POST["uname"];
$email = $_POST["email"];
$password = sha1($_POST["password"]);
$dob = $_POST["dob"];

$sql = "INSERT INTO login(uname,email,password,DOB) VALUES ('$uname','$email','$password','$dob')";
$res = mysqli_query($conn, $sql);
if (!$res) {
    header('location:register.php?success=false');
}
header('location:login.php?success=true'); //location is used to go to another page and ? is used to send message to url