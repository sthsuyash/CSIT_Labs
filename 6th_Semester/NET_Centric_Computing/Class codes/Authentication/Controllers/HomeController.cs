using Authentication.Models;
using Microsoft.AspNetCore.Authentication; // to add authentication
using Microsoft.AspNetCore.Authentication.Cookies; // to add cookie
using Microsoft.AspNetCore.Authorization; // to add authorization
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.Security.Claims; // to add claims -> claims are the authorization details

namespace Authentication.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        // Let's say we need authorization to view Privacy page
        // then we need to add this attribute
        [Authorize]
        public IActionResult Privacy()
        {
            return View();
        }
        [Authorize(Roles = "Student")]
        public IActionResult DashBoard()
        {
            return View();
        }

        // This is the get method for login
        // It will take return url and send it to the view
        [HttpGet]
        public IActionResult Login(string ReturnUrl)
        {
            //take retrun url to view for this use viewbag
            ViewData["returnURL"] = ReturnUrl;
            return View();
        }

        // This is the post method for login
        // It will take username and password and return to the return url
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
                claims.Add(new Claim(ClaimTypes.Role, "Student"));
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

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
