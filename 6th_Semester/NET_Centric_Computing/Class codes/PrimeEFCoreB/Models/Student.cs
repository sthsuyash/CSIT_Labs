namespace PrimeEFCoreB.Models
{
    /*
     * Entity framework act as bridge to connect with external data source like sql server when using asp.net core or MVC application.
     * It uses object relational mapping to interact with the database.
     * which means all the operation of database are done by create class
     * and object like table, db, tables, column, CRUD operation
     *
     * To use entity framework, two pacakges needs to be downloaded
     * EntityFrameworkCore.SqlServer and EntityFrameworkCore.Tools
     */
    public class Student
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public string Gender { get; set; }
        public string Address { get; set; }
        public string Faculty { get; set; }
    }
}
