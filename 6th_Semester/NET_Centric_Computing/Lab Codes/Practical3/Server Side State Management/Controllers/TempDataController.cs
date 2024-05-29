using Microsoft.AspNetCore.Mvc;

namespace Server_Side_State_Management.Controllers
{
    public class TempDataController : Controller
    {
        public IActionResult Index()
        {
            TempData["Name"] = "Ram Singh";
            return View();
        }

        /*
         * Second and Third actions are used to demonstrate the use of TempData in the next request.
         * The implementation are in View
         */
        public IActionResult Second()
        {
            return View();
        }

        public IActionResult Third()
        {
            return View();
        }
    }
}
