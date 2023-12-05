<?php
include "db.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $uname = $_POST["uname"];
    $email = $_POST["email"];
    $password = sha1($_POST["password"]);
    $dob = $_POST["dob"];

    // Check if the username already exists in the database
    $checkUsernameQuery = "SELECT uname FROM login WHERE uname = '$uname'";
    $checkUsernameResult = mysqli_query($conn, $checkUsernameQuery);

    if (mysqli_num_rows($checkUsernameResult) > 0) {
        // Username already exists, show an error message and redirect
        header('location: register.php?success=false&message=Username already exists');
    } else {
        // Username is unique, proceed with registration
        $imgName = $_FILES["photo"]["name"];
        $imgTmpName = $_FILES["photo"]["tmp_name"];
        $imgSize = $_FILES["photo"]["size"];
        $imgType = $_FILES["photo"]["type"];

        $uploadFolder = "uploads/" . $uname;

        if (!file_exists("uploads/" . $uname)) {
            mkdir("uploads/" . $uname);
        }
        if ($imgType != "image/jpeg" && $imgType != "image/jpg" && $imgType != "image/png") {
            header('location: register.php?success=false&message=Only jpeg, jpg, and png files are allowed.');
        } elseif ($imgSize >= 5000000) {
            header('location: register.php?success=false&message=File size is too large.');
        } else {
            $imgNameUnique = "IMG" . uniqid() . "CSIT" . "." . substr($imgType, 6);
            $imgPath = $uploadFolder . "/" . $imgNameUnique;

            if (move_uploaded_file($imgTmpName, $imgPath)) {
                $sql = "INSERT INTO login(uname,email,password,DOB,photo) VALUES ('$uname','$email','$password','$dob','$imgNameUnique')";
                $res = mysqli_query($conn, $sql);
                if ($res) {
                    // Registration successful, redirect to login page
                    header('location: login.php?success=true');
                } else {
                    // Registration failed, show an error message
                    header('location: register.php?success=false&message=Registration failed');
                }
            } else {
                header('location: register.php?success=false&message=File upload failed');
            }
        }
    }
} else {
    header('location: register.php'); // Redirect if accessed directly without POST data
}
?>