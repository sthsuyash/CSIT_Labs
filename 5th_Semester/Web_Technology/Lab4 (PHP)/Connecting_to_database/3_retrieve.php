<?php
include "1_connection.php";

$sql = "SELECT * FROM first_semester";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    echo "<table border='1'><tr><th>ID</th><th>Name</th><th>Email</th><th>Update</th><th>Delete</th></tr>";
    while ($row = mysqli_fetch_assoc($result)) {
        echo "<tr><td>" . $row["id"] . "</td><td>" . $row["name"] . "</td><td>" . $row["email"] . "</td><td><a href='4_edit.php?id=" . $row["id"] . "'>Update</a></td><td><a href='5_delete.php?id=" . $row["id"] . "'>Delete</a></td></tr>";
    }
    echo "</table>";
} else {
    echo "0 results";
}

mysqli_close($conn);
?>