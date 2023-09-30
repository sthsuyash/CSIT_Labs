<?php

$servername = "localhost";
$username = "root";
$password = "password";
$dbname = "csit";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

class UserService
{
    private $conn;

    public function __construct($conn)
    {
        $this->conn = $conn;
    }

    public function registerUser($uname, $email, $password, $dob, $photo)
    {
        // Check if the username already exists
        $checkUsernameQuery = "SELECT uname FROM login WHERE uname = '$uname'";
        $checkUsernameResult = mysqli_query($this->conn, $checkUsernameQuery);

        if (mysqli_num_rows($checkUsernameResult) > 0) {
            return "Username already exists";
        } else {
            // Username is unique, proceed with registration
            $uploadFolder = "uploads/" . $uname;

            if (!file_exists($uploadFolder)) {
                mkdir($uploadFolder);
            }

            $imgName = $photo["name"];
            $imgTmpName = $photo["tmp_name"];
            $imgSize = $photo["size"];
            $imgType = $photo["type"];

            if ($imgType != "image/jpeg" && $imgType != "image/jpg" && $imgType != "image/png") {
                return "Only jpeg, jpg, and png files are allowed.";
            } elseif ($imgSize >= 5000000) {
                return "File size is too large.";
            } else {
                $imgNameUnique = "IMG" . uniqid() . "CSIT" . "." . substr($imgType, 6);
                $imgPath = $uploadFolder . "/" . $imgNameUnique;

                if (move_uploaded_file($imgTmpName, $imgPath)) {
                    $hashedPassword = sha1($password);
                    $sql = "INSERT INTO login(uname,email,password,DOB,photo) VALUES ('$uname','$email','$hashedPassword','$dob','$imgNameUnique')";
                    $res = mysqli_query($this->conn, $sql);

                    if ($res) {
                        return "Registration successful";
                    } else {
                        return "Registration failed";
                    }
                } else {
                    return "File upload failed";
                }
            }
        }
    }

    public function loginUser($uname, $password)
    {
        $hashedPassword = sha1($password);
        $sql = "SELECT * FROM login WHERE uname='$uname' AND password='$hashedPassword'";
        $res = mysqli_query($this->conn, $sql);

        if (mysqli_num_rows($res) > 0) {
            $_SESSION['uname'] = $uname;
            return "Login successful";
        } else {
            return "Invalid username or password";
        }
    }

    public function logoutUser()
    {
        session_unset();
        session_destroy();
    }
}
?>