<?php
include "db.php";
$id = $_GET['id'];

$sql = "DELETE FROM web WHERE id=$id";

$res = mysqli_query($conn, $sql);

if (!$res) {
    die("Operation failed" . mysqli_error($conn));
}
header('location:list.php?success=true');
?>