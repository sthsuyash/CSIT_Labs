using Microsoft.AspNetCore.Mvc;
using Entity_Framework_CRUD.Models;

namespace Entity_Framework_CRUD.Controllers
{
    public class OfficerController : Controller
    {
        // setting up the context class on controller
        // context class is the one that will be used to interact with the database
        private readonly OfficerContext _context;

        // constructor to initialize the context class
        public OfficerController(OfficerContext context)
        {
            _context = context;
        }

        /*
         * Read Officer method
         */
        [HttpGet]
        public IActionResult Index()
        {
            // data to be displayed in index.cshtml
            // data from the database will be converted to list and sent to view
            var officerList = _context.tbl_officer.ToList();
            return View(officerList);
        }

        /*
         * Create Officer method
         * Get and Post methods
         */
        [HttpGet]
        public IActionResult CreateOfficer()
        {
            return View();
        }

        [HttpPost]
        public IActionResult CreateOfficer(Officer o)
        {
            var officer = new Officer()
            {
                Id = Guid.NewGuid(),
                Name = o.Name,
                Gender = o.Gender,
                Department = o.Department,
                Phone = o.Phone,
                Position = o.Position
            };
            _context.tbl_officer.Add(officer);
            _context.SaveChanges();
            return RedirectToAction("Index");
        }

        /*
         * Details Officer method
         * Get method
         */
        [HttpGet]
        public IActionResult GetOfficer(Guid id)
        {
            var officer = _context.tbl_officer.Find(id);
            if (officer == null)
            {
                return RedirectToAction("Index");
            }
            return View(officer);
        }

        /*
         * Update Officer method
         * Get and Post methods
         */

        /*
         * Get method to get the officer details to be updated
         */
        [HttpGet]
        public IActionResult UpdateOfficer(Guid id)
        {
            // check if the id of officer sent from view is matched with the id in the database
            // if matched, the officer details will be sent to the view
            var officer = _context.tbl_officer.FirstOrDefault(x => x.Id == id);
            if (officer == null)
            {
                return RedirectToAction("Index");
            }
            return View(officer);
        }

        /*
         * Post method to update the officer details
         */
        [HttpPost]
        public IActionResult UpdateOfficer(Officer o)
        {
            // check if the officer details are valid
            // then save the changes in database
            var officer = _context.tbl_officer.Find(o.Id);
            if (officer != null)
            {
                officer.Name = o.Name;
                officer.Gender = o.Gender;
                officer.Department = o.Department;
                officer.Phone = o.Phone;
                officer.Position = o.Position;
                _context.SaveChanges();
            }
            return RedirectToAction("Index");
        }

        /*
         * Delete Officer method
         * Get and Post methods
         */

        /*
         * Get method to get the officer details to be deleted
         */
        [HttpGet]
        public IActionResult DeleteOfficer(Guid id)
        {
            // check if the id of officer sent from view is matched with the id in the database
            // if matched, the officer details will be sent to the view
            var officer = _context.tbl_officer.FirstOrDefault(x => x.Id == id);
            if (officer == null)
            {
                return RedirectToAction("Index");
            }
            return View(officer);
        }

        /*
         * Post method to delete the officer details
         */
        [HttpPost]
        public IActionResult DeleteOfficer(Officer o)
        {
            // check if the officer details are valid
            // then delete the officer from the database
            var officer = _context.tbl_officer.Find(o.Id);
            if (officer != null)
            {
                _context.tbl_officer.Remove(officer);
                _context.SaveChanges();
            }
            return RedirectToAction("Index");
        }
    }
}
