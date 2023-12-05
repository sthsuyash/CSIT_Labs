# Login form

WAP to create a login form:

1. accepts username and password.
2. when the username and password matches, it should redirect to a home page.
3. indicate "Hello $username" where $username is the username entered in the login form.
4. or password is incorrect, it should redirect to the login page with an error message "Invalid username or password".
5. use the concept of sessions to store the username and password.

### Database structure

```db
database: csit
|
|_ table: login
|  |
|  |_ id int PK AI
|  |_ uname varchar 100 unique
|  |_ password varchar 100
|  |_ email varchar 100
|  |_ DOB date
|  |_ photo varchar 100

```

### File structure

```file
login(/)
|
|_ register.php action: saveUser.php
|_ saveUser.php -> $uname, $password, $email, $dob, $photo
|_ login.php action: checkUser.php
|_ checkUser.php -> $uname, $password
|_ home.php
```
