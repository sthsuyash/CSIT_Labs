using Microsoft.AspNetCore.Mvc;
using MVC_Demonstration.Models; // to access the Student model

/*
 * Controllers are the components that handle user input and responses.
 * It contains group of action methods (such as return values) which handle the user request.
 * 
 * For each controller, there should be a corresponding folder in the Views folder.
 * For each action method, there should be a corresponding view file in the Views folder.
 * 
 * So, example for this StudentController, there should be a Student folder in the Views folder.
 * and for the action methods such as
 */

namespace MVC_Demonstration.Controllers
{
    public class StudentController : Controller
    {
        /*
         * GET: /Student/
         * This action method will be called when the user navigates to the /Student/ URL.
         */
        public IActionResult Index()
        {
            List<Student> students = new List<Student>
            {
                new Student { Id= 1, Name="Suyash Shrestha", Age=22, Address="Kathmandu", Phone="9841234567", Course="CSIT" },
                new Student { Id= 2, Name="Sam Bastola", Age=20, Address="Kathmandu", Phone="9841234562", Course="CSIT" }
            };
            return View(students);
        }

        /*
         * GET: /Student/Details/:id
         * This action method will be called when the user navigates to the /Student/Details/5 URL.
         */
        public IActionResult Details(int id)
        {
            // access the model
            Student student = new Student()
            {
                Id = 1,
                Name = "Suyash Shrestha",
                Age = 22,
                Address = "Kathmandu",
                Phone = "9841234567",
                Course = "CSIT"
            };
            return View(student);
        }

        /*
         * GET: /Student/greetings
         * This action method will be called when the user navigates to the /Student/greetings URL.
         * This action method returns a string. So we don't need a view file for this action method.
         */
        public string Greetings()
        {
            return "Hello, World!";
        }

        /*
         * GET: /Student/:name/:age
         * Here, the action method takes two parameters. The values of these parameters are passed in the URL.
         * They can be given as ?name=John&age=25 in the URL.
         */
        public IActionResult PrintData(string name, int age)
        {
            ViewBag.Name = name;
            ViewBag.Age = age;
            return View();
        }

    }
}
