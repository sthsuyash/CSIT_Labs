using Microsoft.AspNetCore.Authentication;
using Microsoft.AspNetCore.Authentication.Cookies;
using Microsoft.AspNetCore.Authorization;
using System.Security.Claims;

using Authentication_and_Authorization.Models;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace Authentication_and_Authorization.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult AccessDenied()
        {
            return View();
        }

        /*
         * For all users.
         * no need to be authenticated
         */
        public IActionResult Index()
        {
            return View();
        }

        /*
         * For all authenticated users
         * no matter the role.
         */
        [Authorize]
        public IActionResult Private()
        {
            return View();
        }

        /*
         * For authenticated users with "Admin" and "User" roles.
         */
        //[Authorize (Roles = "Admin, User")]
        //public IActionResult Dashboard()
        //{
        //    return View();
        //}

        // We can implement the same using policy as:
        [Authorize(Policy = "AdminOrUser")]
        public IActionResult Dashboard()
        {
            return View();
        }

        /*
         * For  authenticated users with "User" role.
         */
        [Authorize (Roles = "User")] 
        public IActionResult UserPage()
        {
            return View();
        }

        [Authorize(Roles = "Admin")]
        public IActionResult AdminPage()
        {
            return View();
        }

        /*
         * Loging in the user
         */
        [HttpGet]
        public IActionResult Login(string returnUrl)
        {
            // take the return url and store it in the viewbag
            ViewBag.ReturnUrl = returnUrl;
            return View();
        }

        [HttpPost]
        public IActionResult Login(string username, string password, string returnUrl)
        {
            // user "john" with "admin" role
            if (username == "john" && password == "john")
            {
                List<Claim> claims = new List<Claim>();
                claims.Add(new Claim(ClaimTypes.NameIdentifier, username));
                claims.Add(new Claim(ClaimTypes.Name, username));
                claims.Add(new Claim(ClaimTypes.Role, "Admin"));

                ClaimsIdentity identity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
                ClaimsPrincipal principal = new ClaimsPrincipal(identity);

                HttpContext.SignInAsync(principal);
                return Redirect(returnUrl);
            }

            // user "doe" with "user" role
            if (username == "doe" && password == "doe")
            {
                List<Claim> claims = new List<Claim>();
                claims.Add(new Claim(ClaimTypes.NameIdentifier, username)); // the nameidentifier is the unique identifier for the user
                claims.Add(new Claim(ClaimTypes.Name, username)); // the name claimtypes is the name of the user
                claims.Add(new Claim(ClaimTypes.Role, "User"));

                ClaimsIdentity identity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
                ClaimsPrincipal principal = new ClaimsPrincipal(identity);

                HttpContext.SignInAsync(principal);
                return Redirect(returnUrl);
            }
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
