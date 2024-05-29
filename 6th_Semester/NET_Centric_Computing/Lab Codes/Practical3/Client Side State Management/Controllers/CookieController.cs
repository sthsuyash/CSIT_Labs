using Microsoft.AspNetCore.Mvc;

namespace Client_Side_State_Management.Controllers
{
    public class CookieController : Controller
    {
        /*
         * Get value from cookie 
         */
        [HttpGet]
        public IActionResult Index()
        {
            string cookieValue = Request.Cookies["Username"];
            // if cookie is present, set it to viewbag to display it on view
            if (cookieValue != null) ViewBag.Username = cookieValue;
            return View();
        }

        /*
         * Post value to set cookie which gets data from form
         */
        [HttpPost]
        public IActionResult Index(string key, string value, int? expireTime)
        {
            CookieOptions option = new CookieOptions();
            if (expireTime.HasValue)
            {
                option.Expires = DateTime.Now.AddMinutes(expireTime.Value);
            }
            else
            {
                option.Expires = DateTime.Now.AddDays(1);
            }
            Response.Cookies.Append(key, value, option);
            return RedirectToAction("Index");
        }

        /*
         * Delete cookie
         */
        public IActionResult DeleteCookie(string key)
        {
            Response.Cookies.Delete(key);
            return RedirectToAction("Index");
        }
    }
}
