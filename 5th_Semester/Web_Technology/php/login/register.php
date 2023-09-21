<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" type="text/css" href="styles.css">
    <title>Student Register Form</title>
</head>

<body>
    <main>
        <div class="container">
            <div class="title">Registration</div>
            <div class="content">
                <form method="POST" action="saveUser.php">
                    <div class="user-details">
                        <div class="input-box">
                            <span class="details">Username</span>
                            <input name="uname" type="text" placeholder="Enter your username" required>
                        </div>
                        <div class="input-box">
                            <span class="details">Email</span>
                            <input name="email" type="email" placeholder="Enter your email" required>
                        </div>
                        <div class="input-box">
                            <span class="details">Password</span>
                            <input name="password" type="password" placeholder="Enter your password" required>
                        </div>
                        <div class="input-box">
                            <span class="details">Date of Birth</span>
                            <input name="dob" type="date" placeholder="Enter your date of birth" required>
                        </div>
                        <div class="input-box">
                            <span class="details">Photo</span>
                            <input name="photo" type="file" placeholder="Place your photo">
                        </div>
                    </div>
                    <div class="button">
                        <input type="submit" value="Register">
                    </div>
                </form>
            </div>
        </div>
    </main>
</body>

</html>