<?php
class UserController
{
    private $userService;

    public function __construct(UserService $userService)
    {
        $this->userService = $userService;
    }

    public function register()
    {
        // Handle registration form submission
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $uname = $_POST["uname"];
            $email = $_POST["email"];
            $password = $_POST["password"];
            $dob = $_POST["dob"];
            $photo = $_FILES["photo"];

            $message = $this->userService->registerUser($uname, $email, $password, $dob, $photo);

            if (strpos($message, 'successful') !== false) {
                header("location: login.php?success=true");
            } else {
                header("location: register.php?success=false&message=" . urlencode($message));
            }
        }
    }

    public function login()
    {
        // Handle login form submission
        if ($_SERVER["REQUEST_METHOD"] == "POST") {
            $uname = $_POST["uname"];
            $password = $_POST["password"];

            $message = $this->userService->loginUser($uname, $password);

            if (strpos($message, 'successful') !== false) {
                header("location: index.php?login=true");
            } else {
                echo "Invalid username or password";
            }
        }
    }

    public function logout()
    {
        $this->userService->logoutUser();
        header("location: login.php?logout=true");
    }
}
?>