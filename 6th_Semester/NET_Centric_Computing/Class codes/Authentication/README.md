# Authentication and Authorization in ASP.NET

- Authentication is the process of verifying the identity of a user.
- Authorization is the process of verifying that the user has the necessary permissions to access the resources.
- We need to be Authenticated to access Authorization
- We can have cookies and session authentication.

## Steps to add Authentication and Authorization in ASP.NET Core

### 1. Using Username and Password only (no roles)

1. At first, we need to configure the [`Controllers/HomeController.cs`](Controllers/HomeController.cs) file.

   - In the headers, add the following lines:

     ```c#
     using Microsoft.AspNetCore.Authentication; // to add authentication
     using Microsoft.AspNetCore.Authentication.Cookies; // to add cookie
     using Microsoft.AspNetCore.Authorization; // to add authorization
     using System.Security.Claims; // to add claims -> claims are the authorization details
     ```

     - This will add the necessary libraries to the file. The `Claims` are the authorization details.

   - Let's say that the Privacy page is only accessible to authenticated users. So, in the class `HomeController`, after the `Index` method, let's add the `[Authorize]` attribute to the `Privacy` method.

     ```c#
     [Authorize]
     public IActionResult Privacy()
     {
         return View();
     }
     ```

     - This will make the page accessible only to authenticated users.

   - Now, let's add the login method to the `HomeController` class as the authentication form and the logic to authenticate the user is needed.

     ```c#
     /**
     * This is the get method for login
     * It will take return url and send it to the view
     */
     [HttpGet]
     public IActionResult Login(string ReturnUrl)
     {
         // take return url to view for this use ViewData
         ViewData["returnURL"] = ReturnUrl;
         return View();
     }
     ```

     - This will take the return URL and send it to the view.
     - The return URL is the URL to which the user will be redirected after the login.
     - The view will render the login form and authenticate the user, then redirect the user to the return URL.

   - Now, let's add the post method for the login. This will take the username and password and return to the return URL.

     ```c#
     /**
     * This is the post method for login
     * It will take username and password and return to the return url
     */
     [HttpPost]
     public IActionResult Login(string username, string password, string ReturnUrl)
     {
         if (username == "ram" && password == "ram")
         {
             // add authroization
             // claim: authorization detail
             // identity: which mechanism to be used for authorization:cookie
             // principal: who is authorized
             List<Claim> claims = new List<Claim>();
             claims.Add(new Claim(ClaimTypes.NameIdentifier, username));
             claims.Add(new Claim(ClaimTypes.Name, username));
             // identity->claims
             ClaimsIdentity identity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
             // principal->identity
             ClaimsPrincipal principal = new ClaimsPrincipal(identity);
             // executing->sign in
             HttpContext.SignInAsync(principal); //execute
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

     ```html
     @* create login form and also extract return url *@ @{ ViewData["Title"]
     ="Login"; } @{ string retUrl = ViewData["returnURL"] as string; }
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

The process of adding roles is similar to adding claims. We need to add the roles to the claims and then add the claims to the identity.

1. Let's say that we have a role called `Student`. We can add this role to the claims. In the `Login` method in the `HomeController` class, add the role to the claims.

   ```c#
   if (username == "ram" && password == "ram")
   {
       // add authroization
       // claim: authorization detail
       // identity: which mechanism to be used for authorization:cookie
       // principal: who is authorized
       List<Claim> claims = new List<Claim>();
       claims.Add(new Claim(ClaimTypes.NameIdentifier, username));
       claims.Add(new Claim(ClaimTypes.Name, username));
       /** adding role **/
       claims.Add(new Claim(ClaimTypes.Role, "Student")); // adding role
       // identity->claims
       ClaimsIdentity identity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
       // principal->identity
       ClaimsPrincipal principal = new ClaimsPrincipal(identity);
       // executing->sign in
       HttpContext.SignInAsync(principal); //execute
       return Redirect(ReturnUrl);
   }
   ```

   - Here, we are adding the role `Student` to the claims.

2. Now, let's say that the `Dashboard` page is only accessible to the users with the role `Student`. We can add the `[Authorize(Roles = "Student")]` attribute to the `Dashboard` method in the `HomeController` class.

   ```c#
   [Authorize(Roles = "Student")]
   public IActionResult Dashboard()
   {
       return View();
   }
   ```

   - This will make the page accessible only to the users with the role `Student`.
   - Then, create a `Dashboard.cshtml` file in the [`Views/Home`](Views/Home) folder.
   - This will be the dashboard page that will be accessible only to the users with the role `Student`.
