<!-- email validation in php -->

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>form</title>
  </head>
  <body>
    <?php
    // echo"<pre>";
    // print_r($_SERVER);
    // echo"</pre?"
    $namePattern = "/^[a-zA-Z ]*$/";
    $rollPattern = "/^[0-9]*$/";

    if($_SERVER['REQUEST_METHOD'] == "POST"){
        $name = $_POST['name'];
        $roll = $_POST['roll'];
        $email = $_POST['email'];
        $gender = $_POST['gender'];

        if($name == "" || $roll == "" || $email == "" || $gender == ""){
            echo "<p style='color:red;'>Please fill up the form properly</p>";
        }elseif(preg_match($namePattern, $name) == false){
          echo "<p style='color:red;'>Name must contain alphabets and white spaces</p>";
        }elseif(strlen($name)<6){
          echo "<p style='color:red;'>Name must contain at least 6 characters</p>";
        }
        // filtering number in roll field 
        elseif (!filter_input(INPUT_POST, "roll", FILTER_VALIDATE_INT)){
          echo "<p style='color:red;'>Roll must be a number</p>";
        }
        elseif(!filter_input(INPUT_POST, "email", FILTER_VALIDATE_EMAIL)){
          echo "<p style='color:red;'>Invalid email format</p>";
        }
        else{
          echo "<p>Your name is: $name<p/>";
          echo "<p>Your roll is: $roll<p/>";
          echo "<p>Your email is: $email<p/>";
          echo "<p>Your gender is: $gender<p/>";

        }

    }
    ?>
    <form action="/php/index.php" method="POST" enctype="multipart/form-data" autocomplete="off">
      <label>Name: </label>
      <input type="text" name="name" id="name" placeholder="Enter your name" />
      <br/>
      
      <label>Roll: </label>
      <input
      type="text"
      name="roll"
      id="roll"
      placeholder="Enter your roll"
      />
      <br/>
      
      <label>Gender:</label>
      <input type="radio" value="male" name="gender"/>Male
      <input type="radio" value="female" name="gender"/>Female
      <br/>
      
      <label>Email:</label>
      <input type="text" name="email" id="email" />
      <input type="submit" value="Submit" />
      <br/>
    </form>

    <?php
    if(isset($_FILES['image'])){
      $file_name = $_FILES['image']['name'];
      $file_size = $_FILES['image']['size'];
      $file_tmp = $_FILES['image']['tmp_name'];
      $file_type = $_FILES['image']['type'];
      $file_ext = strtolower(end(explode('.', $_FILES['image']['name'])));

      $extensions = array("jpeg", "jpg", "png");

      if(in_array($file_ext, $extensions) === false){
        echo "<p style='color:red;'>This extension file not allowed, Please choose a JPG or PNG file</p>";
      }
      elseif($file_size > 2097152){
        echo "<p style='color:red;'>File size must be 2mb or lower</p>";
      }
      else{
        move_uploaded_file($file_tmp, "images/".$file_name);
        echo "<p style='color:green;'>Image uploaded successfully</p>";
      }
    }

    ?>
    
  </body>
</html>
