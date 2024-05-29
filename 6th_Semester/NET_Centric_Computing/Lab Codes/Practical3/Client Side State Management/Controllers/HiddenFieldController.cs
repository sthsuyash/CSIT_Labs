using Microsoft.AspNetCore.Mvc;

namespace Client_Side_State_Management.Controllers
{
    public class HiddenFieldController : Controller
    {
        // logger
        private readonly ILogger<HiddenFieldController> _logger;
        public HiddenFieldController(ILogger<HiddenFieldController> logger)
        {
            _logger = logger;
        }

        /*
         * Index action method to return the view
         * Id and Name are stored in ViewBag
         */
        public IActionResult Index()
        {
            ViewBag.Id = 1;
            ViewBag.Name = "John";
            return View();
        }

        /*
         * Post action method to receive the form data
         * Id and Name are received from the form
         */
        [HttpPost]
        public IActionResult Index(int Id, string Name)
        {
            ViewBag.Id = Id;
            ViewBag.Name = Name;

            _logger.LogInformation("Id: {Id}, Name: {Name}", Id, Name); // even if the user cannot see id, it is still sent to the server
            
            return View();
        }
    }
}
