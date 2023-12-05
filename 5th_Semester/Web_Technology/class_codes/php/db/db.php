<?php
$servername = "localhost";
$username = "root";
$password = "password";
$db = "csit";
$conn = mysqli_connect($servername, $username, $password, $db);
if (!$conn) {
    die('Csonnection Refused');
}
?>