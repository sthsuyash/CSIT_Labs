using Microsoft.AspNetCore.Mvc;
using MVC_CRUD_EFCore___Student_Portal.Models.Entity;

namespace MVC_CRUD_EFCore___Student_Portal.Controllers
{
    public class StudentsController : Controller
    {
        [HttpGet]
        public IActionResult Add()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Add(Student student)
        {
            if (ModelState.IsValid)
            {
                // Add student to database
                return RedirectToAction("Index");
            }
            return View(student);
        }
    }
}
