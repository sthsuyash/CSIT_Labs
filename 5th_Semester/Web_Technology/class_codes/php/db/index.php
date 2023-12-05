<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <title>Student form</title>
</head>


<body>

    <main>
        <?php
        if (isset($_GET['success'])) { //get is used to get value from the direted page
            echo "<h2 class='value-inserted'>Value has been inserted</h2>";
        }

        if (isset($_GET['update'])) {
            echo "<h2 class='value-inserted'>Value has been updated</h2>";
        }
        ?>

        <form method="POST" action="save.php">
            <div>
                <label for="name" class="large-label">Name</label>
                <input type="text" name="name" placeholder="Enter your name" />
            </div>
            <div>
                <label for="email" class="large-label">Email</label>
                <input id="email" type="email" placeholder="Enter your email" name="email" />
            </div>
            <div>
                <label for="roll" class="large-label">Roll</label>
                <input type="text" name="roll" placeholder="Enter your roll" />
            </div>
            <div>
                <label for="phone" class="large-label">Phone</label>
                <input type="text" name="phone" placeholder="Enter your phone" />
            </div>
            <div class="button-container">
                <button type="submit">Submit</button>
                <button type="reset">Reset</button>
            </div>
        </form>
    </main>

</body>

</html>