<?php
include "db.php";

$name = $_POST["name"];
$roll = $_POST["roll"];
$phone = $_POST["phone"];
$email = $_POST["email"];

$sql = "INSERT INTO web(name,roll,phone,email) VALUES ('$name','$roll','$phone','$email')";
$res = mysqli_query($conn, $sql);
if (!$res) {
    die("Operation failed" . mysqli_error($conn));
}
header('location:index.php?success=true'); //location is used to go to another page and ? is used to send message to url
?>