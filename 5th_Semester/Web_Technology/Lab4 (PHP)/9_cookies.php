<?php
setcookie("user_pref", "dark_mode", time() + 3600, "/");

if (isset($_COOKIE["user_pref"])) {
    echo "User preference: " . $_COOKIE["user_pref"];
}
?>