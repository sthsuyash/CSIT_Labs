<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>List from db</title>
</head>

<style>
    .styled-table {
        border-collapse: collapse;
        margin: 10rem auto;
        font-size: 0.9em;
        font-family: sans-serif;
        min-width: 400px;
        box-shadow: 0 0 20px rgba(0, 0, 0, 0.15);
    }

    .styled-table th,
    .styled-table td {
        padding: 12px 15px;
    }

    .styled-table tbody tr {
        border-bottom: 1px solid #dddddd;
    }

    .styled-table tbody tr:nth-of-type(even) {
        background-color: #f3f3f3;
    }

    .styled-table tbody tr:last-of-type {
        border-bottom: 2px solid #009879;
    }

    .styled-table tbody tr.active-row {
        font-weight: bold;
        color: #009879;
    }

    .styled-table tbody tr.active-row td {
        border-top: 1px solid #009879;
    }

    .styled-table thead {
        background-color: #009879;
        color: #ffffff;
    }

    a {
        text-decoration: none;
    }

    a:hover {
        color: transparent;
    }

    a:visited {
        color: transparent;
    }
</style>

<body>

    <!-- <?php
    include "db.php";
    $sql = "select * from web";
    $res = mysqli_query($conn, $sql);
    ?> -->
    <!-- // if (mysqli_num_rows($res) > 0) {
    // while($row=mysqli_fetch_assoc($res)){
    // print_r($row);
    // } -->

    <table class="styled-table">
        <thead>
            <tr>
                <th>SN</th>
                <th>Name</th>
                <th>Roll</th>
                <th>Phone</th>
                <th>Email</th>
                <th>Edit</th>
                <th>Delete</th>
            </tr>
        </thead>
        <tbody>
            <?php
            include "db.php";
            $sql = "select * from web";
            $res = mysqli_query($conn, $sql);

            if (mysqli_num_rows($res) > 0) {
                $sn = 1;
                while ($row = mysqli_fetch_assoc($res)) {
                    if ($sn == 1) {
                        ?>
                        <tr class="active-row">
                        <?php } else { ?>
                        <tr>
                        <?php } ?>
                        <td>
                            <?php echo $sn; ?>
                        </td>
                        <td>
                            <?php echo $row['name']; ?>
                        </td>
                        <td>
                            <?php echo $row['roll']; ?>
                        </td>
                        <td>
                            <?php echo $row['phone']; ?>
                        </td>
                        <td>
                            <?php echo $row['email']; ?>
                        </td>
                        <td>
                            <a style="color: blue;" href="edit.php?id=<?php echo $row['id']; ?>">Edit</a>
                        </td>
                        <td>
                            <a style="color: red;" href="delete.php?id=<?php echo $row['id']; ?>">Delete</a>
                        </td>
                    </tr>
                    <?php $sn++;
                }
            } else {
                echo "0 results";
            }
            ?>
        </tbody>
    </table>

</body>

</html>