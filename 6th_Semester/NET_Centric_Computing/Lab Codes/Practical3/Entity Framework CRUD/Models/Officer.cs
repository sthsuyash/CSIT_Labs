namespace Entity_Framework_CRUD.Models
{
    public class Officer
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public string Gender { get; set; }
        public string Phone { get; set; }
        public string Department { get; set; }
        public string Position { get; set; }
    }
}
