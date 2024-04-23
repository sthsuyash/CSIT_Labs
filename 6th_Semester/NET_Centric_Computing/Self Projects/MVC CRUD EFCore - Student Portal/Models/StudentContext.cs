using Microsoft.EntityFrameworkCore;
using MVC_CRUD_EFCore___Student_Portal.Models.Entity;

namespace MVC_CRUD_EFCore___Student_Portal.Models
{
    public class StudentContext : DbContext
    {
        /* 
         * this constructor, we will be using inside the program.cs file
         * to create a connection to the database
         * StudentContext is the bridge between the database and the application
        */
        public StudentContext(DbContextOptions<StudentContext> options) : base(options) { }

        // use the entity created in the Models/Entity/Student.cs file to create a table in the database
        public DbSet<Student> Students { get; set; } // this will create a table called Students in the database
    }
}
