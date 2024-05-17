# Authentication and Authorization (Claims, Roles and Policies)

- Authentication is the process of verifying who you are.
- Authorization is the process of verifying what you have access to.
- In the context of web applications, authentication is the process of verifying the identity of a user.
- In .NET, we can have Cookie-based or Session-based authentication.

- Claims are the authorization details.
- Roles are the permissions that the user has. They are the groups of claims.
- Policies are the rules that the user has to follow. They are the groups of roles.

## Steps for Cookie-based Authentication

### 1. Using Claims

Claims are the authorization details. We can add claims to the user and check if the user has the necessary claims to access the resources.

1. At first, we need to configure the [`Controllers/HomeController.cs`](Controllers/HomeController.cs) file.

   - In the headers, add the following lines:

     ```c#
     using Microsoft.AspNetCore.Authentication;
     using Microsoft.AspNetCore.Authentication.Cookies;
     using Microsoft.AspNetCore.Authorization;
     using System.Security.Claims;
     ```

   - Let's say that the Private page is only accessible to authenticated users. So, in the class `HomeController`, after the `Index` method, let's add the `[Authorize]` attribute to the `Private` method.

     ```c#
     [Authorize]
     public IActionResult Private()
     {
         return View();
     }
     ```

     - This will make the page accessible only to authenticated users.

   - Now, let's add the login method to the `HomeController` class as the authentication form and the logic to authenticate the user is needed.

     ```c#
     [HttpGet]
     public IActionResult Login(string ReturnUrl)
     {
         ViewBag.ReturnUrl = ReturnUrl;
         return View();
     }
     ```

     - This will take the return URL and send it to the view.
     - The return URL is the URL to which the user will be redirected after the login.
     - The view will render the login form and authenticate the user, then redirect the user to the return URL.

   - Now, let's add the post method for the login. This will take the username and password and return to the return URL.

     ```c#
     [HttpPost]
     public IActionResult Login(string username, string password, string ReturnUrl)
     {
         if (username == "ram" && password == "ram")
         {
             List<Claim> claims = new List<Claim>();
             claims.Add(new Claim(ClaimTypes.NameIdentifier, username));
             claims.Add(new Claim(ClaimTypes.Name, username));

             ClaimsIdentity identity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
             ClaimsPrincipal principal = new ClaimsPrincipal(identity);

             HttpContext.SignInAsync(principal);
             return Redirect(ReturnUrl);
         }
         return View();
     }
     ```

     In this method:

     - We are checking if the username and password are correct.
     - If they are, we are creating a list of claims. A claim is an authorization detail. We are adding the username, name, and role to the claims.
     - Then, we are creating an identity with the claims and the cookie authentication scheme. An identity is the mechanism to be used for authorization. Here, we are using the cookie.
     - Then, we are creating a principal with the identity. Principal is the one who is authorized.
     - Finally, we are signing in the principal. This will authenticate the user.

   - Now, create a `Login.cshtml` file in the [`Views/Home`](Views/Home) folder for the authentication form.

     ```c#
     @{ ViewData["Title"] ="Login"; }
     @{ string retUrl = ViewBag.ReturnUrl; }
     <form
       method="post"
       action="Login?ReturnUrl=@System.Net.WebUtility.UrlEncode(retUrl)"
     >
       <label>Username</label>
       <input type="text" name="username" /><br />
       <label>Password</label>
       <input type="text" name="password" /><br />
       <input type="submit" name="submit" value="login" />
     </form>
     ```

     - Here, the main thing is the `action="Login?ReturnUrl=@System.Net.WebUtility.UrlEncode(retUrl)"`.
     - This will take the return URL and send it to the `Login` method.
     - The `UrlEncode` method will encode the URL. This is necessary because the URL may contain special characters that may break the URL.
     - The form will take the username and password and submit it to the `Login` method.

2. Then, in [`Program.cs`](Program.cs):

   ```c#
   // to add cookie authentication
   using Microsoft.AspNetCore.Authentication.Cookies;

   // adding authentication through cookie
   // after adding cookie, login path must be /Home/Login
   builder.Services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
   .AddCookie(options => options.LoginPath = "/Home/Login");
   ```

   - This will add the cookie authentication to the application.
   - The login path must be `/Home/Login`.

### 2. Using Roles

The roles are the permissions that the user has. We can add roles to the user and check if the user has the necessary roles to access the resources.

- The process of adding roles is similar to adding claims. We need to add the roles to the claims and then add the claims to the identity.

1. Let's say that we have roles called `Admin` and `User`. We can add this role to the claims. In the `Login` method in the `HomeController` class, add the role to the claims.

   ```c#
   if (username == "ram" && password == "ram")
   {
       List<Claim> claims = new List<Claim>();
       claims.Add(new Claim(ClaimTypes.NameIdentifier, username));
       claims.Add(new Claim(ClaimTypes.Name, username));
       claims.Add(new Claim(ClaimTypes.Role, "Admin")); // adding role

       ClaimsIdentity identity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
       ClaimsPrincipal principal = new ClaimsPrincipal(identity);

       HttpContext.SignInAsync(principal);
       return Redirect(ReturnUrl);
   }
   ```

   ```c#
   if (username == "john" && password == "john"){
    List<Claim> claims = new List<Claim>();
    claims.add(new Claim(ClaimTypes.NameIdentifier, username));
    claims.add(new Claim(ClaimTypes.Name, username));
    claims.add(new Claim(ClaimTypes.Role, "User"));

    ClaimsIdentity identity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
    ClaimsPrincipal principal = new ClaimsPrincipal(identity);

    HttpContext.SignInAsync(principal);
    return Redirect(ReturnUrl);
   }
   ```

   - Here, we are adding the role `Admin` and `User` to the claims.

2. Now, let's say that the `AdminPage` page is only accessible to the users with the role `Admin`. We can add the `[Authorize(Roles = "Admin")]` attribute to the `AdminPage` method in the `HomeController` class.

   ```c#
   [Authorize(Roles = "Admin")]
   public IActionResult AdminPage()
   {
       return View();
   }
   ```

   - This will make the page accessible only to the users with the role `Admin`.
   - Then, create a `AdminPage.cshtml` file in the [`Views/Home`](Views/Home) folder.
   - This will be the AdminPage page that will be accessible only to the users with the role `Admin`.

### 3. Using Policies

1. First, we need to update the `Program.cs` file to include the Policy based Authorization

   ```c#
   builder.Services.AddAuthorization(options =>
   {
     options.AddPolicy("Admin", policy => policy.RequireRole("Admin"));
     options.AddPolicy("User", policy => policy.RequireRole("User"));
   });
   ```

2. Now, we can use the policy in the `HomeController` class. We can add the `[Authorize (Policy = "Admin")]` attribute to the `AdminPage` method.

   ```c#
   [Authorize(Policy = "Admin")]
    public IActionResult AdminPage()
    {
        return View();
    }
   ```

   - This will make the page accessible only to the users with the role `Admin`.
