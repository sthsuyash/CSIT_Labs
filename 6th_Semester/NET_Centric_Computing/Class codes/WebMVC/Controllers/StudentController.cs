using Microsoft.AspNetCore.Mvc;
using WebMVC.Models; // to access controllers

/*
 * Controller is used to handle all the incoming http.request.
 * It contains group of actions method (such as return view).
 * which handles the incoming request.
 * for each controller there should be folder in view and
 * for each action method there should be file of view.
 * to access controller from url: tab: domainname/controller/action method
 * if a class is to be a controller then it should inherit superclass controller in C# controller in C# class
 */
namespace WebMVC.Controllers
{
    public class StudentController : Controller
    {
        // action method: such method that returns view
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Contact()
        {
            // accessing model
            Student student = new Student()
            {
                Id = 1,
                Name = "John",
                Gender = "Male",
                Faculty = "CSIT",
                Grade = "A"
            };
            return View(student);
        }

        // normal method
        public string printDetail()
        {
            return "Hello CSIT";
        }

        public string printData(string name, string id)
        {
            return $"person having id {id} is {name}";
        }
    }
}
