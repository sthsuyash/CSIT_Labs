using Microsoft.AspNetCore.Mvc;

namespace Client_Side_State_Management.Controllers
{
    public class QueryStringController : Controller
    {
        public IActionResult Index(string name, string age)
        {
            ViewBag.Name = name;
            ViewBag.Age = age;
            return View();
        }
    }
}
