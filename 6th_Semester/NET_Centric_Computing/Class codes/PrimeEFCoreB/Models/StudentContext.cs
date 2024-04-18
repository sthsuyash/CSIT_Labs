using Microsoft.EntityFrameworkCore;

namespace PrimeEFCoreB.Models
{
    /* 
     * This context class is responsible for creating object of server (sql server) and 
     * Creating table (setting columns of table of database)
     * this class should inherit DbContext class
     */
    public class StudentContext : DbContext
    {
        // creating constructor that will set the object of server
        public StudentContext(DbContextOptions<StudentContext> options) : base(options) { }

        // setting column of table. for this we have to use const of DbSet() class
        public DbSet<Student> Students { get; set; }
        // <Student>:modelclass Students:tableName
        // here Student is model class that will set column of table
        // Student is table name

    }
}
