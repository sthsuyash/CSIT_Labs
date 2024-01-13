<?php
include "1_connection.php";

$id = $_GET["id"];

$sql = "DELETE FROM first_semester WHERE id='$id'";
if (mysqli_query($conn, $sql)) {
    echo "Record deleted successfully!";
} else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);
?>