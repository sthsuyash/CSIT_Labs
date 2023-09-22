<?php

class checkLogin{
    public $uname;
    public $password;

    public function __construct(){
        $this->uname = $_POST['uname'];
        $this->password = $_POST['password'];
    }

    public function check(){
        include "db.php";
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

session_start();
include "db.php";

$uname = $_POST["uname"];
$pwd = sha1($_POST["pwd"]);

$sql = "SELECT * FROM login WHERE uname='$uname' AND password='$pwd'";
$res = mysqli_query($conn, $sql);

if (mysqli_num_rows($res) > 0) {
    $_SESSION['uname'] = $uname;
    header('location:index.php?login=true');
} else {
    echo "Invalid username or password";
}