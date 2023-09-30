<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>List from db</title>
    <link rel="stylesheet" href="styles.css">
</head>

<body>

    <table class="styled-table">
        <thead>
            <tr>
                <th>SN</th>
                <th>Name</th>
                <th>Password</th>
                <th>Email</th>
                <th>DOB</th>
                <th>Photo</th>
            </tr>
        </thead>
        <tbody>
            <?php
            include "db.php";
            $sql = "SELECT * FROM login";
            $res = mysqli_query($conn, $sql);

            if (mysqli_num_rows($res) > 0) {
                $sn = 1;
                while ($row = mysqli_fetch_assoc($res)) {
                    ?>
                    <tr>
                        <td>
                            <?php echo $sn; ?>
                        </td>
                        <td>
                            <?php echo $row['uname']; ?>
                        </td>
                        <td>
                            <?php echo $row['password']; ?>
                        </td>
                        <td>
                            <?php echo $row['email']; ?>
                        </td>
                        <td>
                            <?php echo $row['DOB']; ?>
                        </td>
                        <td>
                            <img src="uploads/<?php echo $row['uname']; ?>/<?php echo $row['photo']; ?>" alt="Profile Image"
                                width="100">
                        </td>
                    </tr>
                    <?php
                    $sn++;
                }
            }
            ?>
        </tbody>
    </table>

</body>

</html>