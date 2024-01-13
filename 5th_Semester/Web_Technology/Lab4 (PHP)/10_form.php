<!DOCTYPE html>
<html>

<head>
    <title>PHP Form</title>
</head>

<body>
    <h2>PHP Form Example</h2>

    <?php
    // Check if form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Retrieve and display the values
        $name = $_POST["name"];
        $email = $_POST["email"];
        $gender = $_POST["gender"];
        $interests = isset($_POST["interests"]) ? $_POST["interests"] : [];

        echo "<h3>Form Submission Results</h3>";
        echo "Name: $name<br/>";
        echo "Email: $email<br/>";
        echo "Gender: $gender<br/>";

        if (!empty($interests)) {
            echo "Interests: " . implode(", ", $interests) . "<br/>";
        } else {
            echo "No interests selected.<br/>";
        }
    }
    ?>

    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
        <label for="name">Name:</label>
        <input type="text" name="name" id="name" required>

        <br>

        <label for="email">Email:</label>
        <input type="email" name="email" id="email" required>

        <br>

        <label>Gender:</label>
        <input type="radio" name="gender" value="male" id="male">
        <label for="male">Male</label>
        <input type="radio" name="gender" value="female" id="female">
        <label for="female">Female</label>

        <br>

        <label>Interests:</label>
        <input type="checkbox" name="interests[]" value="programming" id="programming">
        <label for="programming">Programming</label>
        <input type="checkbox" name="interests[]" value="reading" id="reading">
        <label for="reading">Reading</label>
        <input type="checkbox" name="interests[]" value="traveling" id="traveling">
        <label for="traveling">Traveling</label>

        <br>

        <input type="submit" value="Submit">
    </form>
</body>

</html>