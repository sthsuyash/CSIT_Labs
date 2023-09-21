<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <title>Student edit
        <?php echo $_GET['id'] ?>
    </title>
</head>


<body>

    <main>
        <?php
        include "db.php";
        $id = $_GET['id'];
        $sql = "select * from web where id=$id";
        $res = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($res);
        ?>

        <form method="POST" action="saveupdate.php">
            <div>
                <label for="name" class="large-label">Name</label>
                <input type="text" name="name" value="<?php echo $row['name'] ?>" />
            </div>
            <div>
                <label for="email" class="large-label">Email</label>
                <input id="email" type="email" name="email" value="<?php echo $row['email'] ?>" />
            </div>
            <div>
                <label for="roll" class="large-label">Roll</label>
                <input type="text" name="roll" value="<?php echo $row['roll'] ?>" />
            </div>
            <div>
                <label for="phone" class="large-label">Phone</label>
                <input type="text" name="phone" value="<?php echo $row['phone'] ?>" />
            </div>
            <div class="button-container">
                <button type="submit">Submit Edit</button>
            </div>
        </form>
    </main>

</body>

</html>