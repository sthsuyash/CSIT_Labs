<?php
include "db.php";

$name = $_POST["name"];
$roll = $_POST["roll"];
$phone = $_POST["phone"];
$email = $_POST["email"];

$sql = "UPDATE web SET name='$name',roll='$roll',phone='$phone',email='$email' WHERE id=$id";
$res = mysqli_query($conn, $sql);
if (!$res) {
    die("Operation failed" . mysqli_error($conn));
}
header('location:form.php?success=true'); //location is used to go to another page and ? is used to send message to url
?>