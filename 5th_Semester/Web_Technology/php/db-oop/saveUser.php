<?php
include "db.php";

class saveUser
{
    public $server;
    public $serverUsername;
    public $serverPassword;
    public $db;
    public $uname, $email, $password, $dob;

    // by default public function
    function __construct()
    {
        $this->server = "localhost";
        $this->serverUsername = "root";
        $this->serverPassword = "password";
        $this->db = "csit";

        $this->uname = $_POST['uname'];
        $this->email = $_POST['email'];
        $this->password = $_POST['password'];
        $this->dob = $_POST['dob'];
    }

    public function dbConnect()
    {
        $conn = mysqli_connect($this->server, $this->serverUsername, $this->serverPassword, $this->db);
        if (!$conn) {
            return false;
        }
        return $conn;
    }

    public function registerUser()
    {
        $conn = $this->dbConnect();
        if ($conn) {
            $sql = "INSERT INTO login(uname,email,password,DOB) VALUES ('$this->uname','$this->email','$this->password','$this->dob')";
            $res = mysqli_query($conn, $sql);
            if (!$res) {
                header('location:register.php?success=false');
            }
            header('location:login.php?success=true'); //location is used to go to another page and ? is used to send message to url
        } else {
            return false;
        }
    }

    public function checkUser()
    {
        $conn = $this->dbConnect();
        if ($conn) {

            $sql = "SELECT * FROM login WHERE uname='$this->uname' AND password='$this->password'";
            $res = mysqli_query($conn, $sql);
            if (mysqli_num_rows($res) > 0) {
                $_SESSION['uname'] = $this->uname;
                return true;
            } else {
                return false;
            }
        }
    }

    public function logout()
    {
        session_start();
        session_unset();
        session_destroy();
        header("location:login.php?logout=true");
    }
}

$uname = $_POST["uname"];
$email = $_POST["email"];
$password = sha1($_POST["password"]);
$dob = $_POST["dob"];

$sql = "INSERT INTO login(uname,email,password,DOB) VALUES ('$uname','$email','$password','$dob')";
$res = mysqli_query($conn, $sql);
if (!$res) {
    header('location:register.php?success=false');
}
header('location:login.php?success=true'); //location is used to go to another page and ? is used to send message to url