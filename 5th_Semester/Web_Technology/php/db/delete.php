<?php
include "db.php";
$id = $_GET['id'];

$sql = "delete from web where id=$id";

$res = mysqli_query($conn, $sql);

if (!$res) {
    die("Operation failed" . mysqli_error($conn));
}
header('location:list.php?success=true');
?>