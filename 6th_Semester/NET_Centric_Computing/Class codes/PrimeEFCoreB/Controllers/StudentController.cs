using Microsoft.AspNetCore.Mvc;
using PrimeEFCoreB.Models;

/*
 * Controller is responsible for handling incoming HTTP requests 
 * and sending response to the browser.
 */
namespace PrimeEFCoreB.Controllers
{
    public class StudentController : Controller
    {
        // setting context class on controller
        // context is used to interact with the database
        private readonly StudentContext sc;

        // constructor to initialize context class
        public StudentController(StudentContext sc)
        {
            this.sc = sc;
        }

        // insertStudent method is used to create form in view. it uses get
        [HttpGet]
        public IActionResult InsertStudent()
        {
            return View();
        }

        // accept form data and insert into the database table
        [HttpPost]
        public IActionResult InsertStudent(Student s)
        {
            var student = new Student()
            {
                Id = Guid.NewGuid(), // auto generated
                Name = s.Name,
                Gender = s.Gender,
                Address = s.Address,
                Faculty = s.Faculty
            };
            sc.Students.Add(student);
            sc.SaveChanges();
            return RedirectToAction("Index");
        }

        // displaying data
        public IActionResult Index()
        {
            // data will be displayed in index.cshtml
            // data from table will be converted into list and sent to view
            var viewStd = sc.Students.ToList();
            return View(viewStd);
        }

        // action method to update operation
        [HttpGet]
        public IActionResult Edit(Guid id)
        {
            // check if id sent from view is matched with database record or not
            // if matched, send the data to set method of EditStudent
            var editStudentsData = sc.Students.FirstOrDefault(x => x.Id == id);
            if (editStudentsData != null)
            {
                var editStudent = new Student()
                {
                    Id = editStudentsData.Id,
                    Name = editStudentsData.Name,
                    Gender = editStudentsData.Gender,
                    Address = editStudentsData.Address,
                    Faculty = editStudentsData.Faculty
                };
                return View(editStudent);
            }
            else
            {
                return RedirectToAction("Index");
            }
        }

        [HttpPost]
        public IActionResult Edit(Student student)
        {
            // check if id of editStudent persist or not in database
            // save changes in database
            var editStds = sc.Students.Find(student.Id);
            if (editStds != null)
            {
                editStds.Id = student.Id;
                editStds.Name = student.Name;
                editStds.Address = student.Address;
                editStds.Gender = student.Gender;
                editStds.Faculty = student.Faculty;
                sc.SaveChanges();
            }
            return RedirectToAction("Index");
        }
    }
}
