using Microsoft.AspNetCore.Mvc;

namespace Server_Side_State_Management.Controllers
{
    public class SessionController : Controller
    {
        /*
         * Get method to display the name and email from session
         */
        [HttpGet]
        public IActionResult Index()
        {
            var name = HttpContext.Session.GetString("Name");
            var email = HttpContext.Session.GetString("Email");

            // set the session values to ViewBag
            ViewBag.Name = name;
            ViewBag.Email = email;

            return View();
        }

        /*
         * Post method to store the name and email in session
         */
        [HttpPost]
        public IActionResult Index(string name, string email)
        {
            HttpContext.Session.SetString("Name", name);
            HttpContext.Session.SetString("Email", email);
            return RedirectToAction("Index");
        }

        /*
         * Get method to clear the session
         */
        [HttpGet]
        public IActionResult Clear()
        {
            HttpContext.Session.Clear();
            return RedirectToAction("Index");
        }
    }
}
